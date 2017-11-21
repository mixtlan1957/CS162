/*********************************************************************
** Program name: Lab 9
** Author: Mario Franco-Munoz
** Date: 11/20/2017
** Description: 
*********************************************************************/


#include "Containers.hpp"
//default constructor
Containers::Containers() {
	bufferInput = 0;
	addChance = 0;
	remChance = 0;
	rounds_buffer = 0;
}


/*********************************************************************
** Description: menu provides an interface for the user to select which function needs
** to be run. (buffer simulation or palindrome generator).
*********************************************************************/
void Containers::menu() {
	float choice;				//float varaiable for input validation
	int status;					//status flag for input validation
	int error;					//error count for input validation
	std::string palindromeString;

	//display introduction/starting intstructions
	std::cout << "Welcome to Lab9: Buffer simulation and Palindrome Creator." << std::endl;

	do {
		error = 0;
		do {
			if (error > 0) {
				std::cout << "Invalid input entered. Please enter a \"1\" to start the Buffer Simulation or ";
				std::cout << "\"2\" to start the palindrome creator segment or \"3\" to exit. \n" << std::endl;
			}
			error++;
			//prompt the user to initiate either the buffer or palindrome
			std::cout << "Please select one of the following:" << std::endl;
			std::cout << "Enter \"1\" to start the Buffer Simulation." << std::endl;
			std::cout << "Enter \"2\" to start the Palindrome generator." << std::endl;
			std::cout << "Enter \"3\" to exit program." << std::endl;
			
		} while ((status = getInt(&choice) != 0) || choice < 1 || choice > 3);

		//buffersim
		if (static_cast<int>(choice) == 1) {
			bufferSim();
		}
		//palindrome
		else if (static_cast<int>(choice) == 2) {
			palindromeString = palindrome();
			//display palindrome
			std::cout << palindromeString;
			std::cout << "\n" << std::endl;
		}
		//exit case
		else {
			std::cout << "Program will now exit." << std::endl;
		}
	} while (choice != 3);
}

/*********************************************************************
** Description: bufferSim simulates a buffer using an STL queue. User designates how many
** rounds that the simulation will be run for as well as designating the probability for an
** element to be added to the queue ("buffer") as well as designating the probability for
** an element to be removed from the queue/buffer.
*********************************************************************/
void Containers::bufferSim() {
	
	float choice;				//float varaiable for input validation
	int status;					//status flag for input validation
	int error;					//error count for input validation
	int N;						//generated random number to be potentially added to queue
	double length = 0;			//for average length calculation
	double avg_length = 0;		//for average length calculation
	double prev_length = 0;		//for average length calculation, initialized at 0 - base case
	int row_count = 0;			//row counter for output formatting
	int count = 0;				//general counter - to keep track of current round
	

	//prompt the user to chose how many rounds of the buffer simulation will be run
	//and validate the user's input
	error = 0;
	do {
		std::cout << "Please enter the number of rounds for the buffer simulation to run for. [1 - 100]" << std::endl;

		if (error > 0) {
			std::cout << "Invalid input." << std::endl;
		}
		error++;
	} while ((status = getInt(&choice) != 0) || choice < 1 || choice > 100 );
	rounds_buffer = static_cast<int>(choice);

	//prompt user to enter the % chance of adding a randomly generated number at the end of the buffer
	error = 0;
	do {
		if (error > 0) {
			std::cout << "Invalid input.\n" << std::endl;
		}
		error++;
		std::cout << "Enter the % chance of a random number being added to the queue (end of buffer).\n ";
		std::cout << "(Enter selection as integer between 0 and 100)." << std::endl;
	} while ((status = getInt(&choice) != 0) || choice < 0 || choice > 100);
	addChance = static_cast<int>(choice);

	// prompt user to enter the % chance of removing a randomly generated number from the front end of the buffer
	error = 0;
	do {
		if (error > 0) {
			std::cout << "Invalid input." << std::endl;
		}
		error++;
		std::cout << "Enter the % chance of a random number being removed from the queue (start of buffer).\n ";
		std::cout << "(Enter selection as integer between 0 and 100)." << std::endl;
	} while ((status = getInt(&choice) != 0) || choice < 0 || choice > 100);
	remChance = static_cast<int>(choice);



	//buffer round do-while loop
	do {

		//reset length and row count
		row_count = 0;

		//increment current round counter
		count++;

		//display round
		std::cout << "******Round " << count << " *******" << std::endl;

		//1) Generate a random number 1-1000
		N = randNoGen(1, 1000);

		//2) Append a number (if conditions are met)
		if (randNoGen(1, 100) <= addChance) {
			buffer.push(N);
			std::cout << N << " was appended to the buffer!" << std::endl;
		}
		else {
			std::cout << "No value added this round!" << std::endl;
		}

		//3)Remove a number (if conditions are met)
		if (randNoGen(1, 100) <= remChance) {
			if (buffer.empty() != true) {
				std::cout << buffer.front() << " will be removed from the buffer!" << std::endl;
				buffer.pop();
			}
			else {
				std::cout << "A value was going to be removed... " << std::endl;
				std::cout << "But there are no values to remove!!!" << std::endl;
			}
		}
		else {
			std::cout << "No value removed this round!" << std::endl;
		}

		//4) Output the values in the buffer, and then output the length of the buffer
		std::queue<int> temp = buffer;

		std::cout << "Contents of buffer: " << std::endl;
		while (temp.empty() != true) {
			std::cout << temp.front() << " ";
			temp.pop();

			//conditional return statement
			if (row_count >= 10) {
				std::cout << "\n";
				row_count = 0;
			}

			row_count++;
		}
		std::cout << "\n" << std::endl;
		std::cout << "Length of buffer this round: " << buffer.size() << std::endl;
		length = buffer.size();


		//5) Output the average length of buffer
		avg_length = (prev_length*(count - 1) + length) / count;
		prev_length = length;

		std::cout << "The average length of the buffer this round is: ";
		std::cout << std::fixed << std::showpoint << std::setprecision(2) << avg_length << std::endl;
		std::cout << "\n";


		//decrement rounds_buffer counter
		rounds_buffer--;

	} while (rounds_buffer > 0);

	//empty the buffer in case the sim is run again.
	while (buffer.empty() != true) {
		buffer.pop();
	}

}

/*********************************************************************
** Description: palindrome takes a user input string and loads in the characters into
** an STL stack. Contents of stack are then displayed (string in reverse order)
*********************************************************************/
std::string Containers::palindrome() {
	std::string inputString;			//user input string
	int error;

	error = 0;
	do {
		if (error > 0) {
			std::cout << "Invalid input! Please enter a string at least 2 characters in length." << std::endl;
		}

		//prompt user to enter a string
		std::cout << "Welcome to the palindrome function. Please enter a string followed by the enter key." << std::endl;
		std::cout << "String must be at least one character in length." << std::endl;
		getline(std::cin, inputString);
		error++;
	} while (inputString.length() < 1);


	//load string into stack
	for (unsigned i = 0; i < inputString.length(); i++) {
		pali.push(inputString.at(i));
	}

	//output string reversed
	std::cout << "Palindrome output:" << std::endl;

	//empty the stack while printing contents (mirror image)
	while (pali.empty() != true) {
		inputString.push_back(pali.top());
		pali.pop();
	}

	//return palindrome
	return inputString;
}