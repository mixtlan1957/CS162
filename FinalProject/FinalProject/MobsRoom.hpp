/*********************************************************************
** Program name: Final Project
** Author: Mario Franco-Munoz
** Date: 11/27/2017
** Description: Header file for MobsRoom class. MobsRoom class represents a space
** with an enemy demon that must be defeated.
*********************************************************************/

#include "Space.hpp"
#include "BattleMage.hpp"




#ifndef MobsRoom_HPP
#define MobsRoom_HPP

class MobsRoom :public Space {
private:
	int creatureStrength;
	int creatureBaseAtk;
	const int EXP_YIELD = 10;

public:

	//copy constructor
	MobsRoom(int);

	void specialEvent(BattleMage *);

};
#endif