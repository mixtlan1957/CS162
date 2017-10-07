/*********************************************************************
** Program name: Lab2
** Author: Mario Franco-Munoz
** Date: 10/6/2017
** Description: File outputs tally/count of how many times a letter appeared in a paragraph of the input file.
*********************************************************************/


#include "output_letters.hpp"

void output_letters(std::ofstream &ofFileIn, int *alphArrIn) {
	const int ENGLISH_ALPHABET = 26;
	char letter;

	//fWrite results to output file
	for (int i = 0; i < ENGLISH_ALPHABET; i++) {
		letter = 97 + i;
		ofFileIn << letter << ": " << alphArrIn[i] << "\n" << std::endl;
	}
}
