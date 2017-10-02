/*********************************************************************
** Program name: Project 1 (Langton's Ant)
** Author: Mario Franco-Munoz
** Date: 09/28/2017
** Description: Menu function offering options to user to select mode of game (default or random position for
**	ant starting location) or quit. 
*********************************************************************/

#include "menuFunction.hpp"
#include "getInt.hpp"

int menuFunction() {
	int choice;
	int status;
	int errorCounter = 0;

	//do-while loop to present options to users.
	do {
		if (errorCounter > 1) {
			std::cout << "Invalid selection. Please enter a valid menu selection." << std::endl;
		}
		std::cout << "Please enter one of the following options: " << std::endl;
		std::cout << "1.	Start Langton's Ant simulation (default mode)." << std::endl;
		std::cout << "2.	EC Option: Start Langton's Ant simulation with random starting point for ant." << std::endl;
		std::cout << "3.	Exit program." << std::endl;
		errorCounter++;
	} while (((status=getInt(&choice)) != 0 ) || (choice < 1 || choice > 3));


	//swtich for input of cases
	switch (choice) {
	case 1:
		return 1;
		break;
	case 2:
		return 2;
		break;
	case 3: std::cout << "Thank you for playing. Program will now exit." << std::endl;
		exit(0);
	default: std::cout << "FATAL ERROR" << std::endl;
	}


}
