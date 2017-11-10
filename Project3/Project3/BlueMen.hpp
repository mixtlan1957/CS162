/*********************************************************************
** Program name: Project3 & 4
** Author: Mario Franco-Munoz
** Date: 10/26/2017
** Description: Source file for BlueMen class. The BlueMen class is a subclass of the
** abstract Character class that represents a Barbarian character type in the Fantasy
** Combat Game universe.
*********************************************************************/

#include "Character.hpp"

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

class BlueMen :public Character {
private:
	std::string const CHARACTERISTICS = "They are small, 6 inch tall, but fast and tough.\n" 
		"They are hard to hit so they can take some damage. They can also do a LOT of damage\n" 
		"when they crawl inside enemies' armor or clothing.";
	std::string const SPECIAL = "Mob";

public:
	BlueMen();

	virtual void setAttackDmg();
	virtual void setDefense();
	virtual std::string getCharacteristics();
	virtual std::string getSpecial();

	virtual ~BlueMen() {

	}

};
#endif 

