/*********************************************************************
** Program name: Final Project
** Author: Mario Franco-Munoz
** Date: 11/27/2017
** Description: Header file for the FinalBoss class. FinalBoss class is
** an inherited Space class that represents a space containing the Final Boss
** of the game.
*********************************************************************/

#include "Space.hpp"
#include"BattleMage.hpp"

#ifndef FINALBOSSROOM_HPP
#define FINALBOSSROOM_HPP
class FinalBossRoom :public Space {
private:
	int baseAttack;
	int hitpoints;
	const int EXP_YIELD = 50;
public:
	//constructor
	FinalBossRoom(int);

	void specialEvent(BattleMage *);

	virtual ~FinalBossRoom() {

	}

};
#endif

