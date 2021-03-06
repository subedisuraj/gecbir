#pragma once
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include "device_functions.h"
#include <stdio.h>
#include <windows.h>
#include <cmath>
#include <vector>
#include <string>
#include "ImageInfo.h"

//#include "ImageAnalyser.h"

#define SIMILARITY_TOLERANCE_PARALLEL 0.35 
#define HISTOGRAM_BINS_SIZE 512


using std::string;
using std::vector;


namespace GECBIR {
class ImageAnalyserParallel
{
public:
	uchar3* PixelData;
	int3 * HistoData;
	unsigned int size_of_data; //No of pixels
	static vector<ImageInfo>  allImages;


public:

	ImageAnalyserParallel(uchar3* data, int dataSize);

	int * ComputeHistogram();
	bool ImageAnalyserParallel::CompareImageSimilarity(ImageAnalyserParallel otherImage);
	bool ImageAnalyserParallel::CompareImageEquality(ImageAnalyserParallel otherImage);
	static vector<vector<ImageInfo > > ImageAnalyserParallel::CompareImageEqualityOpt(vector<string> selectedImagesList);
};

}