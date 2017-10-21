/*********************************************************************
** Description: Header file for Integer_Input_Val function. Function checks user input to ensure that it is
** an integer and returns 1 if the input was not an integer and returns a 0 if the input was an integer.
** The main contents of this function was written by Harlan James and additional changes made by code example
** provided in piazza post by Mason Reiset.
*********************************************************************/

#include "float_Input_Val.hpp"


int getFloat(float *ptr) {
	float testFloat;
	int testInt;
	
	int status = -1;
	char buffer[4096];

	if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
		std::cout << "No data read." << std::endl;
	}

	else if (sscanf(buffer, "%f", ptr) != 1) {
		std::cout << "Integer not entered. ";	
	}
	else if (sscanf(buffer, "%f", ptr) == 1) {
		testFloat = *ptr;
		testFloat *= 10;			//precision limit set to .1 in this case
		testInt = static_cast<int>(testFloat);
		if (testFloat > testInt) {
			std::cout << "Please enter a number with up to .1 precision." << std::endl;
		}
		else {
			status = 0;
		}
	}
	return status;
}
