#include "ImageAnalyser.h"
#include "Imagebox.h"
#include "mainWindow.h"
#include "Workspace.h"


using namespace cv;
using std::cout;


namespace GECBIR {

	vector<ImageInfo> ImageAnalyserParallel::allImages;
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
		ImageAnalyser otherImg = ImageAnalyser(ImageInfo("",OtherImagePath));
		int R = this->ImageData.rows;
		int C = this->ImageData.rows;
		int Ch = 3;
		/*int Ch = this->ImageData.channels(;
		int bitDepth = this->ImageData.depth;*/

		long count = 0;
		for(int i=0; i<R; i++)
		{
			for(int j=0; j<C*Ch; j++)
			{
				if(abs(this->ImageData.at<uchar>(i,j) - otherImg.ImageData.at<uchar>(i,j))>=2)
					count++;
			}
		}
		if(count >= 10)
			return false;
		return true;
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



	double3 findBhattacharyaDistance(int3 * hist1, int3 * hist2)
	{
		int3 sum1 ={0,0,0};
		int3 sum2 = {0,0,0}; 

		for(int i =0; i<HISTOGRAM_BINS_SIZE; i++)
		{
			sum1.x += hist1[i].x ;
			sum1.y += hist1[i].y;
			sum1.z += hist1[i].z;

			sum2.x += hist2[i].x;
			sum2.y += hist2[i].y;
			sum2.z += hist2[i].z;
		}

		double3 mean1, mean2;

		mean1.x = sum1.x/(double)HISTOGRAM_BINS_SIZE ;
		mean1.y = sum1.y/(double)HISTOGRAM_BINS_SIZE ;
		mean1.z = sum1.z/(double)HISTOGRAM_BINS_SIZE ;

		mean2.x = sum2.x/(double)HISTOGRAM_BINS_SIZE ;
		mean2.y = sum2.y/(double)HISTOGRAM_BINS_SIZE ;
		mean2.z = sum2.z/(double)HISTOGRAM_BINS_SIZE ;

		double3 score = {0.0,0.0,0.0};

		for(int i =0; i<HISTOGRAM_BINS_SIZE; i++)
		{
			score.x += sqrt(hist1[i].x * hist2[i].x);
			score.y += sqrt(hist1[i].y * hist2[i].y);
			score.z += sqrt(hist1[i].z * hist2[i].z);
		}

		score.x = sqrt(1 - ( 1/ sqrt(mean1.x * mean2.x * HISTOGRAM_BINS_SIZE * HISTOGRAM_BINS_SIZE )) * score.x);
		score.y = sqrt(1 - ( 1/ sqrt(mean1.y * mean2.y * HISTOGRAM_BINS_SIZE * HISTOGRAM_BINS_SIZE )) * score.y);
		score.z = sqrt(1 - ( 1/ sqrt(mean1.z * mean2.z * HISTOGRAM_BINS_SIZE * HISTOGRAM_BINS_SIZE )) * score.z);

		return score;
	}

	bool ImageAnalyser::CompareImageSimilarityCustom(string OtherImagePath)
	{

		uchar3 * this_Imagedata = (uchar3*)this->ImageData.data;
		int3 *this_histo_data = new int3[HISTOGRAM_BINS_SIZE];
		for(int i =0; i<HISTOGRAM_BINS_SIZE ; i++)
		{
			this_histo_data[i].x = 0;
			this_histo_data[i].y = 0;
			this_histo_data[i].z = 0;
		}
		for (long i = 0; i < HISTOGRAM_BINS_SIZE*HISTOGRAM_BINS_SIZE; i++)
		{
			this_histo_data[ this_Imagedata[i].x].x += 1;
			this_histo_data[ this_Imagedata[i].y].y += 1;
			this_histo_data[ this_Imagedata[i].z].z += 1;
		}

		ImageAnalyser otherImg = ImageAnalyser(ImageInfo("",OtherImagePath));
		uchar3 * other_Imagedata = (uchar3*)otherImg.ImageData.data;
		int3 * other_histo_data = new int3[HISTOGRAM_BINS_SIZE];
		for(int i =0; i<HISTOGRAM_BINS_SIZE ; i++)
		{
			other_histo_data[i].x = 0;
			other_histo_data[i].y = 0;
			other_histo_data[i].z = 0;
		}
		for (long i = 0; i < HISTOGRAM_BINS_SIZE*HISTOGRAM_BINS_SIZE; i++)
		{
			other_histo_data[  other_Imagedata[i].x].x += 1;
			other_histo_data[  other_Imagedata[i].y].y += 1;
			other_histo_data[  other_Imagedata[i].z].z += 1;
		}


		double3 similarityScore =  findBhattacharyaDistance(this_histo_data, other_histo_data);
		if(similarityScore.x < SIMILARITY_TOLERANCE_PARALLEL || similarityScore.x < SIMILARITY_TOLERANCE_PARALLEL || similarityScore.x < SIMILARITY_TOLERANCE_PARALLEL)
			return true;
		return false;
	}



	vector<ImageInfo > ImageAnalyser::findDuplicates()
	{
		vector<ImageInfo > dupImages = vector<ImageInfo>();
		ImageAnalyser selectedImage = ImageAnalyser(this->imagefile);
		vector<ImageInfo >& allImagesinCurGallery =  mainWindow::currentWorkspace->allImagesinGallery;
//
//#ifdef RUN_PARALLEL_OPT
//				for(int j = 0; j<mainWindow::currentWorkspace->allImagesinGallery.size(); j++)
//		{
//			string otherImageName = allImagesinCurGallery[j].ImageName; 
//			string otherImageFullName = allImagesinCurGallery[j].ImagePath;
//			if(selectedImage.imagefile.ImagePath != otherImageFullName )
//			{
//				bool equalImages = false;
//				unsigned int dataSize = IMAGE_SIZE * IMAGE_SIZE;
//				uchar3 * imageData =  (uchar3 *)(selectedImage.ImageData.data);
//				ImageAnalyserParallel selectedImageParallel = ImageAnalyserParallel(imageData, dataSize);
//
//				ImageAnalyser otherImage = ImageAnalyser(ImageInfo("",otherImageFullName));
//				uchar3 * otherImageData =  (uchar3 *)(otherImage.ImageData.data);
//				ImageAnalyserParallel otherImageParallel = ImageAnalyserParallel(otherImageData, dataSize);
//				equalImages = selectedImageParallel.CompareImageEquality(otherImageParallel);
//				if(equalImages)
//				{
//					dupImages.push_back(ImageInfo(otherImageName,otherImageFullName));
//				}
//			}
//		}
//
//
//
//#endif
//
//
//
//
//
//
//#ifdef RUN_PARALLEL
//			
//	     ImageAnalyserParallel::allImages = allImagesinCurGallery;
//		 unsigned int dataSize = IMAGE_SIZE * IMAGE_SIZE;
//		 uchar3 * imageData =  (uchar3 *)(selectedImage.ImageData.data);
//		 ImageAnalyserParallel selectedImageParallel = ImageAnalyserParallel(imageData, dataSize);
//		// bool a = selectedImageParallel.CompareImageEqualityOpt();
//
//		//for(int j = 0; j<mainWindow::currentWorkspace->allImagesinGallery.size(); j++)
//		//{
//		//	string otherImageName = allImagesinCurGallery[j].ImageName; 
//		//	string otherImageFullName = allImagesinCurGallery[j].ImagePath;
//		//	if(selectedImage.imagefile.ImagePath != otherImageFullName )
//		//	{
//		//		bool equalImages = false;
//		//		unsigned int dataSize = IMAGE_SIZE * IMAGE_SIZE;
//		//		uchar3 * imageData =  (uchar3 *)(selectedImage.ImageData.data);
//		//		ImageAnalyserParallel selectedImageParallel = ImageAnalyserParallel(imageData, dataSize);
//
//		//		ImageAnalyser otherImage = ImageAnalyser(ImageInfo("",otherImageFullName));
//		//		uchar3 * otherImageData =  (uchar3 *)(otherImage.ImageData.data);
//		//		ImageAnalyserParallel otherImageParallel = ImageAnalyserParallel(otherImageData, dataSize);
//		//		equalImages = selectedImageParallel.CompareImageEquality(otherImageParallel);
//		//		if(equalImages)
//		//		{
//		//			dupImages.push_back(ImageInfo(otherImageName,otherImageFullName));
//		//		}
//		//	}
//		//}
//#else
		for(int j = 0; j<mainWindow::currentWorkspace->allImagesinGallery.size(); j++)
		{
			string otherImageName = allImagesinCurGallery[j].ImageName; 
			string otherImageFullName = allImagesinCurGallery[j].ImagePath;
			if(selectedImage.imagefile.ImagePath != otherImageFullName )
			{
				bool equalImages = false;
				equalImages = selectedImage.CompareImageEquality(otherImageFullName);



				if(equalImages)
				{
					dupImages.push_back(ImageInfo(otherImageName,otherImageFullName));
				}
			}
		}
//#endif
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
				bool similarImages = false;

#ifdef RUN_PARALLEL
				unsigned int dataSize = IMAGE_SIZE * IMAGE_SIZE;
				uchar3 * imageData =  (uchar3 *)(selectedImage.ImageData.data);
				ImageAnalyserParallel selectedImageParallel = ImageAnalyserParallel(imageData, dataSize);
				selectedImageParallel.ComputeHistogram();

				ImageAnalyser otherImage = ImageAnalyser(ImageInfo("",otherImageFullName));
				uchar3 * otherImageData =  (uchar3 *)(otherImage.ImageData.data);
				ImageAnalyserParallel otherImageParallel = ImageAnalyserParallel(otherImageData, dataSize);
				similarImages = selectedImageParallel.CompareImageSimilarity(otherImageParallel);
#else

				similarImages = selectedImage.CompareImageSimilarityCustom(otherImageFullName);
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