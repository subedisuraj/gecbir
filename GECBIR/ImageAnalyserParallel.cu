#include "ImageAnalyserParallel.h"
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include "device_functions.h"
#include <stdio.h>

namespace GECBIR{
cudaError_t addWithCuda(int *c, const int *a, const int *b, unsigned int size);

int * allocatecudaMemory(const int * hostdata, unsigned int dataSize, bool copyMemory)
{
	int *dev_a = 0;
	cudaError_t cudaStatus;

	cudaStatus = cudaMalloc((void**)&dev_a, dataSize * sizeof(int));
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMalloc failed!");
		return 0;
    }

	if(copyMemory)
	{
	cudaStatus = cudaMemcpy(dev_a, hostdata, dataSize * sizeof(int), cudaMemcpyHostToDevice);
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMemcpy failed!");
        return 0;
    }
	}

    if(cudaStatus==cudaSuccess)
		return dev_a;

	return 0;
}


cudaError_t InitializeDevice()
{
	cudaError_t cudaStatus;
	cudaStatus = cudaSetDevice(0);
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaSetDevice failed!  Do you have a CUDA-capable GPU installed?");
		return cudaStatus;
    }
	return cudaStatus;
}

__global__ void addKernel(int *c, const int *a, const int *b)
{
    int i = threadIdx.x;
    c[i] = a[i] + b[i];
}



__global__ void histo_kernel(int *buffer, int size,  int *histo) 
{
    int i = threadIdx.x + blockIdx.x * blockDim.x;

// stride is total number of threads
    int stride = blockDim.x * gridDim.x;

 // All threads handle blockDim.x * gridDim.x
   // consecutive elements
   while (i < size) {
  /*    int alphabet_position = buffer[i] - 'a';
      if (alphabet_position >= 0 && alpha_position < 26) */		
	//	atomicAdd(&(histo[alphabet_position/4]), 1);
       i += stride;
   }
}



int addcuda()
{
    const int arraySize = 5;
    const int a[arraySize] = { 1, 2, 3, 4, 5 };
    const int b[arraySize] = { 10, 20, 30, 40, 50 };
    int c[arraySize] = { 0 };

    // Add vectors in parallel.
    cudaError_t cudaStatus = addWithCuda(c, a, b, arraySize);
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "addWithCuda failed!");
        return 1;
    }

    printf("{1,2,3,4,5} + {10,20,30,40,50} = {%d,%d,%d,%d,%d}\n",
        c[0], c[1], c[2], c[3], c[4]);

    // cudaDeviceReset must be called before exiting in order for profiling and
    // tracing tools such as Nsight and Visual Profiler to show complete traces.
    cudaStatus = cudaDeviceReset();
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaDeviceReset failed!");
        return 1;
    }

    return 0;
}


int * ImageAnalyserParallel::ComputeHistogram()
{
	int *d_ImageData;
	int *d_histoData;


	int *histo_data;
	cudaError_t cudaStatus;

	cudaStatus = InitializeDevice();
	if(cudaStatus != cudaSuccess)
		return 0;

	d_ImageData = allocatecudaMemory(this->PixelData,this->size_of_data,true);
	d_histoData = allocatecudaMemory(0,100, false);

	histo_kernel<<<1,this->size_of_data>>>(d_ImageData, this->size_of_data, d_histoData); 


    // Check for any errors launching the kernel
    cudaStatus = cudaGetLastError();
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "Kernel launch failed: %s\n", cudaGetErrorString(cudaStatus));
        goto Error;
    }
    
    cudaStatus = cudaDeviceSynchronize();
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaDeviceSynchronize returned error code %d after launching addKernel!\n", cudaStatus);
        goto Error;
    }

    // Copy output vector from GPU buffer to host memory.
	cudaStatus = cudaMemcpy(histo_data, d_histoData, 100 * sizeof(int), cudaMemcpyDeviceToHost);
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMemcpy failed!");
        goto Error;
    }

Error:
	cudaFree(d_ImageData);
	cudaFree(d_histoData);

	return 0;
}






// Helper function for using CUDA to add vectors in parallel.
cudaError_t addWithCuda(int *c, const int *a, const int *b, unsigned int size)
{
    int *dev_a = 0;
    int *dev_b = 0;
    int *dev_c = 0;
    cudaError_t cudaStatus;

    // Choose which GPU to run on, change this on a multi-GPU system.
	cudaStatus = InitializeDevice();
	if(cudaStatus != cudaSuccess)
		return cudaStatus;

	dev_c = allocatecudaMemory(c, size, false);
	dev_a = allocatecudaMemory(a, size, true);
	dev_b = allocatecudaMemory(b, size, true);


    // Launch a kernel on the GPU with one thread for each element.
    addKernel<<< 1, size>>>(dev_c, dev_a, dev_b);

    // Check for any errors launching the kernel
    cudaStatus = cudaGetLastError();
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "addKernel launch failed: %s\n", cudaGetErrorString(cudaStatus));
        goto Error;
    }
    
    // cudaDeviceSynchronize waits for the kernel to finish, and returns
    // any errors encountered during the launch.
    cudaStatus = cudaDeviceSynchronize();
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaDeviceSynchronize returned error code %d after launching addKernel!\n", cudaStatus);
        goto Error;
    }

    // Copy output vector from GPU buffer to host memory.
    cudaStatus = cudaMemcpy(c, dev_c, size * sizeof(int), cudaMemcpyDeviceToHost);
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMemcpy failed!");
        goto Error;
    }

Error:
    cudaFree(dev_c);
    cudaFree(dev_a);
    cudaFree(dev_b);
    
    return cudaStatus;
}








ImageAnalyserParallel::ImageAnalyserParallel(int * data, int dataSize)
{
	PixelData = data;
	size_of_data = dataSize;
}



}