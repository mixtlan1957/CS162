/*********************************************************************
** Program name: Project3
** Author: Mario Franco-Munoz
** Date: 10/26/2017
** Description: Source file for BlueMen class. The BlueMen class is a subclass of the
** abstract Character class that represents a Barbarian character type in the Fantasy
** Combat Game universe.
*********************************************************************/

#include "BlueMen.hpp"

BlueMen::BlueMen() {
	this->armor = 3;
	this->strength = 12;
	this->type = "Blue Men";
}

/*********************************************************************
** Description: getDescription is an accessor function which in this case
** returns the BlueMen specific characteristics.
*********************************************************************/
std::string BlueMen::getCharacteristics() {
	return this->CHARACTERISTICS;
}

/*********************************************************************
** Description: getSpecial is an accessor function that in this case
** returns the BlueMen specific special ability.
*********************************************************************/
std::string BlueMen::getSpecial() {
	return this->SPECIAL;
}

/*********************************************************************
** Description: getAttackDmg is a mutator that in this case applies to the Blue class that
** sets the attack of a BlueMen group on two rolls between 1 and 10.
*********************************************************************/
void BlueMen::setAttackDmg() {
	this->attack = randNoGen(1, 10) + randNoGen(1, 10);
}

/*********************************************************************
** Description: getDefense is a virtual mutator that in this case applies a defense value
** to a BlueMen Character from 3 to 6. If BlueMen have taken damage, the lower defense value multiplier drops
** by 1 for every 4 points of damage taken.
*********************************************************************/
void BlueMen::setDefense() {
	if (this->strength > 8) {
		this->defense = randNoGen(1, 6) + randNoGen(1, 6) + randNoGen(1, 6);
	}
	else if (this->strength > 4 && this->strength <= 8) {
		this->defense = randNoGen(1, 6) + randNoGen(1, 6);
	}
	else {
		this->defense = randNoGen(1, 6);
	}

}


