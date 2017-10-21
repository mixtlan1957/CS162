/*********************************************************************
** Program name: Lab4
** Author: Mario Franco-Munoz
** Date: 10/19/2017
** Description: Source file for Student class. Student class is an subclass of the person class that represents a student
** at the university. 
*********************************************************************/

#include "Student.hpp"


//default constructor
Student::Student():Person() {
	this->GPA = 0.0;
}

//initialized constructor
Student::Student(std::string nameIn, int ageIn, double gpaIn) {
	this->name = nameIn;
	this->age = ageIn;
	this->GPA = gpaIn;
}

/*********************************************************************
** Description: Student version of the "do_work"function. This function associates hours output from the base class
** do work function with homework done by a student.
*********************************************************************/
void Student::do_work() {
	std::cout << this->name << " did ";
	Person::do_work(); 
	std::cout << " of homework." << std::endl;
}

/*********************************************************************
** Description: Setter function for the GPA of a student.
*********************************************************************/
void Student::setGPA(double gpaIn) {
	this->GPA = gpaIn;
}

/*********************************************************************
** Description: Get function for the GPA of a student. returns the GPA of a student object.
*********************************************************************/
double Student::getGPA() {
	return this->GPA;
}
