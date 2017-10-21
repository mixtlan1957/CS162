/*********************************************************************
** Program name: Lab4
** Author: Mario Franco-Munoz
** Date: 10/19/2017
** Description: Header file for University class. As part of "Oregon State University" sulation, this class
** represents the university as a whole with instructors and buildings being part of the university.
** Information about the different buildings, students and instructors is accessed through text files.
*********************************************************************/

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

//class headers
#include "Person.hpp"
#include "Student.hpp"
#include "Instructor.hpp"
#include "Building.hpp"

//function headers
#include "Integer_Input_Val.hpp"
#include "messageReader.hpp"
#include "simpleStringSearch.hpp"
#include "float_Input_Val.hpp"

#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

class University {
private:
	const int ARR_STRT_SZ = 10;

	std::string const name = "Oregon State University";
	
	Student **studentRoster = nullptr;
	int sRosterSize;
	int studentCount;
	
	Instructor **instRoster = nullptr;
	int iRosterSize;
	int instrCount;
	
	Building **bld_roster = nullptr;
	int bldRosterSize;
	int bldCount;

	bool exitBool;

public:
	University();

	//instantiate person and building objects
	void readData();
	void writeData();
	void menu();
	void workSelect();
	void simLoop();

	//function for adding dynamically alocated objects (private data members)
	void addStudents();
	void addInstructors();
	
	int getValStr(std::string *);



	~University() {
		for (int i = 0; i < studentCount; i++) {
			delete studentRoster[i];
		}
		delete[] studentRoster;

		for (int i = 0; i < instrCount; i++) {
			delete instRoster[i];
		}
		delete[] instRoster;
		for (int i = 0; i < bldCount; i++) {
			delete bld_roster[i];
		}
		delete[] bld_roster;
	}
};

#endif