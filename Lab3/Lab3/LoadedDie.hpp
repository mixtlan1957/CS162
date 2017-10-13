/*********************************************************************
** Program name: Lab3
** Author: Mario Franco-Munoz
** Date: 10/12/2017
** Description: Header file for LoadedDie class.
** LoadedDie is a derived class from the Die class. Like its parent, it also contains a data type
** representing the number of sides a given LoadedDie object can have. However its dice roll function is different
** in the sense that it will produced (upward) skewed results. (Rolls will be higher than normal.)
*********************************************************************/
#include "Die.hpp"

#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP

class LoadedDie :public Die {
private:

public:
	//default constructor
	LoadedDie();
	//constructor for loaded die
	LoadedDie(const int &numberSides);

	int loadedRoll(int, int);

	virtual ~LoadedDie() {
	}

};
#endif