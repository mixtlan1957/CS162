/*********************************************************************
** Program name: Lab4
** Author: Mario Franco-Munoz
** Date: 10/19/2017
** Description: Header file for Instructor class. Instructor class is an subclass of the person class that represents an instructor
** at the university. 
*********************************************************************/

#include "Person.hpp"

#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

class Instructor :public Person {
private:
	double rating;

public:
	Instructor();
	Instructor(std::string nameIn, int ageIn, double ratingIn);

	Instructor& operator=(Instructor *RHS);



	virtual void do_work() override;
	void setRating(double);
	double getRating();

	virtual ~Instructor() {

	}


};

#endif