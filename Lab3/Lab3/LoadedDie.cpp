/*********************************************************************
** Program name: Lab3
** Author: Mario Franco-Munoz
** Date: 10/12/2017
** Description: LoadedDie is a derived class from the Die class. Like its parent, it also contains a data type
** representing the number of sides a given LoadedDie object can have. However its dice roll function is different
** in the sense that it will produced (upward) skewed results. (Rolls will be higher than normal.)
*********************************************************************/
#include "LoadedDie.hpp"

//default constructor
LoadedDie::LoadedDie() :Die() {
	this->numberSides = 2;
}

//constructor
LoadedDie::LoadedDie(const int &numberSides) :Die(numberSides) {
	this->numberSides = numberSides;
}

/*********************************************************************
** Description: Loaded die version of random generator. Specifially, the outcome of a "normal"roll has a coefficient added to it.
** If the outcome of this augmented roll is more than the maximum number of faces of a die, the outcome is returned as the
** maximum number of faces of the die instead.
*********************************************************************/
int LoadedDie::loadedRoll(int player, int currentRnd) {
	int weight_factor = 4;
	int weighedRoll;
	int normalRoll;
	

	unsigned seed;
	//ensure that the result beats a typical "normal" die result but ensure that a die roll of 1 is still possible
	//as per instructors note that I noticed just in time before turning in this assignment. 


	normalRoll = rollTheDie(player, currentRnd);

	//if roll is 1 don't change the outcome.
	if (normalRoll == 1) {
		weighedRoll = 1;
		return weighedRoll;
	}
	//make the loaded die have a better chance at winning every other round
	else if (currentRnd % 2 == 1) {
		weighedRoll = (rand() % (numberSides - 1 + 1)) + 1;
		weighedRoll += (weighedRoll / weight_factor);

		if (weighedRoll > numberSides) {
			weighedRoll = numberSides;
			return weighedRoll;
		}
		else {
			return weighedRoll;
		}
	}
	else {
		weighedRoll = normalRoll;
		return weighedRoll;
	}
}