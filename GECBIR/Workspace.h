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

class Workspace
{
public:
	string galleryPath;
	string galleryFolderName;
	vector<Dir> directoryList;
	

public:
	Workspace(void);
	~Workspace(void);
	void getImageLists(String^ foldername, String^ folderpath);
	vector<tuple<string,string> > getAllImageLists();  //Name , Path
	
	
};


class Dir
{
public:
	string name;
	string path;
	vector<tuple<string,string> > imagePaths; // Name, Path


	Dir(){};
	Dir(string dirname, string pathname)
	{
		name = dirname;
		path = pathname;
	}

};

