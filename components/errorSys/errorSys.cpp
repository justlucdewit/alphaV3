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

	types:
	0		reading errors, these errors are caused by missing files
			or files that cannot be oppened

	69		impossible error, this means a error code has been
			recieved that doesnt exist, and that has to be a internal
			error in the alpha engine
*/
void throwError(unsigned short errorCode){
	switch (errorCode){
		case 0: {
			std::cout << "[ERROR 000] the .ac file could not be read, did you spell it correctly?";
			break;
		}

		case 1: {
			std::cout << "[ERROR 001] no acconfig.json file has been found";
			break;
		}

		default: {
			std::cout << "[ERROR 6900] an error has occurred that cant be identified, this should not happen and is an mistake inside the alpha engine";
		}
	}
	std::exit(1);
}
