#pragma once
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include "device_functions.h"
#include <stdio.h>
#include <windows.h>
#include <cmath>
#define HISTOGRAM_BINS_SIZE 256

namespace GECBIR {
class ImageAnalyserParallel
{
public:
	uchar3* PixelData;
	int3 * HistoData;
	unsigned int size_of_data; //No of pixels
	ImageAnalyserParallel(uchar3* data, int dataSize);
	int * ComputeHistogram();
};

}