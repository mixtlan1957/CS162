/*********************************************************************
** Program name: Lab4
** Author: Mario Franco-Munoz
** Date: 10/19/2017
** Description: Header file for Student class. Student class is an subclass of the person class that represents a student
** at the university. 
*********************************************************************/

#include "Person.hpp"

#ifndef STUDENT_HPP
#define STUDENT_HPP

class Student :public Person {
private:
	double GPA;
public:
	Student();
	Student(std::string nameIn, int ageIn, double gpaIn);
	virtual void do_work() override;
	//student sepecific set/get functions
	void setGPA(double);
	double getGPA();

	virtual ~Student() {

	}

};


#endif

