/*********************************************************************
** Program name: Project 3 (Zoo Tycoon)
** Author: Mario Franco-Munoz
** Date: 10/13/2017
** Description: Subclass of the Animal class. In this particular case, this subclass represents
** a turtle in the virtual zoo.
*********************************************************************/
#include "Turtle.hpp"

//default constructor - defaults to age of adult
Turtle::Turtle() :Animal() {
	this->cost = 100;
	this->babyMultiplier = 10;
	this->foodCost = BASE_FOOD_COST/2;
	this->payoff = 5;
}

//constructor for the creation of babies
Turtle::Turtle(int ageIn) {
	this->cost = 100;
	this->babyMultiplier = 10;
	this->foodCost = BASE_FOOD_COST/2;
	this->payoff = 5;
	this->age = ageIn;
}

//move operator
Turtle& Turtle::operator=(Turtle &RHS) {
	if (this != &RHS) {
		this->age = RHS.age;
		this->babyMultiplier = RHS.babyMultiplier;
		this->cost = RHS.cost;
		this->foodCost = RHS.foodCost;
	}
	return *this;
}