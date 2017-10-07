/*********************************************************************
** Program name: Lab2
** Author: Mario Franco-Munoz
** Date: 10/6/2017
** Description: Header file for count_letters.cpp. "This function takes a ifstream object by reference and counts 
** how many of each character (a-z capitals and lower case) and updates the array that stores these values (the second parameter)."
*********************************************************************/

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

#ifndef COUNT_LETTERS_HPP
#define COUNT_LETTERS_HPP

void count_letters(std::ifstream &, int *);

#endif