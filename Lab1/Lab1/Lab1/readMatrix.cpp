/*********************************************************************
** Program name: Lab1
** Author: Mario Franco-Munoz
** Date: 09/27/2017
** Description:
*********************************************************************/


#include "readMatrix.hpp"

int getInt(int *ptr);

void readMatrix(int ***arrIn, int sizeIn) {
	int status = -1;
	int choice;

	//prompt user for all numbers in the matrix and assign values
	std::cout << "Please enter the values for the matrix by row." << std::endl;

	for (int i = 0; i < sizeIn; i++) {
		for (int k = 0; k < sizeIn; k++) {
			while ((status = getInt(&choice) != 0)) {
				std::cout << "Please enter a valid integer!" << std::endl;
			}
			(*arrIn)[i][k] = choice;
		}
	}

}