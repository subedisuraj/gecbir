#pragma once
#include<string>
using std::string;


namespace GECBIR{
class ImageInfo
{
public:
	string ImageName;
	string ImagePath;
	int ImageID;
	static int IDGenerator;

	ImageInfo(){};
	ImageInfo(string imgName, string imgPath)
	{
		ImageName = imgName;
		ImagePath = imgPath;
		ImageID = IDGenerator;
		IDGenerator++;
	}
};
}