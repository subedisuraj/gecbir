#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::string;
using std::cin;
using std::cout;

class Workspace
{
public:
	string galleryPath;
	vector<string> imagePaths;

public:
	Workspace(void);
	~Workspace(void);
	int GetFileList(const char *searchkey, std::vector<std::string> &list);
};

