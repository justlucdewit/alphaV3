#include <iostream>

/*
	the errorSys fragment will recieve a errorCode, and
	will then print that error code to the screen, and
	then quit the execution

	the error code is split into 2 parts:
	-type
	-variation

	in case of error 1669 the type number is 16 and the
	variation number is 69, the variation number is always
	2 digits long
*/
void throwError(const std::string s){
    std::cout << s;
	std::exit(1);
}
