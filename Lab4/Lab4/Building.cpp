/*********************************************************************
** Program name: Lab4
** Author: Mario Franco-Munoz
** Date: 10/19/2017
** Description: Source file for Building class. Building class represents buildings at the Oregon State University.
** A building has an address, size in square ft and a name as data members. 
*********************************************************************/



#include "Building.hpp"

//default constructor
Building::Building() {
	this->address = "";
	this->size = 0;
	this->name = "";
}


//initialized constructor
Building::Building(std::string addressIn, int sizeIn, std::string nameIn) {
	this->address = addressIn;
	this->name;
	this->size;
}

/*********************************************************************
** Description: sets the name of a building object.
*********************************************************************/
void Building::setName(std::string nameIn) {
	this->name = nameIn;
}

/*********************************************************************
** Description: returns the name of a building object
*********************************************************************/
std::string Building::getName() {
	return this->name;
}


/*********************************************************************
** Description: sets the size (in gross square feet) of a building
*********************************************************************/
void Building::setSize(int sizeIn) {
	this->size = sizeIn;
}


/*********************************************************************
** Description: returns the size (in gross square feet) of a building
*********************************************************************/
int Building::getSize() {
	return this->size;
}


/*********************************************************************
** Description: sets the address of a building
*********************************************************************/
void Building::setAddress(std::string addressIn) {
	this->address = addressIn;
}

/*********************************************************************
** Description: returns the address of a building as a single string.
*********************************************************************/
std::string Building::getAddress() {
	return this->address;
}
