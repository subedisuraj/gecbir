#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <list>

using std::list;
using std::string;
using std::cin;
using std::cout;





class ImageFile
{
public:
	string imageFilePath;
	string imageDirectoryPath;
	string imageFileName;

public:
	ImageFile(void);
	~ImageFile(void);
};

