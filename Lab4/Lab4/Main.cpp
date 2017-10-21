/*********************************************************************
** Program name: Lab4
** Author: Mario Franco-Munoz
** Date: 10/19/2017
** Description: Main source file for the "Oregon State University" simulator. 
** "Program is a simple representation of an Oregon State information system 
** that contains information about the university."
*********************************************************************/

#include "University.hpp"

int main() {
	University instance;

	instance.readData();
	instance.simLoop();

	return 0;
}