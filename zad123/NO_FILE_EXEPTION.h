#include <iostream>
#include <exception>
#include <string>
using namespace std;
class NO_FILE_EXEPTION : public exception
{
public:
	string NO_FILE();
};



