/*********************************************************************
** Program name: Lab 7
** Author: Mario Franco-Munoz
** Date: 11/15/2017
** Description: SeachSort reads the values of three different txt files containing
** random integers and after loading the values into different
** arrays: 1) applies a simple linear search algorithm, 2) Sorts the three different arrays
** 3)Applies a binary search.
*********************************************************************/

#include <iostream>
#include <fstream>
#include <string>

#include "Integer_Input_Val.hpp"

#ifndef SEARCHSORT_HPP
#define SEARCHSORT_HPP
class SearchSort {
private:
	//pointers for dynamic arrays
	int *early;
	int *middle;
	int *end;
	int *original;

	int arrCap_early;
	int arrCap_middle;
	int arrCap_end;
	int arrCap_original;

public:
	SearchSort();

	//load arrays step
	void readFiles(std::string);
	
	//simple search step
	void simpleSearch();

	//sorting step
	void sortingMenu();

	//merge sort and associated functions
	void mergeSort(int [], int, int);
	void merge(int [], int, int, int);

	//binary search
	void binSearchPrompt();
	int binSearch(int [], int, int);
	
	//main menu/interface
	void menu();

	//input validation for output file names
	std::string getValidFileName();

	virtual ~SearchSort() {
		delete[] early;
		delete[] middle;
		delete[] end;
		delete[] original;
	}

};
#endif

