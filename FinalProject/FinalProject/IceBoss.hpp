/*********************************************************************
** Program name: Final Project
** Author: Mario Franco-Munoz
** Date: 11/27/2017
** Description: Header file for the IceBoss class. IceBoss class is
** an inherited Space class that represents a space containing an IceBoss
** (mini boss that must be defeated in order to complete the game).
*********************************************************************/

#include "Space.hpp"
#include"BattleMage.hpp"

#ifndef ICEBOSS_HPP
#define ICEBOSS_HPP

class IceBoss :public Space {
private:
	int baseAttack;
	int hitpoints;
	std::string creatureType = "ice";
	const int EXP_YIELD = 35;

public:
	//constructor (copy constructor)
	IceBoss(int);

	void specialEvent(BattleMage *);

	virtual ~IceBoss() {

	}

};
#endif

