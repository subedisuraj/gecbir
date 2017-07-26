#pragma once
#include<string>
using std::string;


namespace GECBIR{
class ImageInfo
{
public:
	string ImageName;
	string ImagePath;
	string ImageID;

	ImageInfo(){};
	ImageInfo(string imgName, string imgPath)
	{
		ImageName = imgName;
		ImagePath = imgPath;
	}
};
}