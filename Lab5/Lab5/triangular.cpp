/*********************************************************************
** Program name: Lab5
** Author: Mario Franco-Munoz
** Date: 10/23/2017
** Description: Source file for "triangular" function. Function has one parameter
** an integer for which it calculates the triangular number (e.g. if n = 3, triangular = 3 + 2 + 1)
*********************************************************************/

#include "triangular.hpp"

int triangular(int numIn) {
	if (numIn > 0) { //base case: stop when numIn reaches 0.
		numIn -= 1;
		return (numIn + 1) + triangular(numIn); //recursive statement
	}
	else {
		return 0;
	}

}