/*********************************************************************
** Program name: Lab 9
** Author: Mario Franco-Munoz
** Date: 11/20/2017
** Description:
*********************************************************************/


#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <iomanip>
#include <string>

#include "randNoGen.hpp"
#include "Integer_Input_Val.hpp"

class Containers {
private:
	std::queue <int> buffer;
	std::stack <char> pali;

	int bufferInput;			//random number to be generated between 1 - 1000 (N)
	int addChance;				//User input, chance of appending numbers to the queue.
	int remChance;				//User input, chance of removing numbers from the queue.
	int rounds_buffer;			//user input, number of rounds that will be simulated

public:
	Containers();

	void menu();
	void bufferSim();
	std::string palindrome();
	


};
