#pragma once

#include<string>
#include <cv.h>
#include <iostream>
#include <opencv\cv.h>
#include <opencv\highgui.h>
#include <vector>
#include <set>
#include "ImageAnalyserParallel.h"


#define RUN_PARALLEL
#define IMAGE_SIZE 512
#define SIMILARITY_TOLERANCE 0.85 //value between 0 and 1 0= most similar



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
	bool ImageAnalyser::CompareImageSimilarityCustom(string OtherImagePath);
	bool CompareImageEquality(string OtherImagePath);
	bool CompareImageSimilarity(string OtherImagePath);
	vector<ImageInfo> findDuplicates(); 
	vector<ImageInfo>  findSimilarImages();
	void ImageAnalyser::DisplayImage();
};

}