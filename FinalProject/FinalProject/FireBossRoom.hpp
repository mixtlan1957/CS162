/*********************************************************************
** Program name: Final Project
** Author: Mario Franco-Munoz
** Date: 11/27/2017
** Description: Header file for the FireBossRoom class. FireBoss class is
** an inherited Space class that represents a space containing a FireBoss
** (mini boss that must be defeated in order to complete the game).
*********************************************************************/

#include "Space.hpp"
#include"BattleMage.hpp"

#ifndef FIREBOSSROOM_HPP
#define FIREBOSSROOM_HPP

class FireBossRoom :public Space {
private:
	int baseAttack;
	int hitpoints;
	const int EXP_YIELD = 25;
	std::string creatureType = "fire";

public:
	//constructor (copy constructor)
	FireBossRoom(int);

	void specialEvent(BattleMage *);

};
#endif

