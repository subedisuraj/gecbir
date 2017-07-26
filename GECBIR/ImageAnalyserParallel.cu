#include "ImageAnalyserParallel.h"

namespace GECBIR{

cudaError_t addWithCuda(int *c, const int *a, const int *b, unsigned int size);

uchar3 * allocatecudaMemoryUchar3(uchar3 * hostdata, unsigned int dataSize, bool copyMemory)
{
	uchar3 *dev_a = 0;
	cudaError_t cudaStatus;

	cudaStatus = cudaMalloc((void**)&dev_a, dataSize * sizeof(uchar3));
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMalloc failed!");
		return 0;
    }

	if(copyMemory)
	{
	cudaStatus = cudaMemcpy(dev_a, hostdata, dataSize * sizeof(uchar3), cudaMemcpyHostToDevice);
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMemcpy failed!");
        return 0;
    }
	}

    if(cudaStatus==cudaSuccess)
		return dev_a;

	return 0;
}



int3 * allocatecudaMemoryInt3(int3 * hostdata, unsigned int dataSize, bool copyMemory)
{
	int3 *dev_a = 0;
	cudaError_t cudaStatus;

	cudaStatus = cudaMalloc((void**)&dev_a, dataSize * sizeof(int3));
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMalloc failed!");
		return 0;
    }

	if(copyMemory)
	{
	cudaStatus = cudaMemcpy(dev_a, hostdata, dataSize * sizeof(int3), cudaMemcpyHostToDevice);
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



__global__ void histo_kernel(uchar3* d_Imgdata, int3* d_histo , unsigned int data_size)
{
	int idx = blockDim.x * blockIdx.x + threadIdx.x;
	if(idx < data_size)
	{
	atomicAdd(&(d_histo[d_Imgdata[idx].x].x),(int)1);
	atomicAdd(&(d_histo[d_Imgdata[idx].y].y),(int)1);
	atomicAdd(&(d_histo[d_Imgdata[idx].z].z),(int)1);
	}
	__syncthreads();

}



double findBhattacharyaDistance(int3 * hist1, int3 * hist2)
{
	
//	int* data;
//int num;
//int3 x =  {0,0,0};
//thrust::device_vector< int3 > iVec(hist1,hist1+3);
//
//// transfer to device and compute sum
//int3 sum = thrust::reduce(iVec.begin(), iVec.end(), x , thrust::plus<int3>());
//int3 mean = sum/(double)num;
//
//   
//    float h2_R = mean(hist2);
//
//    
//    float score = 0;
//    for( int = 0; i< size(hist1); i++){
//        score += math.sqrt( hist1[i] * hist2[i] );
//	}
//    score = math.sqrt( 1 - ( 1 / math.sqrt(h1_*h2_*8*8) ) * score );
//    return score;



	int3 sum1 ={0,0,0}, sum2 = {0,0,0}; 
	for(int i =0; i<HISTOGRAM_BINS_SIZE; i++)
	{
		sum1.x += hist1[i].x ;
		sum1.y += hist1[i].y;
		sum1.z += hist1[i].z;

		sum2.x += hist2[i].x;
		sum2.y += hist2[i].y;
		sum2.z += hist2[i].z;
	}

	double3 mean1, mean2;

	mean1.x = sum1.x/(double)HISTOGRAM_BINS_SIZE ;
	mean1.y = sum1.y/(double)HISTOGRAM_BINS_SIZE ;
	mean1.z = sum1.z/(double)HISTOGRAM_BINS_SIZE ;

	mean2.x = sum1.x/(double)HISTOGRAM_BINS_SIZE ;
	mean2.y = sum1.y/(double)HISTOGRAM_BINS_SIZE ;
	mean2.z = sum1.z/(double)HISTOGRAM_BINS_SIZE ;

	double3 score = {0.0,0.0,0.0};

	for(int i =0; i<HISTOGRAM_BINS_SIZE; i++)
	{
		score.x += sqrt(hist1[i].x * hist2[i].x);
		score.y += sqrt(hist1[i].y * hist2[i].y);
		score.z += sqrt(hist1[i].z * hist2[i].z);

	}

	score.x = sqrt(1 - ( 1/ sqrt(mean1.x * mean2.x * HISTOGRAM_BINS_SIZE * HISTOGRAM_BINS_SIZE )) * score.x);
	score.y = sqrt(1 - ( 1/ sqrt(mean1.y * mean2.y * HISTOGRAM_BINS_SIZE * HISTOGRAM_BINS_SIZE )) * score.y);
	score.z = sqrt(1 - ( 1/ sqrt(mean1.z * mean2.z * HISTOGRAM_BINS_SIZE * HISTOGRAM_BINS_SIZE )) * score.z);


    return (score.x + score.y + score.z)/3;
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

	uchar3 * d_ImageData;
	int3 *d_histoData;


	int3 *histo_data;
	histo_data = new int3[HISTOGRAM_BINS_SIZE];
	cudaError_t cudaStatus;

	cudaStatus = InitializeDevice();
	if(cudaStatus != cudaSuccess)
		return 0;

	d_ImageData = allocatecudaMemoryUchar3(this->PixelData,this->size_of_data,true);
	d_histoData = allocatecudaMemoryInt3(histo_data, HISTOGRAM_BINS_SIZE * 3, false);  // 3 channels

	unsigned int data_size = this->size_of_data;

	int nThreads = 256;
	int nBlocks = data_size/ nThreads + 1;
	
	histo_kernel<<<nBlocks,nThreads>>>(d_ImageData, d_histoData, data_size ); 


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
	cudaStatus = cudaMemcpy(histo_data, d_histoData, HISTOGRAM_BINS_SIZE * sizeof(int3), cudaMemcpyDeviceToHost);
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMemcpy failed!");
        goto Error;
    }

	this->HistoData = histo_data;
	double simi = findBhattacharyaDistance(histo_data, histo_data);

Error:
	cudaFree(d_ImageData);
	cudaFree(d_histoData);

	return 0;
}






// Helper function for using CUDA to add vectors in parallel.
cudaError_t addWithCuda(int *c, const int *a, const int *b, unsigned int size)
{
return (cudaError_t)0;
}
//    int *dev_a = 0;
//    int *dev_b = 0;
//    int *dev_c = 0;
//    cudaError_t cudaStatus;
//
//    // Choose which GPU to run on, change this on a multi-GPU system.
//	cudaStatus = InitializeDevice();
//	if(cudaStatus != cudaSuccess)
//		return cudaStatus;
//
//	dev_c = allocatecudaMemory(c, size, false);
//	dev_a = allocatecudaMemory(a, size, true);
//	dev_b = allocatecudaMemory(b, size, true);
//
//
//    // Launch a kernel on the GPU with one thread for each element.
//    addKernel<<< 1, size>>>(dev_c, dev_a, dev_b);
//
//    // Check for any errors launching the kernel
//    cudaStatus = cudaGetLastError();
//    if (cudaStatus != cudaSuccess) {
//        fprintf(stderr, "addKernel launch failed: %s\n", cudaGetErrorString(cudaStatus));
//        goto Error;
//    }
//    
//    // cudaDeviceSynchronize waits for the kernel to finish, and returns
//    // any errors encountered during the launch.
//    cudaStatus = cudaDeviceSynchronize();
//    if (cudaStatus != cudaSuccess) {
//        fprintf(stderr, "cudaDeviceSynchronize returned error code %d after launching addKernel!\n", cudaStatus);
//        goto Error;
//    }
//
//    // Copy output vector from GPU buffer to host memory.
//    cudaStatus = cudaMemcpy(c, dev_c, size * sizeof(int), cudaMemcpyDeviceToHost);
//    if (cudaStatus != cudaSuccess) {
//        fprintf(stderr, "cudaMemcpy failed!");
//        goto Error;
//    }
//
//Error:
//    cudaFree(dev_c);
//    cudaFree(dev_a);
//    cudaFree(dev_b);
//    
//    return cudaStatus;
//}








ImageAnalyserParallel::ImageAnalyserParallel( uchar3 * data, int dataSize)
{
	PixelData = data;
	size_of_data = dataSize;
}



}