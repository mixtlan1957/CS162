/*********************************************************************
** Program name: Project 2 (Zoo Tycoon)
** Author: Mario Franco-Munoz
** Date: 10/13/2017
** Description: This function takes a min and max value and returns a random number based on time generated
** seed value. Additional mode parameter serves to generate a different random number in the case that this function
** is executed subsequently. Most of this function was taken from C++ early objects by Gaddis (7e) 
*********************************************************************/

#include "randomNumGen.hpp"

int randomNumGen(int maxIn, int minIn, int mode) {
	unsigned seed;
	if (mode == 1) {

		seed = time(0);
		srand(seed);

		return (rand() % (maxIn - minIn + 1)) + minIn;

	}
	else  {
		unsigned seed;

		seed = time(0) - (time(0) / 2);
		srand(seed);

		return (rand() % (maxIn - minIn + 1)) + minIn;

	}
}

