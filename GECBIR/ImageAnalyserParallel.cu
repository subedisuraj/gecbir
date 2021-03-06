#include "ImageAnalyserParallel.h"
#include <map>
#include "ImageAnalyser.h"
#include "cuda_profiler_api.h"
#define NUM_BANKS 16
#define IMAGE_SIZE 512

namespace GECBIR{



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


	__global__ void image_equal(uchar3 * d_thisImage, uchar3 * d_otherImage, int * d_equalPixels, unsigned int data_size )
	{
		int idx = blockDim.x * blockIdx.x + threadIdx.x;
		if(idx<data_size)
		{
			if(d_thisImage[idx].x ==  d_otherImage[idx].x && d_thisImage[idx].y ==  d_otherImage[idx].y && d_thisImage[idx].z ==  d_otherImage[idx].z  )
				d_equalPixels[idx] = 1;
			else 
				d_equalPixels[idx] = 0;
		}
	}






	double3 findBhattacharyaDistanceParallel(int3 * hist1, int3 * hist2)
	{
		int3 sum1 ={0,0,0};
		int3 sum2 = {0,0,0}; 

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

		mean2.x = sum2.x/(double)HISTOGRAM_BINS_SIZE ;
		mean2.y = sum2.y/(double)HISTOGRAM_BINS_SIZE ;
		mean2.z = sum2.z/(double)HISTOGRAM_BINS_SIZE ;

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

		return score;
	}

	int * ImageAnalyserParallel::ComputeHistogram()
	{

		uchar3 * d_ImageData;
		int3 *d_histoData;


		int3 *histo_data;
		histo_data = new int3[HISTOGRAM_BINS_SIZE];
		for(int i =0; i<HISTOGRAM_BINS_SIZE ; i++)
		{
			histo_data[i].x = 0;
			histo_data[i].y = 0;
			histo_data[i].z = 0;
		}
		cudaError_t cudaStatus;

		cudaStatus = InitializeDevice();
		if(cudaStatus != cudaSuccess)
			return 0;

		d_ImageData = allocatecudaMemoryUchar3(this->PixelData,this->size_of_data,true);
		d_histoData = allocatecudaMemoryInt3(histo_data, HISTOGRAM_BINS_SIZE, true);  

		unsigned int data_size = this->size_of_data;

		int nThreads = HISTOGRAM_BINS_SIZE;
		int nBlocks = (data_size % nThreads == 0)?data_size/ nThreads: data_size/ nThreads+ 1;

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
		//double simi = findBhattacharyaDistance(histo_data, histo_data);

Error:
		cudaFree(d_ImageData);
		cudaFree(d_histoData);

		return 0;
	}



	ImageAnalyserParallel::ImageAnalyserParallel( uchar3 * data, int dataSize)
	{
		PixelData = data;
		size_of_data = dataSize;
	}



	bool ImageAnalyserParallel::CompareImageSimilarity(ImageAnalyserParallel otherImage)
	{
		otherImage.ComputeHistogram();
		double3 similarityScore =  findBhattacharyaDistanceParallel(this->HistoData, otherImage.HistoData);
		if(similarityScore.x < SIMILARITY_TOLERANCE_PARALLEL || similarityScore.x < SIMILARITY_TOLERANCE_PARALLEL || similarityScore.x < SIMILARITY_TOLERANCE_PARALLEL)
			return true;
		return false;
	}



	__global__ void pixel_equal(int* equalPixels, long * prefix_sum, unsigned int data_size)
	{
		__shared__ int XY[HISTOGRAM_BINS_SIZE];

		long idx = threadIdx.x;
		if(idx<data_size)
		{
			XY[threadIdx.x] = equalPixels[idx ];
		}

		for(unsigned int stride =1; stride<=threadIdx.x; stride *=2)
		{
			__syncthreads();
			XY[threadIdx.x] += XY[threadIdx.x-stride];
		}
		__syncthreads();
		prefix_sum[idx] = XY[threadIdx.x];

	}


bool ImageAnalyserParallel::CompareImageEquality(ImageAnalyserParallel otherImage)
	{
		uchar3 * d_thisImage;
		uchar3 * d_otherImage;
		int * d_equalPixels;

		cudaError_t cudaStatus;

		cudaStatus = InitializeDevice();
		if(cudaStatus != cudaSuccess)
			return 0;

		unsigned int data_size = this->size_of_data;

		int * equalPixels;
		equalPixels = new int[data_size];

		d_thisImage = allocatecudaMemoryUchar3(this->PixelData,this->size_of_data,true);
		d_otherImage = allocatecudaMemoryUchar3(otherImage.PixelData,otherImage.size_of_data,true);

		cudaStatus = cudaMalloc((void**)&d_equalPixels, data_size * sizeof(int));
		if (cudaStatus != cudaSuccess) {
			fprintf(stderr, "cudaMalloc failed!");
			return 0;
		}
		int nThreads = HISTOGRAM_BINS_SIZE;
		int nBlocks = (data_size % nThreads == 0)?data_size/ nThreads: data_size/ nThreads+ 1;

		image_equal<<<nBlocks,nThreads>>>(d_thisImage, d_otherImage, d_equalPixels, data_size ); 

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
		cudaStatus = cudaMemcpy(equalPixels, d_equalPixels, data_size * sizeof(int), cudaMemcpyDeviceToHost);
		if (cudaStatus != cudaSuccess) {
			fprintf(stderr, "cudaMemcpy failed!");
			goto Error;
		}

		//int * d_intPixels =  (int*) d_equalPixels;
		long * d_prefixSum;
		long * prefixSum = new long[HISTOGRAM_BINS_SIZE];


		cudaStatus = cudaMalloc((void**)&d_prefixSum, HISTOGRAM_BINS_SIZE * sizeof(long));
		if (cudaStatus != cudaSuccess) {
			fprintf(stderr, "cudaMalloc failed!");
			return 0;
		}

		unsigned int extra_space = HISTOGRAM_BINS_SIZE  / NUM_BANKS;
		const unsigned int shared_mem_size = sizeof(long) *  (HISTOGRAM_BINS_SIZE + extra_space);

		nThreads /= 2;



		pixel_equal<<<1,nThreads, shared_mem_size>>>(d_equalPixels, d_prefixSum, HISTOGRAM_BINS_SIZE ); 
		cudaStatus = cudaMemcpy(prefixSum, d_prefixSum , HISTOGRAM_BINS_SIZE * sizeof(long), cudaMemcpyDeviceToHost);
		if (cudaStatus != cudaSuccess) {
			fprintf(stderr, "cudaMemcpy failed!");
			goto Error;
		}


		if(prefixSum[255]>=240)
		{
			return true;
		}

		return false;


		//long int sumEquals =0;
		//for(int i =0 ;i<data_size ; i++)
		//{
		//	sumEquals += equalPixels[i];
		//}

		//if(data_size - sumEquals <=20)
		//	return true;
		//return false;

Error:
		cudaFree(d_equalPixels);
		cudaFree(d_thisImage);
		cudaFree(d_otherImage);

		return 0;
	}





	vector<vector<ImageInfo > >  ImageAnalyserParallel::CompareImageEqualityOpt(vector<string> selectedImagesList)
	{
	

		cudaProfilerStart();
		vector<vector<ImageInfo > > dupImages = vector<vector<ImageInfo> >();
		
		unsigned int dataSize = IMAGE_SIZE * IMAGE_SIZE;
		std::map<int, int> hashtable;
		uchar3 * d_thisImage;
		uchar3* * d_otherImage;
		int * d_equalPixels;
		d_otherImage = new uchar3*[allImages.size()];


		cudaError_t cudaStatus;
		cudaStatus = InitializeDevice();
		if(cudaStatus != cudaSuccess)
			return dupImages;

		cudaStatus = cudaMalloc((void**)&d_equalPixels, dataSize * sizeof(int));
		if (cudaStatus != cudaSuccess) {
			fprintf(stderr, "cudaMalloc failed!");
			return dupImages;
		}

		for(int i=0; i<selectedImagesList.size(); i++)
		{
			vector<ImageInfo > dupImagesforSelected = vector<ImageInfo>();
			ImageInfo imginf = ImageInfo("",selectedImagesList[i]);
			ImageAnalyser thisImageObj = ImageAnalyser(imginf);
			uchar3 * thisImageData =  (uchar3 *)(thisImageObj.ImageData.data);
			ImageAnalyserParallel thisImage = ImageAnalyserParallel(thisImageData, dataSize);

			

			int * equalPixels;
			equalPixels = new int[dataSize];

			d_thisImage = allocatecudaMemoryUchar3(thisImage.PixelData,dataSize,true);

			for(int i =0; i<allImages.size(); i++)
			{
				ImageAnalyser otherImageobj = ImageAnalyser(allImages[i]);
				uchar3 * otherImageData =  (uchar3 *)(otherImageobj.ImageData.data);
				ImageAnalyserParallel otherImage = ImageAnalyserParallel(otherImageData, dataSize);

				if(thisImageObj.imagefile.ImagePath == otherImageobj.imagefile.ImagePath)
					continue;

				int a = allImages[i].ImageID;
				if(hashtable.find(allImages[i].ImageID) == hashtable.end())
				{
					d_otherImage[allImages[i].ImageID] = allocatecudaMemoryUchar3(otherImage.PixelData,otherImage.size_of_data,true);
					hashtable[allImages[i].ImageID] = allImages[i].ImageID;
				}

				int nThreads = HISTOGRAM_BINS_SIZE;
				int nBlocks = (dataSize % nThreads == 0)?dataSize/ nThreads: dataSize/ nThreads+ 1;

				image_equal<<<nBlocks,nThreads>>>(d_thisImage, d_otherImage[allImages[i].ImageID], d_equalPixels, dataSize ); 


				// Check for any errors launching the kernel
				cudaStatus = cudaGetLastError();
				if (cudaStatus != cudaSuccess) {
					fprintf(stderr, "Kernel launch failed: %s\n", cudaGetErrorString(cudaStatus));
				//	goto Error;
				}

				cudaStatus = cudaDeviceSynchronize();
				if (cudaStatus != cudaSuccess) {
					fprintf(stderr, "cudaDeviceSynchronize returned error code %d after launching addKernel!\n", cudaStatus);
				//	goto Error;
				}

				// Copy output vector from GPU buffer to host memory.
				cudaStatus = cudaMemcpy(equalPixels, d_equalPixels, dataSize * sizeof(int), cudaMemcpyDeviceToHost);
				if (cudaStatus != cudaSuccess) {
					fprintf(stderr, "cudaMemcpy failed!");
				//	goto Error;
				}

				//int * d_intPixels =  (int*) d_equalPixels;
				long * d_prefixSum;
				long * prefixSum = new long[HISTOGRAM_BINS_SIZE];


				cudaStatus = cudaMalloc((void**)&d_prefixSum, HISTOGRAM_BINS_SIZE * sizeof(long));
				if (cudaStatus != cudaSuccess) {
					fprintf(stderr, "cudaMalloc failed!");
					return dupImages;
				}

				unsigned int extra_space = HISTOGRAM_BINS_SIZE  / NUM_BANKS;
				const unsigned int shared_mem_size = sizeof(long) *  (HISTOGRAM_BINS_SIZE + extra_space);

				nThreads /= 2;



				pixel_equal<<<1,nThreads, shared_mem_size>>>(d_equalPixels, d_prefixSum, HISTOGRAM_BINS_SIZE ); 
				cudaStatus = cudaMemcpy(prefixSum, d_prefixSum , HISTOGRAM_BINS_SIZE * sizeof(long), cudaMemcpyDeviceToHost);
				if (cudaStatus != cudaSuccess) {
					fprintf(stderr, "cudaMemcpy failed!");
				//	goto Error;
				}


				if(prefixSum[255]>=240)
				{
					dupImagesforSelected.push_back(allImages[i]);
				}
			}

			dupImages.push_back(dupImagesforSelected);
		}



		//long int sumEquals =0;
		//for(int i =0 ;i<data_size ; i++)
		//{
		//	sumEquals += equalPixels[i];
		//}

		//if(data_size - sumEquals <=20)
		//	return true;
		//return false;

Error:
		cudaFree(d_equalPixels);
		cudaFree(d_thisImage);
		cudaFree(d_otherImage);

		cudaProfilerStop();
		return dupImages;
	}

}