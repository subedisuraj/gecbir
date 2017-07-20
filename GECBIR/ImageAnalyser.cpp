#include "ImageAnalyser.h"


#define IMAGE_SIZE 256
using namespace cv;
using std::cout;

ImageAnalyser::ImageAnalyser(string ImagePath)
{
	this->ImageFullName = ImagePath;
	IplImage* imgdat  = cvLoadImage(ImagePath.c_str(), CV_LOAD_IMAGE_COLOR);
	IplImage *resizedImage = ResizeImage(imgdat);
	Mat(resizedImage, false);
	this->ImageData = resizedImage;
	//this->ImageData = cvLoadImageM(ImagePath.c_str(),CV_LOAD_IMAGE_COLOR );

}


IplImage * ImageAnalyser::ResizeImage(IplImage * source)
{
	IplImage *destination = cvCreateImage ( cvSize(IMAGE_SIZE, IMAGE_SIZE ), source->depth, source->nChannels);
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
	imshow(this->ImageFullName, this->ImageData);
}


bool ImageAnalyser::CompareEqualImages(string OtherImagePath)
{
	return false;
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