#include "ImageAnalyser.h"
#include "Imagebox.h"
#include "mainWindow.h"

//#define RUN_PARALLEL
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
#ifndef RUN_PARALLEL
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
	Mat hsv_this, hsv_other;
	ImageAnalyser otherImg = ImageAnalyser(ImageInfo("",OtherImagePath));


	cvtColor( this->ImageData, hsv_this, COLOR_BGR2HSV );
    cvtColor( otherImg.ImageData, hsv_other, COLOR_BGR2HSV );

	//hsv_this = this->ImageData;
	//hsv_other = otherImg.ImageData;


	//TODO:: data of the image file in hsv format can be obtained and transferred using the pointer
	 Mat C = (Mat_<uchar>(3,3) << 1, 2, 3, 4, 5, 5, 6, 7, 0);
	// uchar *Cdata = C.data;
	 uchar *Cdata = hsv_this.data;


	int channels[] = { 0, 1, 2 };
	MatND hist_this, hist_other;

	/// Using 50 bins for hue and 60 for saturation
    int h_bins = 50; int s_bins = 60;
    int histSize[] = { h_bins, s_bins };

    // hue varies from 0 to 179, saturation from 0 to 255
    float h_ranges[] = { 0, 180 };
    float s_ranges[] = { 0, 256 };

	const float* ranges[] = { h_ranges, s_ranges };

	calcHist( &hsv_this, 1, channels, Mat(), hist_this, 2, histSize, ranges, true, false );
    normalize( hist_this, hist_this, 0, 1, NORM_MINMAX, -1, Mat() );

	calcHist( &hsv_other, 1, channels, Mat(), hist_other, 2, histSize, ranges, true, false );
    normalize( hist_other, hist_other, 0, 1, NORM_MINMAX, -1, Mat() );

	double similarityMetrics = compareHist( hist_this, hist_other, 3 );


	if(similarityMetrics < SIMILARITY_TOLERANCE)
		return true;

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

#ifdef RUN_PARALLEL
			unsigned int dataSize = IMAGE_SIZE * IMAGE_SIZE;
			uchar3 * imageData =  (uchar3 *)(selectedImage.ImageData.data);
			ImageAnalyserParallel selectedImageParallel = ImageAnalyserParallel(imageData, dataSize);

			ImageAnalyser otherImage = ImageAnalyser(ImageInfo("",otherImageFullName));
			uchar3 * otherImageData =  (uchar3 *)(otherImage.ImageData.data);
			ImageAnalyserParallel otherImageParallel = ImageAnalyserParallel(otherImageData, dataSize);
			bool equalImages = selectedImageParallel.CompareImageEquality(otherImageParallel);

#else
			bool equalImages = selectedImage.CompareImageEquality(otherImageFullName);

#endif
			
			if(equalImages)
			{
				dupImages.push_back(ImageInfo(otherImageName,otherImageFullName));
			}
		}
	}
	return dupImages;
}


vector<ImageInfo>  ImageAnalyser::findSimilarImages()
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

#ifdef RUN_PARALLEL
			unsigned int dataSize = IMAGE_SIZE * IMAGE_SIZE;
			uchar3 * imageData =  (uchar3 *)(selectedImage.ImageData.data);
			ImageAnalyserParallel selectedImageParallel = ImageAnalyserParallel(imageData, dataSize);
			selectedImageParallel.ComputeHistogram();

			ImageAnalyser otherImage = ImageAnalyser(ImageInfo("",otherImageFullName));
			uchar3 * otherImageData =  (uchar3 *)(otherImage.ImageData.data);
			ImageAnalyserParallel otherImageParallel = ImageAnalyserParallel(otherImageData, dataSize);
			bool similarImages = selectedImageParallel.CompareImageSimilarity(otherImageParallel);
#else

			bool similarImages = selectedImage.CompareImageSimilarity(otherImageFullName);

#endif
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