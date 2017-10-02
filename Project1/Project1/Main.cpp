/*********************************************************************
** Program name: Project 1 (Langton's Ant)
** Author: Mario Franco-Munoz
** Date: 09/28/2017
** Description: Main file for Langton's Ant simulation using ascii symbols on the command prompt.
** Basic rules for simulation is that if the ant is on a white space (denoted by ' ') the ant will turn right 90 deg
** and change the space to black (denoted by '#').
** If the ant is  on a black space, the opposite occurs: the ant will turn left 90 deg and change the space to white.
*********************************************************************/

//function headers
#include "menuFunction.hpp"
#include "getInt.hpp"

//class headers
#include "Ant.hpp"

int main() {
	int modeSelection = 0;
	int keepPlaying = 0;
	int status;


	//introduction
	std::cout << "Welcome to the Langton's Ant simulator." << std::endl;


	do {
		Ant antSim = Ant();
		//menu function call
		modeSelection = menuFunction();
		antSim.inputPrompt(modeSelection);
		antSim.initBoard();
		antSim.moveAndPrint();

		//end of simulation statement
		std::cout << "Simulation has concluded.\n";
		std::cout << "Enter 1 to run another simulation. \n";
		std::cout << "Enter 2 to exit program." << std::endl;
		while ((status = getInt(&keepPlaying) != 0) || (keepPlaying > 2 || keepPlaying < 1)) {
			std::cout << "Invalid menu selection. Please try again." << std::endl;
			std::cout << "Enter 1 to run another simulation. \n";
			std::cout << "Enter 2 to exit program." << std::endl;
		}
	} while (keepPlaying == 1);
	
	
	return 0;
}
