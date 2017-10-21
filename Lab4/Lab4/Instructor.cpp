/*********************************************************************
** Program name: Lab4
** Author: Mario Franco-Munoz
** Date: 10/19/2017
** Description: Source file for Instructor class. Instructor class is an subclass of the person class that represents an instructor
** at the university.
*********************************************************************/

#include "Instructor.hpp"



//default constructor
Instructor::Instructor() :Person() {
	this->rating = 0.0;
}


//initialized constructor
Instructor::Instructor(std::string nameIn, int ageIn, double ratingIn) {
	this->name = nameIn;
	this->age = ageIn;
	this->rating = ratingIn;
}

//(=) operator overload
Instructor& Instructor::operator=(Instructor *RHS) {
	if (this != RHS) {
		this->name = RHS->name;
		this->age = RHS->age;
		this->rating = RHS->rating;
	}
	return *this;
}



/*********************************************************************
** Description: Instructor version of the "do_work"function. This function associates hours output from the base class
** do work function with hours spent grading papers by an instructor.
*********************************************************************/
void Instructor::do_work() {
	std::cout << this->name << " graded papers for ";
	Person::do_work();
	std::cout << "." << std::endl;
}

/*********************************************************************
** Description: Instructor specific function to set the rating of an instructor
*********************************************************************/
void Instructor::setRating(double ratingIn) {
	this->rating = ratingIn;
}

/*********************************************************************
** Description: Instructor specific function to get the rating of an instructor
*********************************************************************/
double Instructor::getRating() {
	return this->rating;
}


