/*********************************************************************
** Program name: Lab2
** Author: Mario Franco-Munoz
** Date: 10/6/2017
** Description: This function takes a ifstream object by reference and counts how many of each character (a-z capitals
** and lower case) and updates the array that stores these values (the second parameter).
*********************************************************************/

#include "count_letters.hpp"

void count_letters(std::ifstream &ifsIn, int *alphArrIn) {
	char ch;

	//search paragraph and count the letters
	ch = ifsIn.get();
	while (ch != '\n' && ch != EOF) {
		

		//use isalpha to check if character is a letter, if so make lowercase using tolower
		//tally the result (97-122 ascii range for lower case letters)
		if (isalpha(ch)) {
			ch = towlower(ch);
			alphArrIn[ch - 97]++;
		}
		ch = ifsIn.get();
	}


}