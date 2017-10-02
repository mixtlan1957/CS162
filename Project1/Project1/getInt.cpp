/*********************************************************************
** Program name: Project 1 (Langton's Ant)
** Author: Mario Franco-Munoz
** Date: 09/28/2017
** Description: User input validation function tailored to getting a single integer input from the user.
** checks for empty input and if input was an integer. 
*********************************************************************/

#include "getInt.hpp"

//function taken/based on input validation video provided by Harlan James (as seen on youtube.com)
int getInt(int *ptr)
{
	int status = -1;
	char buffer[4096];

	if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
		std::cout << "No data read." << std::endl;
	}
	else if (sscanf(buffer, "%i", ptr) != 1) {
		std::cout << "Integer not entered. ";
	}
	else {
		status = 0;
	}
	return status;
}