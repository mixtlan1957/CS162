/*********************************************************************
** Program name: Project 3 (Zoo Tycoon)
** Author: Mario Franco-Munoz
** Date: 10/13/2017
** Description: Subclass of the Animal class. In this particular case, this subclass represents
** a tiger in the virtual zoo.
*********************************************************************/

#include "Tiger.hpp"

//default constructor 
Tiger::Tiger() :Animal() {
	this->cost = 10000;
	this->babyMultiplier = 1;
	this->foodCost = BASE_FOOD_COST * 5;
	this->payoff = 2000;
}

//constructor for the creation of babies
Tiger::Tiger(int ageIn) {
	this->cost = 10000;
	this->babyMultiplier = 1;
	this->foodCost = BASE_FOOD_COST * 5;
	this->payoff = 2000;
	this->age = ageIn;
}

//assignment operator

Tiger& Tiger::operator=(const Tiger &RHS) {
	if (this != &RHS) {

		this->age = RHS.age;
		this->babyMultiplier = RHS.babyMultiplier;
		this->cost = RHS.cost;
		this->foodCost = RHS.cost;
	}
	return *this;
}
