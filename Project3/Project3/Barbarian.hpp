/*********************************************************************
** Program name: Project3
** Author: Mario Franco-Munoz
** Date: 10/26/2017
** Description: Header file for Barbarian class. The Barbarian class is a subclass of the
** abstract Character class that represents a Barbarian character type in the Fantasy
** Combat Game universe.
*********************************************************************/

#include "Character.hpp"

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

class Barbarian :public Character {
private:
	std::string const CHARACTERISTICS = "Think Conan or Hercules from the movies. Big sword, big muscles, bare torso.";
	std::string const SPECIAL = "";

public:
	//default constructor
	Barbarian();
	
	virtual void setAttackDmg();
	virtual void setDefense();
	virtual std::string getCharacteristics();
	virtual std::string getSpecial();


};
#endif
