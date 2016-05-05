#include <iostream>
#include <fstream>
#include <string>
#include "library.hpp"
using namespace std;

int main()
{
	Library library;
	library.initLibrary();
	library.run();

	return 0;
}
