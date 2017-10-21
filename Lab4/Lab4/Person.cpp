/*********************************************************************
** Program name: Lab4
** Author: Mario Franco-Munoz
** Date: 10/19/2017
** Description:Source file for person class. Person class represents a given person at a university (specific to this program
** the university in question is Oregon State University). It is the parent class of subclasses Person and Faculty.
** This base class contains a given person's name and a function to generate a random number of hours worked. (Between 20 and 90).
*********************************************************************/

#include "Person.hpp"

//default constructor
Person::Person() {
	name = "";
	age = 0;
}

/*********************************************************************
** Description: virtual function do_work generates a random number of hours worked between 20 and 90 hrs.
** This function is based on the example provided in C++ Early Objects 9ed Gaddis.
*********************************************************************/
void Person::do_work() {
	unsigned output;
	unsigned maxHrs = 90;
	unsigned minHrs = 20;
	unsigned seed;
	seed = time(0);
	srand(seed);

	output = (rand() % (maxHrs - minHrs + 1)) + minHrs;
	std::cout << output << " hours";
}

/*********************************************************************
** Description: returns the age of the individual (student or instructor especifically for this program)
*********************************************************************/
int Person::getAge() {
	return this->age;
}

/*********************************************************************
** Description: sets the age of the individual (student or instructor especifically for this program)
*********************************************************************/
void Person::setAge(int ageIn) {
	this->age = ageIn;
}

/*********************************************************************
** Description: returns the name of the individual (student or instructor especifically for this program)
*********************************************************************/
std::string Person::getName() {
	return this->name;
}

/*********************************************************************
** Description: sets the name of the individual (student or instructor especifically for this program)
*********************************************************************/
void Person::setName(std::string nameIn) {
	this->name = nameIn;
}


