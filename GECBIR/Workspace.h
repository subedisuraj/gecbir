#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <list>

using std::list;
using std::string;
using std::cin;
using std::cout;

class Workspace
{
public:
	string galleryPath;
	list<string> imagePaths;

public:
	Workspace(void);
	~Workspace(void);
};

