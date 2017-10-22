/*********************************************************************
** Program name: Lab4
** Author: Mario Franco-Munoz
** Date: 10/19/2017
** Description: Header file for Building class. Building class represents buildings at the Oregon State University.
** A building has an address, size in square ft and a name as data members. 
*********************************************************************/

#include <string>


#ifndef BUILDING_HPP
#define BUILDING_HPP

class Building {
private:
	std::string name;
	int size;
	std::string address;

public:
	Building();
	Building(std::string, int, std::string);

	Building& operator=(Building *);

	//accessors and mutators
	void setName(std::string);
	std::string getName();
	void setSize(int);
	int getSize();
	void setAddress(std::string);
	std::string getAddress();




};

#endif




