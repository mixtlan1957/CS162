/*********************************************************************
** Program name: Project3
** Author: Mario Franco-Munoz
** Date: 10/26/2017
** Description: Header file for Character base class. The Character base class
** is the foundation for the different characters in the Fantasy Combat Game.
*********************************************************************/

#include "randNoGen.hpp"

#include <string>


#ifndef CHARACTER_HPP
#define CHARACTER_HPP
class Character {
protected:
	int attack;
	int defense;
	int armor;
	int strength;
	std::string type;
	bool generalFlag;

public:
	//pure virtual mutators
	virtual void setAttackDmg() = 0;
	virtual void setDefense() = 0;
	virtual std::string getCharacteristics() = 0;
	virtual std::string getSpecial() = 0;
	
	//accessors
	virtual int getArmor();
	virtual int getStrength();
	virtual int getDefense();
	virtual int getDamage();
	virtual std::string getType();
	virtual bool getGeneralFlag();
	

	//mutators
	virtual void setArmor(int);
	virtual void setStrength(int);
	virtual void setGeneralFlag(bool);


	virtual ~Character() {

	}


};
#endif