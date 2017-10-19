/*********************************************************************
** Program name: Project 3 (Zoo Tycoon)
** Author: Mario Franco-Munoz
** Date: 10/13/2017
** Description: Animal class provides a parent template for the subclasses that are used throughout the virtual zoo game.
** Get and set functions for the different properties (protected members) of the subclasses live here.
*********************************************************************/

#include "Animal.hpp"


//default Constructor
Animal::Animal() {
	this->age = 1;			//animals added with default constructor are 1 day old.
}


/*********************************************************************
** Description: setAge sets the age of a given animal subclass. typically used for setting age of babies to 0.
*********************************************************************/
void Animal::setAge(int ageIn) {
	this->age = ageIn;
}

/*********************************************************************
** Description: getAge returns the age of a given animal subclass.
*********************************************************************/
int Animal::getAge() {
	return this->age;
}
/*********************************************************************
** Description: getPayoff returns the payoff of a given animal subclass.
*********************************************************************/
double Animal::getPayoff() {
	return this->payoff;
}

/*********************************************************************
** Description: getBabyMultiplier returns the number of babies an animal can have
*********************************************************************/
int Animal::getBabyMult() {
	return this->babyMultiplier;
}

/*********************************************************************
** Description: getCost returns the cost of an animal.
*********************************************************************/
int Animal::getCost() {
	return this->cost;
}

/*********************************************************************
** Description: getFoodCost returns the food cost of an animal.
*********************************************************************/
int Animal::getFoodCost() {
	return this->foodCost;
}


/*********************************************************************
** Description: function to access and increment the age of an animal after a day has ended (as part of the Zoo class).
*********************************************************************/
void Animal::incrementAge() {
	this->age++;
}



