/*********************************************************************
** Program name: Lab5
** Author: Mario Franco-Munoz
** Date: 10/23/2017
** Description: Source file for "First RecursiveFunction" uses recursion to print the reverse
** of a string. 
*********************************************************************/


#include "reverseString.hpp"

void reverseString(std::string strIn) {

	if (strIn.length() > 0) {  //base case
		std::cout << strIn.at(strIn.length()-1); //print last character in current string iteration
		strIn.pop_back();	   //shorten the string each iteration					
		reverseString(strIn);  //recursive function call
	}
	else {
		std::cout << "\n";  //end string reversal with newline character to CRLF
	}
}
