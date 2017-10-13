/*********************************************************************
** Program name: Lab3
** Author: Mario Franco-Munoz
** Date: 10/12/2017
** Description: Header file for Die class.
** Die class represents a N-faced die. Where the number of faces is determined by the user.
** Contains a function to return a random result based on the c++ library rand() function.
*********************************************************************/

#include <ctime>
#include <cstdlib>

#ifndef DIE_HPP
#define DIE_HPP

class Die {
private:
	
public:
	Die();
	Die(int);
	int rollTheDie(int, int);
	void setSides(int);

	virtual ~Die() {

	}

protected:
	int numberSides;
};

#endif
