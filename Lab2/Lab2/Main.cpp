/*********************************************************************
** Program name: Lab2
** Author: Mario Franco-Munoz
** Date: 10/6/2017
** Description: Main source file for Lab2 assignment "Letter Count" program. This program asks user to provide a txt file
** that can consist of uppercase and lowercase characters of the english alphabet and new line characters. For every new paragraph
** encountered ('\n' character) the program prompts the user to enter the name of an output file where a count of how many times
** each letter appeared for a given paragraph in the input file. This continues for every paragraph (\n) and until EOF is reached.
*********************************************************************/

#include "output_letters.hpp"
#include "count_letters.hpp"

int main() {
	//primary use variables
	std::string ifName = "";
	std::string ofName = "";
	std::string paragraph;
	int alphabetArr[26];
	std::ofstream ofs;
	int pcount = 0;			//paragraph counter


	//initialize array to prevent odd errors from occuring.
	for (int i = 0; i < 26; i++) {
		alphabetArr[i] = 0;
	}
	
	
	//introduction
	std::cout << "Hello, welcome to \"Letter Count.\" \n";
	std::cout << "This program takes a file and count the number of times a given letter appears." << std::endl;
	std::cout << "And the a text file is output containing a count of the frequency of each letter." << std::endl;
	std::cout << "(Per paragraph)." << std::endl;
	std::cout << "Please note, input file must consist of only characters a through z, (caps and lower case), " << std::endl;
	std::cout << "the space and newline characters (\\n) \n" << std::endl;
	
	//getfile name from user
	std::cout << "Please enter the name of the file that will be read (include file extention): ";
	getline(std::cin, ifName);

	//initialize the input file stream
	std::ifstream ifs(ifName.c_str(), std::ios::in);

	//verify the file
	if (ifs.fail()) {
		std::cout << "Error opening file. Program will now close." << std::endl;
	}

	while (ifs) {
		pcount++;

		//call the count letters function
		count_letters(ifs, alphabetArr);

		//designate output
		std::cout << "Enter the name of the output text file where results (paragraph " << pcount << ") will be output to: ";
		getline(std::cin, ofName);
		std::ofstream ofs(ofName.c_str(), std::ios::out);
		output_letters(ofs, alphabetArr);
		

		//reinitialize array to all zeros
		for (int i = 0; i < 26; i++) {
			alphabetArr[i] = 0;
		}
	}

	//close input file
	ifs.close();
	
	//close output file
	ofs.close();

	return 0;
}