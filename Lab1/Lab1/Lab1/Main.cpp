/*********************************************************************
** Program name: Lab1 (Matrix Determinant Calculator)
** Author: Mario Franco-Munoz
** Date: 09/27/2017
** Description: This program asks the user to chose either a 2x2 or 3x3 matrix and then uses the readMatrix
**	function to ask and populate the values for the given matrix (4 values for a 2x2, 9 values for a 3x3).
**	The determinant function then calculates the determinant of the matrix which is subsequently displayed to user.
*********************************************************************/

#include "readMatrix.hpp"
#include "determinant.hpp"

int getInt(int *ptr);

//function for input validation based on Harlan James' basic input validation video
int getInt(int *ptr)
{
	int status = -1;
	char buffer[4096];

	if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
		std::cout << "No data read." << std::endl;
	}
	else if (sscanf(buffer, "%i", ptr) != 1) {
		std::cout << "Integer not entered. ";
	}
	else {
		status = 0;
	}
	return status;
}

int main() {
	int status;
	int choice;

	//Introduction
	std::cout << "Hello welcome to Matrix Determinant Calculator. This program will ask you to ";
	std::cout << "select either a 2x2 or 3x3 matrix\n";
	std::cout << "and then ask you to fill in the values for the matrix." << std::endl;
	std::cout << "After entering the values of the matrix, \n";
	std::cout << "the determinant of the matrix will be displayed.\n" << std::endl;

	//Prompt User to Select 2x2 or 3x3 matrix
	std::cout << "Please select the size of the matrix by entering the digit 2 or 3 followed by the enter key." << std::endl;
	while ((status = getInt(&choice) != 0) || (choice < 2 || choice > 3)) {
		std::cout << "Please enter a single integer 2 or 3 (denoting 2x2 or 3x3 matrix)." << std::endl;
	}

	//define dynamic matrix based on user selection
	int rows = choice;
	int cols = choice;
	int **arr = new int*[rows];
	for (int i = 0; i < rows; i++) {
		arr[i] = new int[cols];
	}

	//call readMatrix - will prompt the user to enter 4 or 9 integers to fill the matrix
	readMatrix(&arr, choice);

	//call determinant and display
	if (choice == 2) {
		std::cout << "You have entered a 2x2 matrix.\n The determinant is: ";
	}
	else if (choice == 3) {
		std::cout << "You have entered a 3x3 matrix.\n The determinant is: ";
	}
	std::cout << determinant(&arr, choice) << std::endl;

	//free dynamically allocated memory
	for (int i = 0; i < choice; i++) {
		delete[] arr[i];
	}
	delete[] arr;

	return 0;
}
