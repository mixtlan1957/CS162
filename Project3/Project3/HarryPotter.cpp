/*********************************************************************
** Program name: Project3 & 4
** Author: Mario Franco-Munoz
** Date: 10/26/2017
** Description: Source file for HarryPotter class. The HarryPotter class is a subclass of the
** abstract Character class that represents a Harry Potter character type in the Fantasy
** Combat Game universe.
*********************************************************************/

#include "HarryPotter.hpp"


HarryPotter::HarryPotter() {
	this->strength = 10;
	this->armor = 0;
	this->type = "Harry Potter";
	generalFlag = true; //in this case this general bool flag is used to denote 
						//whether or not HarryPotter still has an extra life.
}

/*********************************************************************
** Description: getDescription is an accessor function that returns the HarryPotter specific characteristics.
*********************************************************************/
std::string HarryPotter::getCharacteristics() {
	return this->CHARACTERISTICS;
}

/*********************************************************************
** Description: getSpecial is an accessor function that returns the HarryPotter specific special ability.
*********************************************************************/
std::string HarryPotter::getSpecial() {
	return this->SPECIAL;
}

/*********************************************************************
** Description: getAttackDmg is a mutator specific to the HarryPotter class that
** in this case sets the attack of a HarryPotter to two rolls between 1 and 6.
*********************************************************************/
void HarryPotter::setAttackDmg() {
	this->attack = randNoGen(1, 6) + randNoGen(1, 6);
}

/*********************************************************************
** Description: getAttackDmg is a mutator specific to the HarryPotter class that
** in this case sets the attack of a HarryPotter to two rolls between 1 and 6.
*********************************************************************/
void HarryPotter::setDefense() {
	this->defense = randNoGen(1, 6) + randNoGen(1, 6);
}
