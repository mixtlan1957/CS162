/*********************************************************************
** Program name: Lab4
** Author: Mario Franco-Munoz
** Date: 10/19/2017
** Description: Source file for University class. As part of "Oregon State University" sulation, this class
** represents the university as a whole with instructors and buildings being part of the university.
** Information about the different buildings, students and instructors is accessed through text files.
*********************************************************************/

#include "University.hpp"

//default constructor
University::University() {
	studentRoster = new Student*[ARR_STRT_SZ];
	instRoster = new Instructor*[ARR_STRT_SZ];
	bld_roster = new Building*[ARR_STRT_SZ];
	
	sRosterSize = ARR_STRT_SZ;
	studentCount = 0;
	
	iRosterSize = ARR_STRT_SZ;
	instrCount = 0;
	
	bldRosterSize = ARR_STRT_SZ;
	bldCount = 0;
}

/*********************************************************************
** Description: readData reads students instructors and buildings and their respective information from a text file and 
** initializes the Person and Building arrays of pointers.
*********************************************************************/
void University::readData() {
	int count = 0;			//while loop counter
	int intInput = 0;
	double dblInput = 0.0;
	std::string search;			//variable for searching by Student
	std::string temp;			//variable used for capturing search results within a line search (e.g. searching for GPA)
	std::string iFname;			//file name
	std::string lineRead;		//where line read from txt file is stored for additional subsearching/processing
	std::stringstream ss;		//string stream used to convert strings into doubles and integers where necessary
	Person **tempXfer = nullptr;
	int prev;					//placeholder variable for changing array sizes
	
	
	
	//read through students text file
	iFname = "Students.txt";
	std::ifstream ifs(iFname, std::ios::in);
	if (!ifs) {
		std::cout << "Error opening file." << std::endl;
	}
	getline(ifs, lineRead);
	studentCount = 0; //reset instructor count for re-read
	while (!ifs.fail()) {
		
		//adds students to dynamic array of student object pointers
		addStudents();

		//find and set name
		temp = stringSearch(lineRead, "#Name");
		studentRoster[count]->setName(temp);

		//find and set GPA
		temp = stringSearch(lineRead, "#GPA");
		ss << temp;
		if (!(ss >> dblInput)) {
			dblInput = 9.9;							//error value
		}
		studentRoster[count]->setGPA(dblInput);
		ss.clear();

		//find and set Age
		temp = stringSearch(lineRead, "#Age");
		ss << temp;
		if (!(ss >> intInput)) {				//This line of code is based on information provided on cplusplus.com
			intInput = 999999;
		}
		studentRoster[count]->setAge(intInput);
		ss.clear();
		count++;
		getline(ifs, lineRead);
	}
	ifs.close();

	//read through instructor txt file
	count = 0;				//don't be irresponsible, reset the counter.
	iFname = "Instructors.txt";
	ifs.open(iFname);
	if (!ifs) {
		std::cout << "Error opening file." << std::endl;
	}
	getline(ifs, lineRead);
	instrCount = 0; //reset instructor count for re-read
	while (!ifs.fail()) {
		
		addInstructors();

		//find and set name
		temp = stringSearch(lineRead, "#Name");
		instRoster[count]->setName(temp);

		//find and set Rating
		temp = stringSearch(lineRead, "#Rating");
		ss << temp;
		if (!(ss >> dblInput)) {
			dblInput = 9.9;							//error value
		}
		instRoster[count]->setRating(dblInput);
		ss.clear();

		//find and set Age
		temp = stringSearch(lineRead, "#Age");
		ss << temp;
		if (!(ss >> intInput)) {				//This line of code is based on information provided on cplusplus.com
			intInput = 999999;
		}
		instRoster[count]->setAge(intInput);
		ss.clear();
		count++;
		getline(ifs, lineRead);
	}
	ifs.close();

	
	//read through buildings txt file
	count = 0;
	iFname = "Buildings.txt";
	ifs.open(iFname);
	if (!ifs) {
		std::cout << "Error opening file." << std::endl;
	}
	getline(ifs, lineRead);
	bldCount = 0; //reset bld count for re read
	while (!ifs.fail()) {
		bldCount++;
		
		//if array is too small, double the size of the array
		if (bldCount > bldRosterSize) {
			prev = bldRosterSize;
			bldRosterSize *= 2;
			Building **tempXfer = new Building*[bldRosterSize];
			//first move prev contents
			for (int i = 0; i < prev; i++) {
				tempXfer[i] = new Building;
				tempXfer[i] = bld_roster[i];
			}
			
			tempXfer[count] = new Building;

			//deallocate memory
			delete[] bld_roster;

			//transfer pointers
			bld_roster = tempXfer;

		}
		else {
			bld_roster[count] = new Building;
		}
		

		//find and set name
		temp = stringSearch(lineRead, "#Name");
		bld_roster[count]->setName(temp);

		//find and set square footage
		temp = stringSearch(lineRead, "#Sqft");
		ss << temp;
		if (!(ss >> intInput)) {
			intInput = 9999999;							//error value
		}
		bld_roster[count]->setSize(intInput);
		ss.clear();

		//find and set address
		temp = stringSearch(lineRead, "#Address");
		bld_roster[count]->setAddress(temp);
		ss.clear();
		count++;
		getline(ifs, lineRead);
	}
	ifs.close();
}


/*********************************************************************
** Description: menu function displays options to user. User can select to print information abouty buildings, people 
** at the university, chose someone to do work, add a building/person, or exit the program.
*********************************************************************/
void University::menu() {
	float choice;
	int status;
	int errorCounter = 0;
	
	//Introduction
	std::cout << "Welcome to the " << name << " simulation!" << std::endl;
	do {
		if (errorCounter > 1) {
			std::cout << "Invalid selection. Please enter a valid menu selection." << std::endl;
		}
		std::cout << " To begin, please enter one of the following options: " << std::endl;
		std::cout << "1.	Print information about all the buildings." << std::endl;
		std::cout << "2.	Print information of everybody at the university." << std::endl;
		std::cout << "3.	Chose a person to do work." << std::endl;
		std::cout << "4.    Exit the program" << std::endl;
		std::cout << "***EC OPTIONS:***" << std::endl;
		std::cout << "5.	Add a student or instructor." << std::endl;
		errorCounter++;
	} while (((status = getInt(&choice)) != 0) || choice > 6 || choice < 1);
	errorCounter = 0;

	switch (static_cast<int>(choice)) {
	case 1: //output building information
		std::cout << "***BUILDING INFO***" << std::endl;
		for (int i = 0; i < bldCount; i++) {
			std::cout << bld_roster[i]->getName() << std::endl;
			std::cout << "Gross sqft: " << bld_roster[i]->getSize() << std::endl;
			std::cout << "Address: " << bld_roster[i]->getAddress() << "\n" << std::endl;
		}
		std::cout << "\n" << std::endl;

		break;
	case 2: //output student and instructor information
		std::cout << "***STUDENTS***" << std::endl;
		for (int i = 0; i < studentCount; i++) {
			std::cout << studentRoster[i]->getName() << std::endl;
			std::cout << "Age: " << studentRoster[i]->getAge() << std::endl;
			std::cout << "GPA: " <<std::fixed <<std::showpoint << std::setprecision(1) 
				<< studentRoster[i]->getGPA() << "\n" << std::endl;
		}
		std::cout << "***INSTRUCTORS***" << std::endl;
		for (int i = 0; i < instrCount; i++) {
			std::cout << instRoster[i]->getName() << std::endl;
			std::cout << "Age: " << instRoster[i]->getAge() << std::endl;
			std::cout << "Rating: " << std::fixed << std::showpoint << std::setprecision(1)
				<< instRoster[i]->getRating() << "\n" << std::endl;
		}
		std::cout << "\n" << std::endl;
		break;
	case 3: 
		workSelect();
		break;
	case 4:
		exit = true;
		break;
	case 5:
		writeData();
		break;
	default:
		break;
	}
}


/*********************************************************************
** Description: workSelect displays all the students and faculty in the University program for the user to 
** select which person he wants to have the "do_work" member function run on.
*********************************************************************/
void University::workSelect() {
	float choice;
	int status;
	int errorCounter = 0;
	int temp;

	//output students for selection
	std::cout << "***STUDENTS***" << std::endl;
	for (int i = 0; i < studentCount; i++) {
		std::cout << i + 1 << ".   " << studentRoster[i]->getName() << std::endl;
	}
	std::cout << "***INSTRUCTORS***" << std::endl;
	for (int i = studentCount; i < instrCount + studentCount; i++) {
		std::cout << i + 1 << ".   " << instRoster[i-studentCount]->getName() << std::endl;
	}

	errorCounter = 0;
	do {
		std::cout << "Please enter the number that appears by the student or ";
		std::cout <<"instructor that you wish to have do work." << std::endl;
		errorCounter++;
	} while (((status = getInt(&choice)) != 0) || (choice > (studentCount + instrCount)) || choice < 1);
	temp = static_cast<int>(choice) - 1;

	if (temp < studentCount) {
		studentRoster[temp]->do_work();
	}
	else {
		instRoster[temp-studentCount]->do_work();
	}

}

/*********************************************************************
** Description: simLoop loops the program until the user decides to enter the exit program selection.
*********************************************************************/
void University::simLoop() {
	float choice = 0;
	int status;
	int errorCounter = 0;
	
	if (exit = false) {
		do {
			menu();
			errorCounter = 0;
			do {
				if (errorCounter > 1) {
					std::cout << "Invalid selection. Please enter a valid menu selection." << std::endl;
				}
				std::cout << "Continue running program?" << std::endl;
				std::cout << "Enter 1 to continue." << std::endl;
				std::cout << "Enter 2 to exit program." << std::endl;

				errorCounter++;
			} while (((status = getInt(&choice)) != 0) || choice > 2 || choice < 1);

		} while (choice == 1);
	}
}

/*********************************************************************
** Description: writeData prompts the user to provide information on the person they wish to add to the
** appropriate text file in such a format that will allow the data to be subsequently read in future run instances.
*********************************************************************/
void University::writeData() {
	std::ofstream ofs;
	std::string input = "";
	float choice = 0;
	int status;
	int errorCounter = 0;

	
	do {
		
		errorCounter = 0;
		do {
			if (errorCounter > 1) {
				std::cout << "Invalid selection. Please enter a valid menu selection." << std::endl;
			}
			std::cout << "Add instructor or student? Please select one of the folowing:" << std::endl;
			std::cout << "1.   ADD STUDENT" << std::endl;
			std::cout << "2.   ADD INSTRUCTOR" << std::endl;
			errorCounter++;
		} while (((status = getInt(&choice)) != 0) || choice > 2 || choice < 1);
		
		
		//adding instructor or student?
		if (choice == 1) {
			ofs.open("Students.txt", std::ios::app);
			addStudents();						//call addStudents function

			//validate the user input name
			errorCounter = 0;
			do {
				std::cout << "Please enter the name of the student. (#, $ characters are not permited)." << std::endl;
				if (errorCounter > 1) {
					std::cout << "Invalid input encoutnered" << std::endl;
				}
				errorCounter++;
			} while ((status = getValStr(&input)) != 0);

			studentRoster[studentCount-1]->setName(input);

			//validate the age
			errorCounter = 0;
			do {
				std::cout << "Please enter the age of the student." << std::endl;
				if (errorCounter > 0) {
					std::cout << "Invalid entry. Please enter an age between 1 and 130" << std::endl;
				}
				errorCounter++;
			} while ((status = getInt(&choice) != 0) || choice > 130 || choice < 1);
			studentRoster[studentCount-1]->setAge(static_cast<int>(choice));


			//validate the gpa
			errorCounter = 0;
			do {
				std::cout << "Please enter the gpa of the student." << std::endl;
				if (errorCounter > 0) {
					std::cout << "Invalid entry. Please enter a gpa value between 0.0 and 4.0" << std::endl;
				}
				errorCounter++;
			} while ((status = getFloat(&choice) != 0) || choice > 4.0 || choice < 0.0);
			studentRoster[studentCount-1]->setGPA(static_cast<double>(choice));

			//write data
			ofs << "$#Name" << studentRoster[studentCount-1]->getName();
			ofs << "$#GPA" << studentRoster[studentCount-1]->getGPA();
			ofs << "$#Age" << studentRoster[studentCount-1]->getAge();
			ofs << "$" << std::endl;
			ofs.close();
		}
		
		//add instructor information if an instructor is to be added
		else  {
			ofs.open("Instructors.txt", std::ios::app);
			addInstructors();						//call add instructors function

			//recieve and validate name
			errorCounter = 0;
			do {
				std::cout << "Please enter the name of the instructor. (#, $ characters are not permited)." << std::endl;
				if (errorCounter > 1) {
					std::cout << "Invalid input encoutnered" << std::endl;
				}
				errorCounter++;
			} while ((status = getValStr(&input)) != 0);

			instRoster[instrCount- 1]->setName(input);

			//recieve and validate age
			errorCounter = 0;
			do {
				std::cout << "Please enter the age of the instructor." << std::endl;
				if (errorCounter > 0) {
					std::cout << "Invalid entry. Please enter an age between 1 and 130" << std::endl;
				}
				errorCounter++;
			} while ((status = getInt(&choice) != 0) || choice > 130 || choice < 1);
			instRoster[instrCount - 1]->setAge(static_cast<int>(choice));


			//validate the rating
			errorCounter = 0;
			do {
				std::cout << "Please enter the rating of the instructor." << std::endl;
				if (errorCounter > 0) {
					std::cout << "Invalid entry. Please enter a rating value between 0.0 and 5.0" << std::endl;
				}
				errorCounter++;
			} while ((status = getFloat(&choice) != 0) || choice > 5.0 || choice < 0.0);
			instRoster[instrCount - 1]->setRating(static_cast<double>(choice));

			//write data
			ofs << "$#Name" << instRoster[instrCount - 1]->getName();
			ofs << "$#Rating" << instRoster[instrCount - 1]->getRating();
			ofs << "$#Age" << instRoster[instrCount - 1]->getAge();
			ofs << "$" << std::endl;
			ofs.close();
		}
		
		choice = 0;
		errorCounter = 0;
		do {
			if (errorCounter > 1) {
				std::cout << "Invalid selection. Please enter a valid menu selection." << std::endl;
			}
			std::cout << "Continue adding students/instructors?" << std::endl;
			std::cout << "Enter 1 to continue." << std::endl;
			std::cout << "Enter 2 to stop adding students/instructors." << std::endl;

			errorCounter++;
		} while (((status = getInt(&choice)) != 0) || choice > 2 || choice < 1);

	} while (choice == 1);

}




/*********************************************************************
** Description: addStudent handles adding a student to its appropriate dynamic array.
** IMPORTANT: this function is specific to the case in which a new student is being added
** after the student count variable has been updated. Otherwise data will be overwritten.
** Additionally, this function is intended to be used within a loop, adding one student at a time only.
*********************************************************************/
void University::addStudents() {
	int prev;
	studentCount++;
	if (studentCount > sRosterSize) {
		prev = sRosterSize;
		sRosterSize *= 2;
		Student **tempXfer = new Student*[sRosterSize];
		
		tempXfer[studentCount - 1] = new Student;

		//move prev contents
		for (int i = 0; i < prev; i++) {
			tempXfer[i] = new Student;
			tempXfer[i] = studentRoster[i];
		}

		//deallocate memory
		delete[] studentRoster;
		//transfer pointers
		studentRoster = tempXfer;

	}
	else {
		studentRoster[studentCount-1] = new Student;
	}
}




/*********************************************************************
** Description: addInstructor handles adding a instructor to its appropriate dynamic array.
** IMPORTANT: this function is specific to the case in which a new instructor is being added
** after the instructor count variable has been updated. Otherwise data will be overwritten.
** Additionally, this function is intended to be used within a loop, adding one student at a time only.
*********************************************************************/
void University::addInstructors() {
	int prev;
	//if array is too small, double the size of the array
	instrCount++;
	if (instrCount > iRosterSize) {
		prev = iRosterSize;
		iRosterSize *= 2;
		Instructor **tempXfer = new Instructor*[iRosterSize];

		tempXfer[instrCount - 1] = new Instructor;

		//move prev contents
		for (int i = 0; i < prev; i++) {
			tempXfer[i] = new Instructor;
			tempXfer[i] = instRoster[i];
		}

		//deallocate memory

		delete[] instRoster;
		//transfer pointers

		instRoster = tempXfer;
	}
	else {
		instRoster[instrCount-1] = new Instructor;
	}
	
}


/*********************************************************************
** Description: obtains a line of input from user and checks length and filter (non-compatible characters).
*********************************************************************/
int University::getValStr(std::string *ptr) {
	int status = -1;
	std::string select;
	int lowLimit = 2;
	int highLimit = 40;
	char filter1 = '#';
	char filter2 = '$';
	int found1;
	int found2;

	std::getline(std::cin, select);
	found1 = select.find(filter1);
	found2 = select.find(filter2);
	//check for length
	if (select.length() > highLimit || select.length() < lowLimit) {
		std::cout << "Invalid input. Please enter a name at least " << lowLimit;
		std::cout << " and at most " << highLimit << " characters in length." << std::endl;
	}
	else if (found1 != std::string::npos || found2 != std::string::npos) {
		std::cout << "Invalid character used. Use of the \"" << filter1 << "\" and \""<<filter2 <<"\"" ;
			std::cout <<" are not permited!" << std::endl;
	}
	else {
		*ptr = select;
		status = 0;
	}
	return status;
}






