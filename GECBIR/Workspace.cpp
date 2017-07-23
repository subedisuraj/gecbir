#include "Workspace.h"
#include "Settings.h"


namespace GECBIR{
using namespace std;


using namespace System;
using namespace System::IO;


using std::vector;


String^ getManagedString(string unmanagedString);
string getUnmanagedString(String^ managedString);

Workspace::Workspace(void)
{
	
	InitializeGalleryPath();
	DirectoryInfo^ dir = gcnew DirectoryInfo(getManagedString(galleryPath));
	galleryFolderName = getUnmanagedString( dir->Name);
	getImageListsinGallery(dir->Name, dir->FullName);
	allImagesinGallery = getAllImageLists();

}

void Workspace::InitializeGalleryPath()
{
	galleryPath = getUnmanagedString(Settings::galleryLocation);
	if(galleryPath=="")
		galleryPath = "C:\\Users\\ss0193\\Desktop\\MyGallery\\";
}

Dir Workspace::getImageListsInDir(String^ foldername, String^ folderpath)
{
	Dir curFolder = Dir(getUnmanagedString(foldername), getUnmanagedString(folderpath));
	array<String^>^ ImageFileslist = Directory::GetFiles( folderpath, "*\.jpg" );
	for (int j=0; j<ImageFileslist->Length; j++)
	{
		DirectoryInfo^ imageFile = gcnew DirectoryInfo(ImageFileslist[j]);
		ImageInfo imagefileInfo = ImageInfo(getUnmanagedString(imageFile->Name), getUnmanagedString(imageFile->FullName));
		curFolder.imagePaths.push_back(imagefileInfo);
	}
	return curFolder;
}

void Workspace::getImageListsinGallery(String^ foldername, String^ folderpath)
{
	//get Imagelist inside current folder
	Dir rootFolderImages = getImageListsInDir( foldername, folderpath);
	directoryList.push_back(rootFolderImages);

	//get imagelist of subfolders
	array<String^>^ dirs = Directory::GetDirectories( folderpath );
	for (int i=0; i<dirs->Length; i++)
	{
		DirectoryInfo^ dir = gcnew DirectoryInfo(dirs[i]);
		Dir subFolderIMages = getImageListsInDir(dir->Name,dir->FullName);
		directoryList.push_back(subFolderIMages);
	}
}

vector<ImageInfo > Workspace::getAllImageLists()
{
	vector<ImageInfo > allImagePaths;
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
}