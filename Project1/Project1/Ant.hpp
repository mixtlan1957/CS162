/*********************************************************************
** Program name: Project 1 (Langton's Ant)
** Author: Mario Franco-Munoz
** Date: 09/28/2017
** Description: Header file for Ant class.
** Source file description:
** "Starting with a function (inputPrompt) to prompt the user to enter the parameters for the simulation. 
** After witch a function (initBoard) takes the parameters entered by the user and initializes a dynamic 2D array.
** Third key function moveTheAnt and printBoard provide the main functionality by simulating the steps the ant makes
** and outputing it to the command prompt window."
*********************************************************************/

#include "getInt.hpp"
#include "randNoGen.hpp"

#include <iostream>
#include <iomanip>

#ifndef ANT_HPP
#define ANT_HPP

class Ant {
private:
	char **board;
	int antLocationRow;
	int antLocationCol;
	char antOrient;
	int stepCount;
	int rows;
	int cols;

public:
	//constructor
	Ant();

	//member functions
	void printBoard();
	void moveTheAnt();
	void inputPrompt(int);
	void moveAndPrint();
	void initBoard();

	void setSteps(int);
	void setAntX(int);
	void setAntY(int);
	void setRows(int);
	void setCols(int);

	int getSteps();


	//destructor for memory dealloc
	~Ant() {
		for (int i = 0; i < rows+2; i++) {
			delete[] board[i];
		}
		delete[] board;
	}
};
#endif