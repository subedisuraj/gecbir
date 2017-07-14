#pragma once

#include <msclr\marshal_cppstd.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <Windows.h>


using std::vector;
using std::string;
using std::cin;
using std::cout;
using namespace System;

class Dir;

class Workspace
{
public:
	string galleryPath;
	vector<Dir> directoryList;

public:
	Workspace(void);
	void Hello(String^ folder);
	~Workspace(void);
	
};


class Dir
{
public:
	string path;
	vector<string> imagePaths;

	Dir(string pathname)
	{
		path = pathname;
	}

};

