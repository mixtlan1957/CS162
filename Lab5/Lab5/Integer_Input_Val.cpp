/*********************************************************************
** Description: Header file for Integer_Input_Val function. Function checks user input to ensure that it is
** an integer and returns 1 if the input was not an integer and returns a 0 if the input was an integer.
** The main contents of this function was written by Harlan James and additional changes made by code example
** provided in piazza post by Mason Reiset.
*********************************************************************/

#include "Integer_Input_Val.hpp"


int getInt(float *ptr) {
	float testFloat;			
	int testInt;		
	int status = -1;			
	char buffer[4096];      //input limit

	//read in input into the buffer using stdin
	if (fgets(buffer, sizeof(buffer), stdin) == NULL) { 
		std::cout << "No data read." << std::endl;
	}

	else if (sscanf(buffer, "%f", ptr) != 1) {   //check if input in the buffer is of float compatible format.
		std::cout << "Integer not entered. ";	
	}
	else if (sscanf(buffer, "%f", ptr) == 1) {
		testFloat = *ptr;
		testInt = static_cast<int>(testFloat); //truncante the float by casting it into an int.
		if (testFloat > static_cast<float>(testInt)) { //revert the now truncated int to float for proper comparison
			std::cout << "Please enter an integer." << std::endl;
		}
		else {
			status = 0;
		}
	}
	return status;
}
