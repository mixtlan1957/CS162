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
** Description: Loaded die version of random generator. SPecifially, the outcome of a "normal"roll has a coefficient added to it.
** If the outcome of this augmented roll is more than the maximum number of faces of a die, the outcome is returned as the
** maximum number of faces of the die instead.
*********************************************************************/
int LoadedDie::loadedRoll(int player, int currentRnd) {
	int weight_factor = 5;
	int weighedRoll;
	
	unsigned seed;

	//ensure that the result for player 1 and player 2 are different in case the executiong time is too fast
	//for the seed to be different
	if (player == 1) {
		if (currentRnd % 2 == 0) {
			seed = time(0) / 7 + currentRnd;
			srand(seed);
		}
		else {
			seed = time(0) * 7 + currentRnd;
			srand(seed);
		}

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
	else { //second block is to ensure that the seed is different for each player.
		if (currentRnd % 2 == 0) {
			seed = time(0) * 3 + currentRnd;
			srand(seed);
		}
		else {
			seed = time(0) / 3 + currentRnd;
			srand(seed);
		}
		
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
}