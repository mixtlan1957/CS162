/*********************************************************************
** Program name: Lab5
** Author: Mario Franco-Munoz
** Date: 10/23/17
** Description: Menu function offering options to user to select mode of operation.
*********************************************************************/

#include "menuFunction.hpp"
#include "Integer_Input_Val.hpp"

int menuFunction() {
	float choice;
	int status;

	//do-while loop to present options to users.
	status = 0;
	do {
		std::cout << "\n" << std::endl;
		if (status !=  0) {
			std::cout << "Invalid selection. Please enter a valid menu selection." << std::endl;
		}
		std::cout << "Please enter one of the following options: " << std::endl;
		std::cout << "1.    Print a string in reverse." << std::endl;
		std::cout << "2.    Calculate the sum of an array of integers." << std::endl;
		std::cout << "3.    Calculate the triangular number of an integer N." << std::endl;
		std::cout << "4.    Exit program." << std::endl;
	} while (((status=getInt(&choice)) != 0 ) || (choice < 1 || choice > 4));


	//swtich for input of cases
	switch (static_cast<int>(choice)) {
	case 1:
		return 1;
		break;
	case 2:
		return 2;
		break;
	case 3:
		return 3;
		break;
	case 4: 
		return 4;
		break;
	default: std::cout << "FATAL ERROR" << std::endl;
		exit(1);
	}


}
