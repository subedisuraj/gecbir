#include "ImageAnalyser.h"
#include <cv.h>
#include <iostream>
#include <opencv\cv.h>
#include <opencv\highgui.h>

using namespace cv;
using std::cout;

ImageAnalyser::ImageAnalyser(void)
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