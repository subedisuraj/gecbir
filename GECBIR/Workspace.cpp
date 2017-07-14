#include "Workspace.h"
#include <Windows.h>
#include <vector>


using namespace std;



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

	int a = 0;


	


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
