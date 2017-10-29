/*********************************************************************
** Program name: Project3 (Fantasy Combat Game)
** Author: Mario Franco-Munoz
** Date: 10/26/2017
** Description: Source file for Character base class. The Character base class
** is the foundation for the different characters in the Fantasy Combat Game.
*********************************************************************/

#include "Character.hpp"



/*********************************************************************
** Description: getArmor is an acessor function for the "armor" data member used by characters
** of the Fantasy Combat Game.
*********************************************************************/
int Character::getArmor() {
	return this->armor;
}

/*********************************************************************
** Description:  getStrength is an accesor function for the "strength" data member used by
** characters of the Fantasy Combat Game.
*********************************************************************/
int Character::getStrength() {
	return this->strength;
}

/*********************************************************************
** Description:  getStrength is an accesor function for the "strength" data member used by
** characters of the Fantasy Combat Game.
*********************************************************************/
int Character::getDefense() {
	return this->defense;
}

/*********************************************************************
** Description: setArmor is a mutator function for the "armor" data member used by characters
** of the Fantasy Combat Game.
*********************************************************************/
void Character::setArmor(int armorIn) {
	this->armor = armorIn;
}

/*********************************************************************
** Description: setStrength is a mutator function for the "armor" data member used by characters
** of the Fantasy Combat Game.
*********************************************************************/
void Character::setStrength(int strengthIn) {
	this->strength = strengthIn;
}

/*********************************************************************
** Description: getType is an accessor function for the character type.
*********************************************************************/
std::string Character::getType() {
	return this->type;
}

/*********************************************************************
** Description: getType is an accessor function for the damage a character does.
*********************************************************************/
int Character::getDamage() {
	return this->attack;
}

/*********************************************************************
** Description: setGeneralFlag is used to set the bool variable generalFlag.
*********************************************************************/
void Character::setGeneralFlag(bool input) {
	this->generalFlag = input;
}


/*********************************************************************
** Description: getGeneralFlag returns the bool General flag when called.
*********************************************************************/
bool Character::getGeneralFlag() {
	return  this->generalFlag;
}

