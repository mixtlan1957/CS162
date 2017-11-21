/*********************************************************************
** Description: Function to generate a random number within specified range (minimum value, maximum value). 
** Stackoverflow post https://stackoverflow.com/questions/19665818/generate-random-numbers-using-c11-random-library
*********************************************************************/

#include "randNoGen.hpp"

//this function is nearly directly taken from pg 135 "C++ Early Objectes 9th ed" Gaddis
int randNoGen(int minIn, int maxIn) {


	std::random_device rand;  //"We use random_device once to seed the random number generator named 'mt'"
	std::mt19937 mt(rand()); //"random_device() is slower than mt19937, but it does not need to be seeded
							//because it requests random data from your OS" - 
	std::uniform_real_distribution<double> dist(minIn, maxIn + 1);
	return dist(mt);
}
