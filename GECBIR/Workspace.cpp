#include "Workspace.h"
#include <Windows.h>
#include <vector>
#include <boost/filesystem.hpp>

using namespace std;
using namespace boost::filesystem;


using std::vector;


Workspace::Workspace(void)
{
	galleryPath = "C:\\Users\\ss0193\\Desktop\\MyGallery\\Europe\\";
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
	
	string  searchString = galleryPath ; 
	const char *cstr = searchString.c_str();
	GetFileList(cstr,imagePaths);
	int a = 0;


	


}

int Workspace::GetFileList(const char *searchkey, std::vector<std::string> &list)
{
    // list all files in current directory.
    //You could put any file path in here, e.g. "/home/me/mwah" to list that directory
	path p (searchkey);

    directory_iterator end_itr;

    // cycle through the directory
    for (directory_iterator itr(p); itr != end_itr; ++itr)
    {
        // If it's not a directory, list it. If you want to list directories too, just remove this check.
        if (is_regular_file(itr->path())) {
            // assign current file name to current_file and echo it out to the console.
            string current_file = itr->path().string();
            cout << current_file << endl;
        }
    }
	return 0;
}


//int Workspace::GetFileList(const char *searchkey, std::vector<std::string> &list)
//{
//    WIN32_FIND_DATA fd;
//    HANDLE h = FindFirstFile(searchkey,&fd);
// 
//    if(h == INVALID_HANDLE_VALUE)
//    {
//        return 0; // no files found
//    }
// 
//    while(1)
//    {
//        list.push_back(fd.cFileName);
// 
//        if(FindNextFile(h, &fd) == FALSE)
//            break;
//    }
//    return list.size();
//}




Workspace::~Workspace(void)
{
}
