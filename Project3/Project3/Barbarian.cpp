/*********************************************************************
** Program name: Project3
** Author: Mario Franco-Munoz
** Date: 10/26/2017
** Description: Source file for Barbarian class. The Barbarian class is a subclass of the
** abstract Character class that represents a Barbarian character type in the Fantasy
** Combat Game universe.
*********************************************************************/

#include "Barbarian.hpp"

//default constructor
Barbarian::Barbarian() {
	this->armor = 0;
	this->strength = 12;
	this->type = "Barbarian";
}

/*********************************************************************
** Description: getDescription is an accessor function that returns the Barbarian specific characteristics.
*********************************************************************/
std::string Barbarian::getCharacteristics() {
	return this->CHARACTERISTICS;
}

/*********************************************************************
** Description: getSpecial is an accessor function that returns the Barbarian specific special ability.
*********************************************************************/
std::string Barbarian::getSpecial() {
	return this->SPECIAL;
}

/*********************************************************************
** Description: getAttackDmg is a mutator specific to the Barbarian class that 
** sets the attack of a Barbarian on two rolls between 1 to 6.
*********************************************************************/
void Barbarian::setAttackDmg() {
	this->attack = randNoGen(1, 6) + randNoGen(1, 6);  //format of randNoGen is min, max
}

/*********************************************************************
** Description: getDefense is a mutator specific to the Barbarian class in this case
** that sets the defense of a Barbarian on two rolls between 1 to 6.
*********************************************************************/
void Barbarian::setDefense() {
	this->defense = randNoGen(1, 6) + randNoGen(1, 6);
}



