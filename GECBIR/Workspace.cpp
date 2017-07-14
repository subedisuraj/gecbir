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
	//imagePaths.push_back("C:\\Users\\ss0193\\Desktop\\MyGallery\\Europe\\city1.jpg");
	//imagePaths.push_back("C:\\Users\\ss0193\\Desktop\\MyGallery\\Europe\\city2 - Copy.jpg");
	//imagePaths.push_back("C:\\Users\\ss0193\\Desktop\\MyGallery\\Europe\\city2.jpg");
	//imagePaths.push_back("C:\\Users\\ss0193\\Desktop\\MyGallery\\Europe\\city3.jpg");
	//imagePaths.push_back("C:\\Users\\ss0193\\Desktop\\MyGallery\\Europe\\city1.jpg");
	//imagePaths.push_back("C:\\Users\\ss0193\\Desktop\\MyGallery\\Europe\\city2 - Copy.jpg");
	//imagePaths.push_back("C:\\Users\\ss0193\\Desktop\\MyGallery\\Europe\\city2.jpg");
	//imagePaths.push_back("C:\\Users\\ss0193\\Desktop\\MyGallery\\Europe\\city3.jpg");
	//imagePaths.push_back("C:\\Users\\ss0193\\Desktop\\MyGallery\\Europe\\city1.jpg");
	//imagePaths.push_back("C:\\Users\\ss0193\\Desktop\\MyGallery\\Europe\\city2 - Copy.jpg");
	//imagePaths.push_back("C:\\Users\\ss0193\\Desktop\\MyGallery\\Europe\\city2.jpg");
	//imagePaths.push_back("C:\\Users\\ss0193\\Desktop\\MyGallery\\Europe\\city3.jpg");
	//imagePaths.push_back("C:\\Users\\ss0193\\Desktop\\MyGallery\\Europe\\city1.jpg");
	//imagePaths.push_back("C:\\Users\\ss0193\\Desktop\\MyGallery\\Europe\\city2 - Copy.jpg");
	//imagePaths.push_back("C:\\Users\\ss0193\\Desktop\\MyGallery\\Europe\\city2.jpg");
	//imagePaths.push_back("C:\\Users\\ss0193\\Desktop\\MyGallery\\Europe\\city3.jpg");
	//imagePaths.push_back("C:\\Users\\ss0193\\Desktop\\MyGallery\\Europe\\city1.jpg");
	//imagePaths.push_back("C:\\Users\\ss0193\\Desktop\\MyGallery\\Europe\\city2 - Copy.jpg");
	//imagePaths.push_back("C:\\Users\\ss0193\\Desktop\\MyGallery\\Europe\\city2.jpg");
	//imagePaths.push_back("C:\\Users\\ss0193\\Desktop\\MyGallery\\Europe\\city3.jpg");
	//imagePaths.push_back("C:\\Users\\ss0193\\Desktop\\MyGallery\\Europe\\city1.jpg");
	//imagePaths.push_back("C:\\Users\\ss0193\\Desktop\\MyGallery\\Europe\\city2 - Copy.jpg");
	//imagePaths.push_back("C:\\Users\\ss0193\\Desktop\\MyGallery\\Europe\\city2.jpg");
	//imagePaths.push_back("C:\\Users\\ss0193\\Desktop\\MyGallery\\Europe\\city3.jpg");


	String^ folderName = getManagedString(galleryPath);
	Hello(folderName);

}



void Workspace::Hello(String^ foldername)
{
	array<String^>^ dir = Directory::GetDirectories( foldername );
	Console::WriteLine("--== Directories inside '{0}' ==--", foldername);
	for (int i=0; i<dir->Length; i++)
		directoryList.push_back(Dir(getUnmanagedString(dir[i])));

	array<String^>^ file = Directory::GetFiles( foldername );
	Console::WriteLine("--== Files inside '{0}' ==--", foldername);
	for (int i=0; i<file->Length; i++)
		Console::WriteLine(file[i]);

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