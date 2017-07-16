#include "Workspace.h"



using namespace std;


using namespace System;
using namespace System::IO;


using std::vector;


String^ getManagedString(string unmanagedString);
string getUnmanagedString(String^ managedString);

Workspace::Workspace(void)
{
	galleryPath = "C:\\Users\\ss0193\\Desktop\\MyGallery\\";
	DirectoryInfo^ dir = gcnew DirectoryInfo(getManagedString(galleryPath));
	galleryFolderName = getUnmanagedString( dir->Name);
	getImageLists(dir->Name, dir->FullName);

}



void Workspace::getImageLists(String^ foldername, String^ folderpath)
{
	Dir curFolder = Dir(getUnmanagedString(foldername), getUnmanagedString(folderpath));
	array<String^>^ curfiles = Directory::GetFiles( folderpath, "*\.jpg" );
	for (int j=0; j<curfiles->Length; j++)
	{
		DirectoryInfo^ dir = gcnew DirectoryInfo(curfiles[j]);
		tuple<string, string> fileInfo = tuple<string, string>(getUnmanagedString(dir->Name), getUnmanagedString(dir->FullName));
		curFolder.imagePaths.push_back(fileInfo);
	}
	directoryList.push_back(curFolder);


	array<String^>^ dirs = Directory::GetDirectories( folderpath );
	for (int i=0; i<dirs->Length; i++)
	{
		DirectoryInfo^ dir = gcnew DirectoryInfo(dirs[i]);
		Dir d = Dir(getUnmanagedString(dir->Name),getUnmanagedString(dir->FullName));
		array<String^>^ files = Directory::GetFiles( dirs[i], "*\.jpg" );
		for (int j=0; j<files->Length; j++)
		{
			DirectoryInfo^ dir = gcnew DirectoryInfo(files[j]);
			tuple<string, string> fileInfo = tuple<string, string>(getUnmanagedString(dir->Name), getUnmanagedString(dir->FullName));
			d.imagePaths.push_back(fileInfo);
		}
		directoryList.push_back(d);
	}
}

vector<tuple<string,string> > Workspace::getAllImageLists()
{
	vector<tuple<string,string> > allImagePaths;
	for(int i=0; i< directoryList.size(); i++)
	{
		for(int j =0; j< directoryList[i].imagePaths.size(); j++)
			allImagePaths.push_back(directoryList[i].imagePaths[j]);

	}
	return allImagePaths;
}

Workspace::~Workspace(void)
{
}


String^ getManagedString(string unmanagedString)
{
	return msclr::interop::marshal_as<System::String^>(unmanagedString);
}


string getUnmanagedString(String^ managedString)
{
	return msclr::interop::marshal_as<std::string>(managedString);
}