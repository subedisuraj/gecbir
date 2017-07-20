#pragma once
#include "Workspace.h"
#include<string>
#include <cv.h>
#include <iostream>
#include <opencv\cv.h>
#include <opencv\highgui.h>
#include <vector>
#include <set>


using std::set;
using std::vector;
using std::string;
using cv::Mat;
using std::cout;

class ImageAnalyser
{
private: string ImageFullName;
		 Mat ImageData;

public:
	void Sample(void);
	ImageAnalyser(){};
	IplImage * ResizeImage(IplImage * source);
	ImageAnalyser(string ImagePath);
	bool CompareEqualImages(string OtherImagePath);
	vector<Dir> findDuplicates( string ImagePath); 
	vector<Dir>  findRelatedImages(string ImagePath);
	void ImageAnalyser::DisplayImage();
};

