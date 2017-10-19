/*********************************************************************
** Program name: Project 3 (Zoo Tycoon)
** Author: Mario Franco-Munoz
** Date: 10/13/2017
** Description: Header file for turtle animal subclass. 
** "Subclass of the Animal class. In this particular case, this subclass represents
** a turtle in the virtual zoo."
*********************************************************************/


#include "Animal.hpp"

#ifndef TURTLE_HPP
#define TURTLE_HPP

class Turtle :public Animal {
private:
public:
	//default contsructor
	Turtle();

	//constructor
	Turtle(int);

	Turtle& operator=(Turtle &RHS);

	virtual ~Turtle(){
		
	}


};
#endif
