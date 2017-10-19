/*********************************************************************
** Program name: Project 3 (Zoo Tycoon)
** Author: Mario Franco-Munoz
** Date: 10/13/2017
** Description: Subclass of the Animal class. In this particular case, this subclass represents
** a penguin in the virtual zoo.
*********************************************************************/

#include "Penguin.hpp"

//default constructor - defaults to age of adult
Penguin::Penguin() :Animal() {
	this->cost = 1000;
	this->babyMultiplier = 5;
	this->foodCost = BASE_FOOD_COST;
	this->payoff = 100;
}

//constructor for the creation of babies
Penguin::Penguin(int ageIn) {
	this->cost = 1000;
	this->babyMultiplier = 5;
	this->foodCost = BASE_FOOD_COST;
	this->payoff = 100;
	this->age = ageIn;
}

//assignment operator
Penguin& Penguin::operator=(const Penguin &RHS) {
	if (this != &RHS) {
		this->age = RHS.age;
		this->babyMultiplier = RHS.babyMultiplier;
		this->cost = RHS.cost;
		this->foodCost = RHS.cost;
	}
	return *this;
}