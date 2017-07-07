#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <list>

using std::list;
using std::string;
using std::cin;
using std::cout;


namespace GECBIR{


class ImageBox
{
public:
	string imageFilePath;
	string imageDirectoryPath;
	string imageFileName;

public:
	ImageBox(void);
	~ImageBox(void);
};

}