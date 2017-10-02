/*********************************************************************
** Program name: Project 1 (Langton's Ant)
** Author: Mario Franco-Munoz
** Date: 09/28/2017
** Description: Function to generate a random number within specified range (minimum value, maximum value). 
**	Where the min and max are the first parameters and the third parameter provides an input to generate a different
** number value when a second random number value is required.
*********************************************************************/

#include "randNoGen.hpp"

//this function is nearly directly taken from pg 135 "C++ Early Objectes 9th ed" Gaddis
int randNoGen(int minIn, int maxIn, int mode ) {
	if (mode == 1) {
		unsigned seed;

		seed = time(0);
		srand(seed);

		return (rand() % (maxIn - minIn + 1)) + minIn;

	}
	else if (mode == 2) {
		unsigned seed;

		seed = time(0) - (time(0)/2);
		srand(seed);

		return (rand() % (maxIn - minIn + 1)) + minIn;

	}
}