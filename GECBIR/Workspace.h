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

class Workspace
{
public:
	string galleryPath;
	vector<string> imagePaths;
	vector<string> directoryList;

public:
	Workspace(void);
	void Hello(String^ folder);
	~Workspace(void);
	
};

