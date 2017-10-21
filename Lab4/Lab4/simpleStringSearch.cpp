/*********************************************************************
** Program name: Lab4
** Author: Mario Franco-Munoz
** Date: 10/19/2017
** Description: This function takes a block of text (as a string) and using the $ character
** as a delimiter it searches for string value passed by value.
*********************************************************************/


#include "simpleStringSearch.hpp"

std::string stringSearch(std::string strIn, std::string search) {
	std::string outputString = "";
	std::string ssInput;
	std::string error = "NOT FOUND!";
	int offset = search.length();
	std::stringstream ss;
	int found;

	ss << strIn;
	getline(ss, ssInput, '$');
	while (ss) {
		found = ssInput.find(search);
		if (found != std::string::npos) {
			for (int i = offset; i < ssInput.length(); i++) {
				outputString += ssInput.at(i);
			}
			ss.clear();
			return outputString;
		}
		getline(ss, ssInput, '$');
	}
	ss.clear();
	return error;
}