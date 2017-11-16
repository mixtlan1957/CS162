/*********************************************************************
** Program name: Lab 7
** Author: Mario Franco-Munoz
** Date: 11/15/2017
** Description: SeachSort reads the values of three different txt files containing
** random integers and after loading the values into different
** arrays: 1) applies a simple linear search algorithm, 2) Sorts the three different arrays
** 3)Applies a binary search. 
*********************************************************************/

#include "SearchSort.hpp"

//default constructor
SearchSort::SearchSort() {
	arrCap_early, arrCap_middle, arrCap_end, arrCap_original = 0;
	early = nullptr;
	middle = nullptr;
	end = nullptr;
	original = nullptr;
}

/*********************************************************************
** Description: menu is the main holding point for the different aspects of the SearchSort class that need
** to be executed. (Loading arrays, simple search, mergeSort, and binary search).
*********************************************************************/
void SearchSort::menu() {
	//load the arrays
	readFiles("early.txt");
	readFiles("middle.txt");
	readFiles("end.txt");
	readFiles("original.txt");

	//simple search function call
	simpleSearch();

	//merge sort
	sortingMenu();

	//binary search
	binSearchPrompt();


}


/*********************************************************************
** Description: readFiles searches through the four different textfiles and loads
** their contents into their respective arrays.
*********************************************************************/
void SearchSort::readFiles(std::string strIn) {
	std::string fileName = strIn;		//input file name
	std::ifstream ifs;					//input file stream					
	int number;							//file read through input file stream
	int count = 0;						//counter (for array assignment)

	ifs.open(fileName.c_str(), std::ios::in);
	
	if (ifs) {
		//first count the nubmer of numbers in the file (to avoid having to expand arrays)
		while (ifs >> number) {
			count++;
		}

		//rewind back to begining of file to now load into array
		ifs.clear();
		ifs.seekg(0L, std::ios::beg);

		if (fileName == "early.txt") {
			arrCap_early = count;
			early = new int[arrCap_early];

			//reset counter
			count = 0;

			//load elements into array
			while (ifs >> number) {
				early[count] = number;
				count++;
			}

		}
		else if (fileName == "middle.txt") {
			arrCap_middle = count;
			middle = new int[arrCap_middle];

			count = 0;

			while (ifs >> number) {
				middle[count] = number;
				count++;
			}
		}
		else if (fileName == "end.txt") {
			arrCap_end = count;
			end = new int[arrCap_end];

			count = 0;

			while (ifs >> number) {
				end[count] = number;
				count++;
			}
		}

		else if (fileName == "original.txt") {
			arrCap_original = count;
			original = new int[arrCap_original];

			count = 0;

			while (ifs >> number) {
				original[count] = number;
				count++;
			}
		}
		else {
			std::cout << "Error accessing file." << std::endl;
			exit(1);
		}

	} 
	else {
		std::cout << "Error opening file." << std::endl;
	}
	ifs.close();
}



/*********************************************************************
** Description: simpleSearch uses a basic linear search algorithm and searches through
** each of the elements of the array for the requested value.
*********************************************************************/
void SearchSort::simpleSearch() {
	//variables used for user validation input (integer provided by user)
	int status;
	int error;
	float choice;

	//flags for searching through each respective array
	bool found_early = false;
	bool found_middle = false;
	bool found_end = false;
	bool found_original = false;
	
	//index & counter for use in while search loops
	int index = 0;

	std::cout << "Lets run a simple search!" << std::endl;

	error = 0;
	do {
		std::cout << "Please enter a number between 0 and 100 (inclusive) to search for." << std::endl;
		if (error > 0) {
			std::cout << "Invalid input. Please enter a number between 0 and 100." << std::endl;
		}
		error++;
	} while ((status = getInt(&choice)) != 0 || choice < 0 || choice > 100);


	//search through early array
	index = 0;
	while (!found_early && index < arrCap_early) {
		if (early[index] == static_cast<int>(choice)) {
			found_early = true;
		}
		index++;
	}
	if (found_early == true) {
		std::cout << "Found the input value of " << choice << "!" << std::endl;
	}
	else {
		std::cout << "Value not found in early.txt!" << std::endl;
	}


	//search through middle array
	index = 0;
	while (!found_middle && index < arrCap_middle) {
		if (middle[index] == static_cast<int>(choice)) {
			found_middle = true;
		}

		index++;
	}
	if (found_middle == true) {
		std::cout << "Found the input value of " << choice << "!" << std::endl;
	}
	else {
		std::cout << "Value not found in middle.txt!" << std::endl;
	}


	//search through end array
	index = 0;
	while (!found_end && index < arrCap_end) {
		if (end[index] == static_cast<int>(choice)) {
			found_end = true;
		}
		index++;
	}
	if (found_end == true) {
		std::cout << "Found the input value of " << choice << "!" << std::endl;
	}
	else {
		std::cout << "Value not found in end.txt!" << std::endl;
	}


	//search through original array
	index = 0;
	while (!found_original && index < arrCap_original) {
		if (original[index] == static_cast<int>(choice)) {
			found_original = true;
		}
		index++;
	}
	if (found_original == true) {
		std::cout << "Found the input value of " << choice << "!" << std::endl;
	}
	else {
		std::cout << "Value not found in original.txt!" << std::endl;
	}
}

/*********************************************************************
** Description: sortingMenu provides an interface for the sorting and 
** naming/generation of output files.
*********************************************************************/
void SearchSort::sortingMenu() {
	std::ofstream ofs;			//output file stream
	std::string fileName;		//validated file name		
	

	//initial instructions
	std::cout << "\n";
	std::cout << "The three different input files (early.txt, middle.txt, end.txt, and original.txt will now be sorted." << std::endl;
	std::cout << "Before displaying the sorted values, please enter an output file name for each of the corresponding ";
	std::cout << "four input files." << std::endl;
	std::cout << "Please note that the file name must end in \".txt\"" << std::endl;
	std::cout << "\n";


	//first file
	std::cout << "Please enter the name of the first output file. (early.txt output)" << std::endl;
	fileName = getValidFileName();

	mergeSort(early, 0, arrCap_early - 1);

	ofs.open(fileName);
	if (ofs) {
		for (int i = 0; i < arrCap_early; i++) {
			ofs << early[i] << std::endl;
		}
	}
	else {
		std::cout << "error opening output file." << std::endl;
	}
	ofs.close();

	//second file
	std::cout << "Please enter the name of the second output file. (middle.txt output)" << std::endl;
	fileName = getValidFileName();

	mergeSort(middle, 0, arrCap_middle - 1);

	ofs.open(fileName);
	if (ofs) {
		for (int i = 0; i < arrCap_middle; i++) {
			ofs << middle[i] << std::endl;
		}
	}
	else {
		std::cout << "error opening output file." << std::endl;
	}
	ofs.close();

	//third file
	std::cout << "Please enter the name of the third output file. (end.txt output)" << std::endl;
	fileName = getValidFileName();

	mergeSort(end, 0, arrCap_end - 1);

	ofs.open(fileName);
	if (ofs) {
		for (int i = 0; i < arrCap_end; i++) {
			ofs << end[i] << std::endl;
		}
	}
	else {
		std::cout << "error opening output file." << std::endl;
	}
	ofs.close();

	//fourth file
	std::cout << "Please enter the name of the fourth output file. (original.txt output)" << std::endl;
	fileName = getValidFileName();

	mergeSort(original, 0, arrCap_original- 1);

	ofs.open(fileName);
	if (ofs) {
		for (int i = 0; i < arrCap_original; i++) {
			ofs << original[i] << std::endl;
		}
	}
	else {
		std::cout << "error opening output file." << std::endl;
	}
	ofs.close();
}

/*********************************************************************
** Description: mergeSort is based off the C-style code found on:
**  http://www.includehelp.com/cpp-tutorial/merge-sort-with-example.aspxmodified to be compatible with C++
** as original example did not account for dynamic mmemory alocation.
*********************************************************************/
void SearchSort::mergeSort(int arr[], int p, int r) {
	int q;

	if (p<r)
	{
		q = (p + r) / 2;                      /*q is the middle element to divide the array*/
		mergeSort(arr, p, q);
		mergeSort(arr, q + 1, r);
		merge(arr, p, q, r);
	}
}

/*********************************************************************
** Description: merge (mergeSort algorithm component)
*********************************************************************/
void SearchSort::merge(int arr[], int p, int q, int r) {
	int n1 = q - p + 1, i, j, k;       /*n1 is the size of L[]*/

	int n2 = r - q;               /*n2 is the sixe of R[]*/

	int *L;
	int *R;

	L = new int[n1];
	R = new int[n2];

	for (i = 0; i<n1; i++)

	{
		L[i] = arr[p + i];
	}

	for (j = 0; j<n2; j++)
	{
		R[j] = arr[q + j + 1];
	}

	i = 0, j = 0;

	for (k = p; i<n1&&j<n2; k++)
	{
		if (L[i]<R[j])
		{
			arr[k] = L[i++];
		}
		else
		{
			arr[k] = R[j++];
		}
	}

	while (i<n1)             /*If L[] has more elements than R[] then it will put all the reamining elements of L[] into A[]*/
	{
		arr[k++] = L[i++];
	}

	while (j<n2)             /*If R[] has more elements than L[] then it will put all the reamining elements of R[] into A[]*/
	{
		arr[k++] = R[j++];
	}
	
	//dealocate memory
	delete[] L;
	delete[] R;
}


/*********************************************************************
** Description: getValidFileName makes sure that the file name input by user does not contain invalid
** characters and that it ends with ".txt"
*********************************************************************/
std::string SearchSort::getValidFileName() {
	int strLength;				//input string length
	bool errorFlag = true;		//error flag
	std::string fileName;		//attempted file name
	std::string inputVal;		//string variable for validating inclusion of ".txt"
	int found;					//for running str.find() string memeber function
	std::string troll = "\\/*?\"<>|";		//invalid characters
	int count;


	do {
		getline(std::cin, fileName);

		strLength = fileName.length();
		//first check to make sure that file ends with ".txt"
		inputVal = fileName.substr(strLength - 4, strLength - 1);
		if (inputVal != ".txt") {
			std::cout << "Invalid file name! ";
			std::cout << "Please ensure that the file name ends with \".txt\" (in lowercase)!" << std::endl;
		}
		else {
			errorFlag = false;
		}

		//next check for "troll" values (values not valid for file naming)
		if (errorFlag == false) {
			count = 0;
			while (count < troll.length() && errorFlag == false) {
				found = fileName.find(troll.at(count));				//search for each of the invalid characters
				if (found != std::string::npos) {
					errorFlag = true;
				}
				count++;
			}

			if (errorFlag == true) {
				std::cout << "Invalid character entered! Please do not include \\/*?\"<>| in the file name!" << std::endl;
				std::cout << "please re-enter flie name." << std::endl;
			}
		}

	} while (errorFlag == true);

	return fileName;
}


/*********************************************************************
** Description: binSearchPrompt() provides an interface for the user to execute the binary search
** function for the three different files.
*********************************************************************/
void SearchSort::binSearchPrompt() {
	int status;				//status for user validation segment
	int error;				//error counter for user validation segment
	float choice;			//user input (as float) for user validation segment
	int result;				//result of running the binary search (-1 if not found, array index if found)

	std::cout << "Now lets run a simple binary search!" << std::endl;

	//validate user input
	error = 0;
	do {
		std::cout << "Please enter a number between 0 and 100 (inclusive) to search for." << std::endl;
		if (error > 0) {
			std::cout << "Invalid input. Please enter a number between 0 and 100." << std::endl;
		}
		error++;
	} while ((status = getInt(&choice)) != 0 || choice < 0 || choice > 100);

	//search through the first file
	result = binSearch(early, arrCap_early, static_cast<int>(choice));
	if (result == -1) {
		std::cout << "Value not found in early.txt!" << std::endl;
	}
	else {
		std::cout << "Found the input value of " << choice << "! It was the position ";
		std::cout << result + 1 << " in the sorted array/output file." << std::endl;
	}

	//search through the second file
	result = binSearch(middle, arrCap_middle, static_cast<int>(choice));
	if (result == -1) {
		std::cout << "Value not found in middle.txt!" << std::endl;
	}
	else {
		std::cout << "Found the input value of " << choice << "! It was in the position ";
		std::cout << result + 1 << " in the sorted array/outputfile." << std::endl;
	}


	//search through the third file
	result = binSearch(end, arrCap_end, static_cast<int>(choice));
	if (result == -1) {
		std::cout << "Value not found in end.txt!" << std::endl;
	}
	else {
		std::cout << "Found the input value of " << choice << "! It was in the position ";
		std::cout << result + 1 << " in the sorted array/outputfile." << std::endl;
	}

	//search through the original file
	result = binSearch(original, arrCap_original, static_cast<int>(choice));
	if (result == -1) {
		std::cout << "Value not found in original.txt!" << std::endl;
	}
	else {
		std::cout << "Found the input value of " << choice << "! It was in the position ";
		std::cout << result + 1 << " in the sorted array/original file." << std::endl;
	}
}

/*********************************************************************
** Description: binSearch() is taken from "C++ Early Objects" 9th ed by Gaddis.
** This function performs a binary search on an an array and returns the index
** if found, and -1 if not found.
*********************************************************************/
int SearchSort::binSearch(int arr[], int size, int value) {
	int first = 0;					// First array element
	int last = size - 1;			// Last array element
	int middle = -1;				// Midpoint of search
	int position = -1;				// Position of search value
	bool found = false;				// Flag

	while (!found && first <= last) {
		middle = (first + last) / 2;		//calculate mid point
		if (arr[middle] == value) {			//if value is found at mid
			found = true;
			position = middle;
		}
		else if (arr[middle] > value) {		// if value is in lower half
			last = middle - 1;
		}
		else {								// if value is in upper half
			first = middle + 1;
		}
	}
	return position;
}