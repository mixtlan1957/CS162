/*********************************************************************
** Program name: Project3
** Author: Mario Franco-Munoz
** Date: 10/26/2017
** Description: Source file for HarryPotter class. The HarryPotter class is a subclass of the
** abstract Character class that represents a Harry Potter character type in the Fantasy
** Combat Game universe.
*********************************************************************/

#include "Character.hpp"

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

class HarryPotter :public Character {
private:
	std::string const CHARACTERISTICS = "Harry Potter is a wizard";
	std::string const SPECIAL = "Hogwarts";

public:
	HarryPotter();

	virtual void setAttackDmg();
	virtual void setDefense();
	virtual std::string getCharacteristics();
	virtual std::string getSpecial();


	virtual ~HarryPotter() {

	}
};
#endif 

