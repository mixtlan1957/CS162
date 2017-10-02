/*********************************************************************
** Program name: Project 1 (Langton's Ant)
** Author: Mario Franco-Munoz
** Date: 09/28/2017
** Description: Ant.cpp, source code for Ant class contains the functional parts of the Langton Ant simulation.
** Starting with a function (inputPrompt) to prompt the user to enter the parameters for the simulation. 
** After witch a function (initBoard) takes the parameters entered by the user and initializes a dynamic 2D array.
** Third key function moveTheAnt and printBoard provide the main functionality by simulating the steps the ant makes
** and outputing it to the command prompt window.
*********************************************************************/

#include "Ant.hpp"


//default constructor
Ant::Ant() {
	//default rows and columns
	rows = 2;
	cols = 2;

	//initialize remaining variables
	antLocationRow = 1;
	antLocationCol = 1;
	antOrient = 'n';
	int stepCount = 0;
}

/*********************************************************************
** Description: Initializes game board after user variables are provided.
*********************************************************************/
void Ant::initBoard() {

	//initialize board
	board = new char*[rows + 2];
	for (int i = 0; i < rows + 2; i++) {
		board[i] = new char[cols + 2];
	}

	//borders
	//top and bottom border
	for (int i = 0; i < cols + 2; i++) {
		board[0][i] = '-';
		board[rows + 1][i] = '-';
	}

	//side boarders
	for (int i = 0; i < rows; i++) {
		board[i + 1][0] = '|';
		board[i + 1][cols + 1] = '|';
	}

	//active game board area
	for (int i = 1; i < rows +1; i++) {
		for (int k = 1; k < cols +1; k++) {
			board[i][k] = ' ';
		}
	}
}



/*********************************************************************
** Description: Prints board output. White spaces denoted by the space character. Black spaces by the '#' character.
*********************************************************************/
void Ant::printBoard() {
	char reset = board[antLocationRow][antLocationCol];
	board[antLocationRow][antLocationCol] = '*';

	for (int i = 0; i < rows + 2; i++) {
		for (int k = 0; k < cols + 2; k++) {
			std::cout << board[i][k];
		}
		std::cout << std::endl;
	}
	
	//retain the color of the square in which the ant resides
	board[antLocationRow][antLocationCol] = reset;
}

/*********************************************************************
** Description: Runs Langton's Ant simulation for defined number of steps.
*********************************************************************/
void Ant::moveTheAnt() {
	bool moved = false;
	//general move statement
	if (board[antLocationRow][antLocationCol] == ' ') {
			
		//if pointing north
		if (antOrient == 'n' && moved == false) {
			if (board[antLocationRow][antLocationCol + 1] == '|') {		//wrap to other side if at edge
				board[antLocationRow][antLocationCol] = '#';
				antLocationCol = 1;
				antOrient = 'e';
				moved = true;
			}
			else {
				//flip color of square
				board[antLocationRow][antLocationCol] = '#';
				//turn 90deg
				antOrient = 'e';
				//move forward one unit
				antLocationCol++;
				moved = true;
			}
		}

		//if pointing east
		if (antOrient == 'e' && moved == false) {
			if (board[antLocationRow + 1][antLocationCol] == '-') {
				board[antLocationRow][antLocationCol] = '#';
				antLocationRow = 1;
				antOrient = 's';
				moved = true;
			}
			else  {
				board[antLocationRow][antLocationCol] = '#';
				antLocationRow++;
				antOrient = 's';
				moved = true;
			}
		}

			//if pointing south
		if (antOrient == 's' && moved == false) {
			if (board[antLocationRow][antLocationCol - 1] == '|') {
				board[antLocationRow][antLocationCol] = '#';
				antLocationCol = cols;
				antOrient = 'w';
				moved = true;
			}
			else {
				board[antLocationRow][antLocationCol] = '#';
				antOrient = 'w';
				antLocationCol--;
				moved = true;
			}
		}

			//if pointing west
		if (antOrient == 'w' && moved == false) {
			if (board[antLocationRow - 1][antLocationCol] == '-') {
				board[antLocationRow][antLocationCol] = '#';
				antLocationCol = rows;
				antOrient = 'n';
				moved = true;
			}
			else {
				board[antLocationRow][antLocationCol] = '#';
				antOrient = 'n';
				antLocationRow--;
				moved = true;
			}
		}
	}

	else if (board[antLocationRow][antLocationCol] == '#') {
		//if pointing south
		if (antOrient == 's' && moved == false) {
			if (board[antLocationRow][antLocationCol + 1] == '|') {		//wrap to other side if at edge
				board[antLocationRow][antLocationCol] = ' ';
				antLocationCol = 1;
				antOrient = 'e';
				moved = true;
			}
			else {
				//flip color of square
				board[antLocationRow][antLocationCol] = ' ';
				//turn 90deg
				antOrient = 'e';
				//move forward one unit
				antLocationCol++;
				moved = true;
			}
		}

		//if pointing west
		if (antOrient == 'w' && moved == false) {
			if (board[antLocationRow + 1][antLocationCol] == '-') {
				board[antLocationRow][antLocationCol] = ' ';
				antLocationRow = 1;
				antOrient = 's';
				moved = true;
			}
			else {
				board[antLocationRow][antLocationCol] = ' ';
				antLocationRow++;
				antOrient = 's';
				moved = true;
			}
		}

		//if pointing north
		if (antOrient == 'n' && moved == false) {
			if (board[antLocationRow][antLocationCol - 1] == '|') {
				board[antLocationRow][antLocationCol] = ' ';
				antLocationCol = cols;
				antOrient = 'w';
				moved = true;
			}
			else {
				board[antLocationRow][antLocationCol] = ' ';
				antOrient = 'w';
				antLocationCol--;
				moved = true;
			}
		}

		//if pointing east
		if (antOrient == 'e' && moved == false) {
			if (board[antLocationRow - 1][antLocationCol] == '-') {
				board[antLocationRow][antLocationCol] = ' ';
				antLocationCol = rows;
				antOrient = 'n';
				moved = true;
			}
			else {
				board[antLocationRow][antLocationCol] = ' ';
				antOrient = 'n';
				antLocationRow--;
				moved = true;
			}
		}
		
	}
	moved = false;
}

/*********************************************************************
** Description: Asks user to proivde input depending on mode selected.
*********************************************************************/
void Ant::inputPrompt(int selectionIn) {
	int status;
	int choice;
	if (selectionIn == 1) {
		//rows
		std::cout << std::left << std::setw(50);
		std::cout << "Enter number of rows for the board:";
		while ((status = getInt(&choice)) != 0 || choice < 2 || choice > 100) {
			std::cout << "Please enter a single positive integer greater than 2 and less than 100" << std::endl;
		}
		setRows(choice);

		//columns
		std::cout << std::left << std::setw(50);
		std::cout << "Enter number of columns for the board:";
		while ((status = getInt(&choice)) != 0 || choice < 2 || choice > 100) {
			std::cout << "Please enter a single positive integer greater than 2 and less than 100" << std::endl;
		}
		setCols(choice);

		//number of steps during sim
		std::cout << std::left << std::setw(50);
		std::cout << "Enter the number of steps during simulation:";
		while ((status = getInt(&choice)) != 0 || choice < 0) {
			std::cout << "Please enter a single positive integer." << std::endl;
		}
		setSteps(choice);

		//starting row of ant
		std::cout << std::left << std::setw(50);
		std::cout << "Starting row of the ant:";
		while ((status = getInt(&choice)) != 0 || choice < 1 || choice > rows) {
			std::cout << "Please enter a single non-negative integer within bounds of board." << std::endl;
		}
		setAntY(choice);

		//starting column of ant
		std::cout << std::left << std::setw(50);
		std::cout << "Starting column of the ant:";
		while ((status = getInt(&choice)) != 0 || choice < 1 || choice > cols) {
			std::cout << "Please enter a single non-negative integer less than 100." << std::endl;
		}
		setAntX(choice);
	}
	else {
		//rows
		std::cout << std::left << std::setw(50);
		std::cout << "Enter number of rows for the board:";
		while ((status = getInt(&choice)) != 0 || choice < 2 || choice > 100) {
			std::cout << "Please enter a single integer greater than 2 and less than 100" << std::endl;
		}
		setRows(choice);

		//columns
		std::cout << std::left << std::setw(50);
		std::cout << "Enter number of columns for the board:";
		while ((status = getInt(&choice)) != 0 || choice < 2 || choice > 100) {
			std::cout << "Please enter a single integer greater than 2 and less than 100." << std::endl;
		}
		setCols(choice);

		//number of steps
		std::cout << std::left << std::setw(50);
		std::cout << "Enter the number of steps during simulation:";
		while ((status = getInt(&choice)) != 0 || choice < 0) {
			std::cout << "Please enter a single non-negative integer." << std::endl;
		}
		setSteps(choice);

		//set random starting point for ant
		antLocationCol = randNoGen(1, cols, 1);
		antLocationRow = randNoGen(1, rows, 2);

		//display random generated starting point
		std::cout << "The starting location of the ant is Row: " << antLocationRow << "; Column: " << antLocationCol << std::endl;

	}


}



/*********************************************************************
** Description: Function encapsulates the moveTheAnt and printBoard functions for ease of use in main
*********************************************************************/
void Ant::moveAndPrint() {
	printBoard();
	for (int i = 0; i < stepCount; i++) {
		moveTheAnt();
		printBoard();
	}
}


/*********************************************************************
** Description: Setter function to set the number of steps provided by the user.
*********************************************************************/
void Ant::setSteps(int stepIn) {
	stepCount = stepIn;
}

/*********************************************************************
** Description: Get function to obtain the number of steps to be run in simulation
*********************************************************************/
int Ant::getSteps() {
	return stepCount;
}

/*********************************************************************
** Description: Setter function to set the starting column location of ant.
*********************************************************************/
void Ant::setAntX(int xIn) {
	antLocationCol = xIn;
}

/*********************************************************************
** Description: Setter function to set the starting row location of ant.
*********************************************************************/
void Ant::setAntY(int yIn) {
	antLocationRow = yIn;
}

/*********************************************************************
** Description: Setter function to set the number of rows in the simulation board.
*********************************************************************/
void Ant::setRows(int rowsIn) {
	rows = rowsIn;
}

/*********************************************************************
** Description: Setter function to set the number of columns in the simulation board.
*********************************************************************/
void Ant::setCols(int colsIn) {
	cols = colsIn;
}