#pragma once
#include <msclr\marshal_cppstd.h>
#include <string>


namespace GECBIR {


using std::string;


class Utility
{
public:
	string getManagedString(string text);
	Utility(void);
	~Utility(void);
};

}