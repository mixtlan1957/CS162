/*********************************************************************
** Program name: Project 2 (Zoo Tycoon)
** Author: Mario Franco-Munoz
** Date: 10/13/2017
** Description: Header file for the randomNumGen function. 
** "This function takes a min and max value and returns a random number based on time generated
** seed value. Additional mode parameter serves to generate a different random number in the case that this function
** is executed subsequently." Most of this function was taken from C++ early objects by Gaddis (7e) 
*********************************************************************/

#include <ctime>
#include <cstdlib>

#ifndef RANDOMNUMGEN_HPP
#define RANDOMNUMGEN_HPP

int randomNumGen(int, int, int);

#endif 

