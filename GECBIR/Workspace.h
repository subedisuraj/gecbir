#pragma once

#include <msclr\marshal_cppstd.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <Windows.h>


using std::vector;
using std::tuple;
using std::string;
using std::cin;
using std::cout;
using namespace System;


String^ getManagedString(string unmanagedString);
string getUnmanagedString(String^ managedString);

class Dir;
class ImageInfo;
class Workspace
{
public:
	string galleryPath;
	string galleryFolderName;
	vector<Dir> directoryList;
	

public:
	Workspace(void);
	~Workspace(void);
	void getImageListsinGallery(String^ foldername, String^ folderpath);
	vector<ImageInfo > getAllImageLists();  //Name , Path
	Dir Workspace::getImageListsInDir(String^ foldername, String^ folderpath);
	
};


class Dir
{
public:
	string name;
	string path;
	vector<ImageInfo> imagePaths;
	//vector<tuple<string,string> > imagePaths; // Name, Path


	Dir(){};
	Dir(string dirname, string pathname)
	{
		name = dirname;
		path = pathname;
	}

};

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

