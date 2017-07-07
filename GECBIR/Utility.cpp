#include "Utility.h"


 namespace GECBIR {

Utility::Utility(void)
{
}


Utility::~Utility(void)
{
}

String^ Utility::getManagedString(string text)
{
System::String^ managed = "test";
std::string unmanaged = msclr::interop::marshal_as<std::string>(managed);
}

}