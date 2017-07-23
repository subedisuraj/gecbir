#include "ImageAnalyser.h"
#include "Imagebox.h"
#include "mainWindow.h"

#define IMAGE_SIZE 64
using namespace cv;
using std::cout;

namespace GECBIR {
ImageAnalyser::ImageAnalyser(ImageInfo imginf)
{
	this->imagefile = imginf;
	IplImage* imgdat  = cvLoadImage(imginf.ImagePath.c_str(), CV_LOAD_IMAGE_COLOR);
	IplImage *resizedImage = ResizeImage(imgdat);
	Mat(resizedImage, false);
	this->ImageData = resizedImage;
	//this->ImageData = cvLoadImageM(ImagePath.c_str(),CV_LOAD_IMAGE_COLOR );

}


IplImage * ImageAnalyser::ResizeImage(IplImage * source)
{
	IplImage *destination = cvCreateImage ( cvSize(IMAGE_SIZE, IMAGE_SIZE ), 8, source->nChannels);
	cvResize(source, destination);
	return destination;
	
}


void ImageAnalyser::DisplayImage()
{
	if(this->ImageData.empty())
	{
		cout << "Error! Image data is empty!" << std::endl;
		return ;
	}
	namedWindow("Picture", CV_WINDOW_NORMAL);
	imshow(this->imagefile.ImageName, this->ImageData);
}


bool ImageAnalyser::CompareImageEquality(string OtherImagePath)
{
#ifndef RUN_PIXEL_PARALLEL
	ImageAnalyser otherImg = ImageAnalyser(ImageInfo("",OtherImagePath));
	int R = this->ImageData.rows;
	int C = this->ImageData.rows;
	int Ch = 3;
	/*int Ch = this->ImageData.channels(;
	int bitDepth = this->ImageData.depth;*/

	for(int i=0; i<R; i++)
	{
		for(int j=0; j<C*Ch; j++)
		{
			if(abs(this->ImageData.at<uchar>(i,j) - otherImg.ImageData.at<uchar>(i,j))>=2)
				return false;
		}
	}
	return true;

#else
	return false; 
#endif

}

bool ImageAnalyser::CompareImageSimilarity(string OtherImagePath)
{
	ImageAnalyser otherImg = ImageAnalyser(ImageInfo("",OtherImagePath));

	return false;
}

vector<ImageInfo > ImageAnalyser::findDuplicates()
{
	vector<ImageInfo > dupImages = vector<ImageInfo>();
	ImageAnalyser selectedImage = ImageAnalyser(this->imagefile);
	vector<ImageInfo > &allImagesinCurGallery =  mainWindow::currentWorkspace->allImagesinGallery;
	for(int j = 0; j<mainWindow::currentWorkspace->allImagesinGallery.size(); j++)
	{
		string otherImageName = allImagesinCurGallery[j].ImageName; 
		string otherImageFullName = allImagesinCurGallery[j].ImagePath;
		if(selectedImage.imagefile.ImagePath != otherImageFullName )
		{
			bool equalImages = selectedImage.CompareImageEquality(otherImageFullName);
			if(equalImages)
			{
				dupImages.push_back(ImageInfo(otherImageName,otherImageFullName));
			}
		}
	}
	return dupImages;
}


vector<ImageInfo>  ImageAnalyser::findSimilarImages(string ImagePath)
{
	vector<ImageInfo > simImages = vector<ImageInfo>();
	ImageAnalyser selectedImage = ImageAnalyser(this->imagefile);
	vector<ImageInfo > &allImagesinCurGallery =  mainWindow::currentWorkspace->allImagesinGallery;
	for(int j = 0; j<mainWindow::currentWorkspace->allImagesinGallery.size(); j++)
	{
		string otherImageName = allImagesinCurGallery[j].ImageName; 
		string otherImageFullName = allImagesinCurGallery[j].ImagePath;
		if(selectedImage.imagefile.ImagePath != otherImageFullName )
		{
			bool similarImages = selectedImage.CompareImageSimilarity(otherImageFullName);
			if(similarImages)
			{
				simImages.push_back(ImageInfo(otherImageName,otherImageFullName));
			}
		}
	}
	return simImages;
}





































void ImageAnalyser::Sample(void)
{
	Mat src1, src2, dst;

	src1 = cvLoadImageM("C:\\Users\\ss0193\\Desktop\\MyGallery\\Europe\\city2.jpg",CV_LOAD_IMAGE_COLOR );

	if (src1.empty())
	{
		cout << "Erro" << std::endl;

	}

	//for(int j=0;j<src1.rows;j++) 
	//{
	//	for (int i=0;i<src1.cols*3;i++)
	//	{

	//		src1.at<uchar>(j,i) = 255; //white
	//		float a = src1.at<uchar>(j,i) ;
	//		int b = 0;
	//	}
	//}


	namedWindow("NewWindow", CV_WINDOW_NORMAL);
	imshow("After", src1);
	waitKey(5000);
}
}