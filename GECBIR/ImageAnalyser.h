#pragma once
#include "Workspace.h"
#include<string>
#include <cv.h>
#include <iostream>
#include <opencv\cv.h>
#include <opencv\highgui.h>
#include <vector>
#include <set>

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
public: string ImageFullName;
		 Mat ImageData;

public:
	void Sample(void);
	ImageAnalyser(){};
	IplImage * ResizeImage(IplImage * source);
	ImageAnalyser(string ImagePath);
	bool CompareImageEquality(string OtherImagePath);
	vector<tuple<string,string> > findDuplicates(); 
	vector<string>  findRelatedImages(string ImagePath);
	void ImageAnalyser::DisplayImage();
};

}