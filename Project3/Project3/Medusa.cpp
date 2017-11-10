/*********************************************************************
** Program name: Project3 & 4
** Author: Mario Franco-Munoz
** Date: 10/26/2017
** Description: Source file for Medusa class. The Medusa class is a subclass of the
** abstract Character class that represents a Medusa character type in the Fantasy
** Combat Game universe.
*********************************************************************/

#include "Medusa.hpp"

Medusa::Medusa() {
	this->strength = 8;
	this->armor = 3;
	this->type = "Medusa";
}

/*********************************************************************
** Description: getDescription is an accessor function that in this case 
** returns the Medusa specific characteristics.
*********************************************************************/
std::string Medusa::getCharacteristics() {
	return this->CHARACTERISTICS;
}

/*********************************************************************
** Description: getSpecial is an accessor function that in this case returns 
** the Medusa specific special ability.
*********************************************************************/
std::string Medusa::getSpecial() {
	return this->SPECIAL;
}


/*********************************************************************
** Description: getAttackDmg is a mutator specific to the Medusa class that
** in this case sets the attack of a Medusa on two rolls between 1 to 6.
*********************************************************************/
void Medusa::setAttackDmg() {
	this->attack = randNoGen(1, 6) + randNoGen(1, 6);
}

/*********************************************************************
** Description: getDefense is a mutator specific to the Medusa class that in this case
** sets the defense of a Medsusa on a single roll between 1 to 6.
*********************************************************************/
void Medusa::setDefense() {
	this->defense = randNoGen(1, 6);
}


