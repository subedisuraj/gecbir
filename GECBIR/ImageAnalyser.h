#pragma once
#include "Workspace.h"
#include<string>
#include <cv.h>
#include <iostream>
#include <opencv\cv.h>
#include <opencv\highgui.h>
#include <vector>
#include <set>
#include "Workspace.h"

#ifndef RUN_PIXEL_PARALLEL
//#define RUN_PARALLEL
#endif

namespace GECBIR{

using std::set;
using std::vector;
using std::string;
using cv::Mat;
using std::cout;

class ImageAnalyser
{
public: ImageInfo imagefile;
		 Mat ImageData;

public:
	void Sample(void);
	ImageAnalyser(){};
	IplImage * ResizeImage(IplImage * source);
	ImageAnalyser(ImageInfo imginf);
	bool CompareImageEquality(string OtherImagePath);
	bool CompareImageSimilarity(string OtherImagePath);
	vector<ImageInfo> findDuplicates(); 
	vector<ImageInfo>  findSimilarImages();
	void ImageAnalyser::DisplayImage();
};

}