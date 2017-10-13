/*********************************************************************
** Program name: Lab3
** Author: Mario Franco-Munoz
** Date: 10/12/2017
** Description: Die class represents a N-faced die. Where the number of faces is determined by the user.
** Contains a function to return a random result based on the c++ library rand() function. 
*********************************************************************/


#include "Die.hpp"

//default constructor
Die::Die() {
	this->numberSides = 2;			//minimum number of sides
}

Die::Die(int sidesIn) {
	this->numberSides = sidesIn;
}


/*********************************************************************
** Description: Returns a random value between the 1 to N where N is number of sides of die. Where input to the function
** (to aid random number generation) is the player's number (1 or 2) and second input is the current round number.
*********************************************************************/
int Die::rollTheDie(int player, int currentRnd) {
	
	
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

		return (rand() % (numberSides - 1 + 1)) + 1;
	}
	else { //additional block is to ensure that seed is different for the two players.
		if (currentRnd % 2 == 0) {
			seed = time(0) * 3 + currentRnd;
			srand(seed);
		}
		else {
			seed = time(0) / 3 + currentRnd;
			srand(seed);
		}
		return (rand() % (numberSides - 1 + 1)) + 1;
	}
}

/*********************************************************************
** Description: Sets number of sides of die.
*********************************************************************/
void Die::setSides(int sidesIn) {
	this->numberSides = sidesIn;
}