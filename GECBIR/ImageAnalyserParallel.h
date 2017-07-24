#pragma once

namespace GECBIR {
class ImageAnalyserParallel
{
public:
	int * PixelData;
	int size_of_data; //No of pixels
	ImageAnalyserParallel(int * data, int dataSize);
	int * ComputeHistogram();
};

}