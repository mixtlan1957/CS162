/*********************************************************************
** Program name: Lab4
** Author: Mario Franco-Munoz
** Date: 10/19/2017
** Description: Header file for person class. Person class represents a given person at a university (specific to this program
** the university in question is Oregon State University). It is the parent class of subclasses Person and Faculty.
** This base class contains a given person's name and a function to generate a random number of hours worked. (Between 20 and 90).
*********************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

#ifndef PERSON_HPP
#define PERSON_HPP

class Person {
protected:
	std::string name;
	int age;


public:
	Person();
	virtual void do_work();

	void setName(std::string);
	std::string getName();
	void setAge(int age);
	int getAge();

	virtual ~Person() {

	}


};

#endif