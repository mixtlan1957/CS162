/*********************************************************************
** Program name: Project3
** Author: Mario Franco-Munoz
** Date: 10/26/2017
** Description: Source file for Vampire class. The Barbarian class is a subclass of the
** abstract Character class that represents a Barbarian character type in the Fantasy
** Combat Game universe.
*********************************************************************/

#include "Character.hpp"

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

class Vampire :public Character {
private:
	std::string const CHARACTERISTICS = "Suave, debonair, but vicious and surprisingly risilient.";
	std::string const SPECIAL = "Charm";
public:
	Vampire();

	virtual void setAttackDmg();
	virtual void setDefense();
	virtual std::string getCharacteristics();
	virtual std::string getSpecial();

};
#endif
