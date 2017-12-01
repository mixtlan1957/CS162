/*********************************************************************
** Program name: Final Project
** Author: Mario Franco-Munoz
** Date: 11/27/2017
** Description: Abstract space class represents a space/square in the virtual gamespace.
*********************************************************************/

#include "Space.hpp"

//default constructor
Space::Space() {
	this->spaceId = -1;
	this->top = nullptr;
	this->right = nullptr;
	this->left = nullptr;
	this->bottom = nullptr;
	this->charSlot = nullptr;
}

/*********************************************************************
** Description: setTop sets the pointer top to point at the Space object above
** this object.
*********************************************************************/
void Space::setTop(Space *above) {
	this->top = above;
}

/*********************************************************************
** Description: setRight sets the pointer right to point at the Space object
** to the right of this object.
*********************************************************************/
void Space::setRight(Space *right) {
	this->right = right;
}

/*********************************************************************
** Description: setBottom sets the pointer bottom to point at the Space object
** below this object.
*********************************************************************/
void Space::setBottom(Space *below) {
	this->bottom = below;
}

/*********************************************************************
** Description: setLeft sets the pointer left to point at the Space object
** to the left of this object.
*********************************************************************/
void Space::setLeft(Space *left) {
	this->left = left;
}

/*********************************************************************
** Description: getTop returns the pointer top which is points at the 
** space above this object.
*********************************************************************/
Space* Space::getTop() {
	return this->top;
}

/*********************************************************************
** Description: getRight returns the pointer right which is points at the 
** space to the right of this object.
*********************************************************************/
Space* Space::getRight() {
	return this->right;
}

/*********************************************************************
** Description: getBottom returns the pointer bottom which is points at the 
** space above this object.
*********************************************************************/
Space* Space::getBottom() {
	return this->bottom;
}

/*********************************************************************
** Description: getLeft returns the pointer left which is points at the 
** space to the left of this object.
*********************************************************************/
Space* Space::getLeft() {
	return this->left;
}

/*********************************************************************
** Description: getID returns the id of the given block for use in navigating through the map.
*********************************************************************/
int Space::getID() {
	return this->spaceId;
}