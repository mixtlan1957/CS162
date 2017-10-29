/*********************************************************************
** Program name: Project3
** Author: Mario Franco-Munoz
** Date: 10/26/2017
** Description: Header file for Medusa class. The Medusa class is a subclass of the
** abstract Character class that represents a Medusa character type in the Fantasy
** Combat Game universe.
*********************************************************************/

#include "Character.hpp"

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

class Medusa :public Character {
private:
	std::string const CHARACTERISTICS = "Scrawny lady with snakes for hair which \n"
		"helps her during combat. Just don't look at her!";
	std::string const SPECIAL = "Glare";

public:
	Medusa();

	virtual void setAttackDmg();
	virtual void setDefense();
	virtual std::string getCharacteristics();
	virtual std::string getSpecial();


	virtual ~Medusa() {

	}

};
#endif
