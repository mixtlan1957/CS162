/*********************************************************************
** Program name: Final Project
** Author: Mario Franco-Munoz
** Date: 11/27/2017
** Description: Header file for the DefaultRoom class. DefaultRoom class is
** an inherited Space class that represents a typical "square" or space on the
** GameBoard.
*********************************************************************/

#include "Space.hpp"
#include "BattleMage.hpp"




#ifndef DEFAULTROOM_HPP
#define DEFAULTROOM_HPP

class DefaultRoom :public Space {
private:
	bool alreadyVisited;

public:

	//copy constructor
	DefaultRoom(int);

	void specialEvent(BattleMage *);

	virtual ~DefaultRoom() {

	}


};
#endif