/*********************************************************************
** Program name: Lab5
** Author: Mario Franco-Munoz
** Date: 10/23/2017
** Description: Main source fil for the use of testing/executing different recursive functions
** as required for Lab 5 assignment. Function1: reverseString (outputs reverse of user input screen to I/O)
** Function2: arraySum (sums the elements of a user defined array of integers
** Function3: triangulate (returns the trangulation of a user provided number)
*********************************************************************/


//recursive function headers
#include "reverseString.hpp"
#include "arraySum.hpp"
#include "triangular.hpp"
#include "menuFunction.hpp"
#include "Integer_Input_Val.hpp"

//additional function headers
#include "menuFunction.hpp"

int main() {
	int selection;
	std::string strInput; //for reverse string input
	
	int arrLength; //for arraySum input
	int *intArr = nullptr; //for arraySum input
	
	float choice; //for user input validation
	int status;	  //for user input validation

	
	
	int test[5] = { 1,2,3,4,5 };
	std::cout << arraySum(test, 5) << std::endl;
	
	
	
	
	std::cout << "Welcome to Lab5 \n" << std::endl;
	
	do {
		selection = menuFunction();

		//**********first recursive function section (reverse string)**********************************
		if (selection == 1) {
			std::cout << "You have selected the \"reverseString\" function." << std::endl;
			std::cout << "Please enter a string: " << std::endl;
			getline(std::cin, strInput);
			reverseString(strInput);
		}

		//***********second recursive function section (arraySum)***************************************
		else if (selection == 2) {
			std::cout << "You have selected the \"arraySum\" function." << std::endl;
			
			//obtain array size from user
			status = 0;
			do {
				std::cout << "Please enter an array size (max size 50): " << std::endl;
				if (status != 0) {
					std::cout << "Invalid input. Please enter an integer between 0 and 50." << std::endl;
				}
			} while ((status = getInt(&choice)) != 0 || choice > 50 || choice < 0);
			arrLength = static_cast<int>(choice);

			intArr = new int[arrLength];

			//obtain array elements from user
			std::cout << "Please enter the elements of the array. (Between -32,766 and 32766): " << std::endl;
			for (int i = 0; i < arrLength; i++) {
				status = 0;
				do {
					std::cout << "Array element " << i << ": ";
					if (status != 0) {
						std::cout << "Invalid input. Please enter an integer between -32,766 and 32,766." << std::endl;
					}
					//don't allow user to enter number larger than limits of integer (- 1)
				} while ((status = getInt(&choice)) != 0 || choice > 32766 || choice < -32766); 
				intArr[i] = static_cast<int>(choice);
			}

			std::cout << "The sum of the array elemnts is: ";
			//recursive function #2, arraySum function call:
			std::cout << arraySum(intArr, arrLength) << std::endl;

			//dealocate dynamic array
			delete[] intArr;
		}

		
	
		//************third recursive function section (triangulate)*****************************************
		else if (selection == 3) {
			//obtain number to triangulate from user
			status = 0;
			do {
				std::cout << "Enter an integer to have the tirangular number of that number calculated.";
				std::cout << "(Number must be between 1 and 255.): ";
				if (status != 0) {
					std::cout << "Invalid input. Please enter an integer between 1 and +255." << std::endl;
				}
			} while ((status = getInt(&choice)) != 0 || choice > 255 || choice < 1);


			std::cout << "Triangular of " << choice << " is: ";
			//recursive function #3, triangular function call
			std::cout << triangular(static_cast<int>(choice)) << std::endl;
		}
		else {
			std::cout << "Thank you for playing. Program will now exit." << std::endl;
		}

	} while (selection != 4);

	return 0;
}