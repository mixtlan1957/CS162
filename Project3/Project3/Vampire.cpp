/*********************************************************************
** Program name: Project3 & 4
** Author: Mario Franco-Munoz
** Date: 10/26/2017
** Description: Source file for Vampire class. The Barbarian class is a subclass of the
** abstract Character class that represents a Barbarian character type in the Fantasy
** Combat Game universe.
*********************************************************************/

#include "Vampire.hpp"

Vampire::Vampire() {
	this->armor = 1;
	this->strength = 18;
	this->type = "Vampire";
}

/*********************************************************************
** Description: getDescription is an accessor function which in this case 
** returns the Vampire specific characteristics.
*********************************************************************/
std::string Vampire::getCharacteristics() {
	return this->CHARACTERISTICS;
}

/*********************************************************************
** Description: getSpecial is an accessor function that in this case 
** returns the Vampire specific special ability.
*********************************************************************/
std::string Vampire::getSpecial() {
	return this->SPECIAL;
}

/*********************************************************************
** Description: getAttackDmg is a mutator that in this case applies to the Vampire class that
** sets the attack of a Vampire on a roll between 1 and 12.
*********************************************************************/
void Vampire::setAttackDmg() {
	this->attack = randNoGen(1, 12);
}

/*********************************************************************
** Description: getDefense is a virtual mutator that in this case applies a defense value
** to a Vampire Character from 1 to 6.
*********************************************************************/
void Vampire::setDefense() {
	this->defense = randNoGen(1, 6);
}


