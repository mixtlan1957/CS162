/*********************************************************************
** Program name: Project 3 (Zoo Tycoon)
** Author: Mario Franco-Munoz
** Date: 10/13/2017
** Description: Header file for Penguin class. 
** "Subclass of the Animal class. In this particular case, this subclass represents
** a penguin in the virtual zoo."
*********************************************************************/

#include "Animal.hpp"

#ifndef PENGUIN_HPP
#define PENGUIN_HPP

class Penguin :public Animal {
private:
public:
	//default contsructor
	Penguin();

	//constructor
	Penguin(int);

	//move operator
	Penguin& operator=(const Penguin &RHS);

	virtual ~Penguin() {
		
	}


};
#endif