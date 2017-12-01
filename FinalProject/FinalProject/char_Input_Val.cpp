/*********************************************************************
** Description:  Function checks user input to ensure that it is
** a character and returns 1 if the input was not a character and returns a 0 if the input was an integer.
** The main contents of this function were written by Harlan James. (based on his user validation input video)
*********************************************************************/

#include "char_Input_Val.hpp"


int getValidChar(char *ptr) {
	int status = -1;
	std::string select;
	
	std::getline(std::cin, select);
	if (select.length() != 1) {
		std::cout << "Invalid input. Please enter a single alpha character (a-z) upper case or lower case." << std::endl;
		status = -1;
	}
	else if (isalpha(select.at(0))) {
		*ptr = tolower(select.at(0));
		status = 0;
	}
	else {
		std::cout << "Invalid input. Please enter a single alpha character (a-z) upper case or lower case." << std::endl;
		status = -1;
	}
	return status;
}

