/*********************************************************************
** Description: messageReader (for extra credit) reads through a text file for the appropriate messages
** that need to be displayed acording to each random event. 
*********************************************************************/

#include "messageReader.hpp"

std::string msgReader(std::string search, std::string fnameIn) {
	std::string ifName = fnameIn;
	std::string errorStatement = "Search tag could not be found!";
	std::string input;
	std::string readMsg = "";
	std::fstream nameFile;
    int offset = search.length();
	int found;


	nameFile.open(ifName.c_str(), std::ios::in);
	if (!nameFile) {
		return "File error.";
	}
	
	
	getline(nameFile, input);
	while (nameFile) {

		found = input.find(search);
		if (found != std::string::npos) {
			for (int i = offset; i < input.length(); i++) {
				readMsg += input.at(i);
			}
			nameFile.close();
			return readMsg;
		}
		getline(nameFile, input);
	}
	return errorStatement;
	nameFile.close();
}