/*********************************************************************
** Program name: Project 3 (Zoo Tycoon)
** Author: Mario Franco-Munoz
** Date: 10/13/2017
** Description: Header file for the Tiger class an Animal subclass.
** "Subclass of the Animal class. In this particular case, this subclass represents
** a tiger in the virtual zoo.
*********************************************************************/

#include "Animal.hpp"

#ifndef TIGER_HPP
#define TIGER_HPP

class Tiger :public Animal {
private:
public:
	//default contsructor
	Tiger();
	
	//constructor
	Tiger(int);

	//assignment operator
	Tiger& operator=(const Tiger &RHS);


	virtual ~Tiger() {
	
	}

};

#endif 

