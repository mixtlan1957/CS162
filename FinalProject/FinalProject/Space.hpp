/*********************************************************************
** Program name: Final Project
** Author: Mario Franco-Munoz
** Date: 11/27/2017
** Description: Header file for abstract space class represents a space/square 
** in the virtual gamespace.
*********************************************************************/


#include "BattleMage.hpp"
#include "randNoGen.hpp"
#include "Integer_Input_Val.hpp"

#include <iostream>

#ifndef SPACE_HPP
#define SPACE_HPP

class Space {
protected:
	Space *top;
	Space *right;
	Space *left;
	Space *bottom;
	int spaceId;
	BattleMage *charSlot;

public:
	
	//default constructor
	Space();

	//mutator functions
	virtual void setTop(Space *);
	virtual void setRight(Space *);
	virtual void setLeft(Space *);
	virtual void setBottom(Space *);

	//accessor functions
	virtual Space* getTop();
	virtual Space* getRight();
	virtual Space* getLeft();
	virtual Space* getBottom();
	virtual int getID();

	//each room will have its own event which depends on the Space type.
	virtual void specialEvent(BattleMage*) = 0;


	virtual ~Space() {

	}


};
#endif
