/*********************************************************************
** Program name: Project 3 (Zoo Tycoon)
** Author: Mario Franco-Munoz
** Date: 10/13/2017
** Description: Header file for Animal class. 
** "Animal class provides a parent template for the subclasses that are used throughout the virtual zoo game.
** Get and set functions for the different properties (protected members) of the subclasses live here."
*********************************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal {
	
protected:
	const int BASE_FOOD_COST = 10;
	int age;				//age is in days
	int cost;
	int foodCost;
	int babyMultiplier;
	double payoff;

public:
	//default constructor
	Animal::Animal();

	int getAge();
	int getCost();
	int getBabyMult();
	int getFoodCost();
	double getPayoff();
	void incrementAge();
	void setAge(int);


};
#endif