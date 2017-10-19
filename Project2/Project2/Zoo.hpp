/*********************************************************************
** Program name: Project 3 (Zoo Tycoon)
** Author: Mario Franco-Munoz
** Date: 10/13/2017
** Description: Header file for Zoo class.
**"Zoo class is the main working component of the virtual zoo game. First game is initialized with the gameInit
** function where user is prompted to enter how many animals to begin with the user will have. After which randEvent produces
** a random event: illness, birth of animals, bonus. After the random element phase, the user is provided a summary of the present
** round and asks if they would like to play again."
*********************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>

//functions
#include "Integer_Input_Val.hpp"
#include "randomNumGen.hpp"


//classes
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"


#ifndef ZOO_HPP
#define ZOO_HPP

class Zoo {
private:
	const int START_CAP = 10;
	bool userAnimalActive = false;
	std::string uAnimalName;

	Tiger **tigerPen = nullptr;		
	int tigerCount;
	int tigerPenSize;

	Penguin **penguinPen = nullptr;
	int penguinCount;
	int penguinPenSize;

	Turtle **turtlePen = nullptr;
	int turtleCount;
	int turtlePenSize;

	double acctBalance;
	int roundCounter;


public:
	Zoo();
	//event sequencing functions
	void gameInit();
	void startOfDay();
	void randEvent();
	void gameLoop();

	//functional aspects of game
	void expandPen(int, int);
	void profitCalc();
	void gameSummary();
	std::string msgReader(std::string); //EC#2
	

	//destructor
	~Zoo() {
		for (int i = 0; i < tigerPenSize; i++) {
			delete tigerPen[i];
		}
		delete[] tigerPen;

		for (int i = 0; i < penguinPenSize; i++) {
			delete penguinPen[i];
		}
		delete[] penguinPen;
		
		for (int i = 0; i < turtlePenSize; i++) {
			delete turtlePen[i];
		}
		delete[] turtlePen;

	}

};
#endif
