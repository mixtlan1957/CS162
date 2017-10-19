/*********************************************************************
** Program name: Project 3 (Zoo Tycoon)
** Author: Mario Franco-Munoz
** Date: 10/13/2017
** Description: Zoo class is the main working component of the virtual zoo game. First game is initialized with the gameInit
** function where user is prompted to enter how many animals to begin with the user will have. After which randEvent produces
** a random event: illness, birth of animals, bonus. After the random element phase, the user is provided a summary of the present
** round and asks if they would like to play again.
*********************************************************************/

#include "Zoo.hpp"

//default constructor
Zoo::Zoo() {
	acctBalance = 100000; //default $$ starting value.
	tigerPen = new Tiger*[START_CAP];
	penguinPen = new Penguin*[START_CAP];
	turtlePen = new Turtle*[START_CAP];

	for (int i = 0; i < START_CAP; i++) {
		tigerPen[i] = nullptr;
		penguinPen[i] = nullptr;
		turtlePen[i] = nullptr;
	}

	roundCounter = 0;
}

/*********************************************************************
** Description: gameInitialize welcomes the user to the start of the game and prompts the user if they want to start a new game.
*********************************************************************/
void Zoo::gameInit() {
	float choice;
	int status;
	int errorCounter = 0;
	std::string strTest;

	//introduction
	std::cout << "Welcome to the zoo simulation!" << std::endl;
	std::cout << "In this game you will be the proud owner of a virtual zoo that houses tigers, penguins and turtles." << std::endl;
	std::cout << "Extra credit options included in this program: #2 Status messages loaded from txt file." << std::endl;

	//do-while loop to present initial options to users.
	do {
		if (errorCounter > 1) {
			std::cout << "Invalid selection. Please enter a valid menu selection." << std::endl;
		}
		std::cout << " To begin, please enter one of the following options: " << std::endl;
		std::cout << "1.	Start virtual zoo game!" << std::endl;
		std::cout << "2.	Exit program." << std::endl;
		errorCounter++;
	} while (((status = getInt(&choice)) != 0) || !(choice == 1 || choice == 2));


	//swtich for input of cases
	switch (static_cast<int>(choice)) {
	case 1:

		//initialize the animal pens
		tigerPenSize = START_CAP;
		penguinPenSize = START_CAP;
		turtlePenSize = START_CAP;

		//initial instructions
		std::cout << "To begin, you must buy 1 - 2 of each type of animal." << std::endl;
		std::cout << std::setw(6) << "Tigers cost: ";
		std::cout << "$10,000" << std::endl;
		std::cout << std::setw(6) << "Penguins cost: ";
		std::cout << "$1,000" << std::endl;
		std::cout << std::setw(6) << "Turtles cost: ";
		std::cout << "$100" << std::endl;
		std::cout << std::setw(6) << "Your starting balance is: ";
		std::cout << "$" << std::showpoint << std::fixed << std::setprecision(2) << acctBalance << std::endl;

		//initial tiger selection
		errorCounter = 0; //reset error counter
		do {
			if (errorCounter > 1) {
				std::cout << "Invalid selection. Please enter \"1\" or \"2\". " << std::endl;
			}
			std::cout << "Enter the number of TIGERS you wish to purchase: (enter 1 or 2): " << std::endl;
			errorCounter++;
		} while (((status = getInt(&choice)) != 0) || choice > 2 || choice < 1);
		tigerCount = static_cast<int>(choice);
		for (int i = 0; i < choice; i++) {
			tigerPen[i] = new Tiger;
			tigerPen[i]->setAge(1);
			acctBalance -= tigerPen[i]->getCost();
		}

		//initial penguin selection
		errorCounter = 0;
		do {
			if (errorCounter > 1) {
				std::cout << "Invalid selection. Please enter \"1\" or \"2\". " << std::endl;
			}
			std::cout << "Enter the number of PENGUINS you wish to purchase: (enter 1 or 2): " << std::endl;
			errorCounter++;
		} while (((status = getInt(&choice)) != 0) || choice > 2 || choice < 1);
		penguinCount = static_cast<int>(choice);
		for (int i = 0; i < choice; i++) {
			penguinPen[i] = new Penguin;
			penguinPen[i]->setAge(1);
			acctBalance -= penguinPen[i]->getCost();
		}


		//initial turtle selection
		errorCounter = 0;
		do {
			if (errorCounter > 1) {
				std::cout << "Invalid selection. Please enter \"1\" or \"2\". " << std::endl;
			}
			std::cout << "Enter the number of TURTLES you wish to purchase: (enter 1 or 2): " << std::endl;
			errorCounter++;
		} while (((status = getInt(&choice)) != 0) || choice > 2 || choice < 1);
		//initial turtles selection
		turtleCount = static_cast<int>(choice);
		for (int i = 0; i < choice; i++) {
			turtlePen[i] = new Turtle;
			turtlePen[i]->setAge(1);
			acctBalance -= turtlePen[i]->getCost();
		}

		break;
	case 2:
		std::cout << "Thank you for playing Virtual Zoo." << std::endl;
		exit(0);
		break;
	default: std::cout << "FATAL ERROR" << std::endl;
		exit(1);
		break;
	}	
}


/*********************************************************************
** Description: randEvent selects a random event to occurr during the event phase of the virtual zoo game. One of the following
** is selected at random: 1) A sickness occurs to an animal, 2) a boom in the zoo attendance occurs, 3) A baby animal is born.
*********************************************************************/
void Zoo::randEvent() {
	int result = randomNumGen(4, 1, 1);
	int deathSelect;
	int bonus;
	int birthSelect;
	int birthCount;
	bool ageCheck = false;
	bool checkNext = false;
	int prev;
	

	int temp = 0; // temporary variable to keep track of how many animals have been checked for reproductive possibilities
				  // should the first randomly selected animal not have an animal old enough to reproduce.

	std::cout << "************RANDOM EVENT PHASE************" << std::endl;
	
	switch (result) {
	case 1: //random animal type selected and last animal in the corresponding animal pen is removed (dies)
		deathSelect = randomNumGen(3, 1, 2);
		std::cout << msgReader("$DEATH_") << std::endl;
			if (deathSelect == 1) {			// tiger dies
				if (tigerCount > 0) {
					std::cout << msgReader("$D_TIGER1_") << std::endl;
					std::cout << msgReader("$D_AGE1_") << tigerPen[tigerCount - 1]->getAge() << msgReader("$D_AGE2_") << std::endl;
					delete tigerPen[tigerCount - 1];
					tigerCount--;
				}
				else {
					std::cout << msgReader("$NO_DEATH_") << std::endl;
				}
			}
			else if (deathSelect == 2) {	// penguin dies
				if (penguinCount > 0) {
					std::cout << msgReader("$D_PENGUIN1_") << std::endl;

					std::cout << msgReader("$D_AGE1_") << penguinPen[penguinCount - 1]->getAge() << msgReader("$D_AGE2_") << std::endl;

					delete penguinPen[penguinCount - 1];
					penguinCount--;
				}
				else {
					std::cout << msgReader("$NO_DEATH_") << std::endl;
				}
			}
			else {				// turtle dies
				if (turtleCount > 0) {
					std::cout << msgReader("$D_TURTLE1_") << std::endl;

					std::cout << msgReader("$D_AGE1_") << turtlePen[turtleCount - 1]->getAge() << msgReader("$D_AGE2_") << std::endl;

					delete turtlePen[turtleCount - 1];
					turtleCount--;
				}
				else {
					std::cout << msgReader("$NO_DEATH_") << std::endl;
				}
			}
		break;


	case 2:	//a boom in zoo attendance occurs
		bonus = randomNumGen(500, 250, 2);
		std::cout << msgReader("$BONUS1_") << std::endl;
		std::cout << msgReader("$BONUS2_") << bonus << std::endl;
		bonus *= tigerCount;
		std::cout << msgReader("$BONUS_TOTAL_") << bonus << std::endl;
		acctBalance += bonus;
		break;
	
	
	case 3: //a baby animal is born (if possible)
		birthSelect = randomNumGen(3, 1, 2);
		
		std::cout << msgReader("$BIRTH_") << std::endl;
		while (temp < 3) {
			//tiger birth section
			if (birthSelect == 1 || checkNext == true) {			
				for (int i = 0; i < tigerCount; i++) {
					if (tigerPen[i]->getAge() >= 3) {
						ageCheck = true;
					}
				}
				if (ageCheck == true) {
					birthCount = 1 * tigerPen[0]->getBabyMult();
					prev = tigerCount;
					tigerCount += birthCount;
					expandPen(prev, 1);
					temp = 3;
					checkNext = false;
					std::cout << birthCount << msgReader("$B_TIGER_") << std::endl;

				}
				else {
					checkNext = true;
					temp++;
				}
			}

			//penguin section
			else if (birthSelect == 2 || checkNext == true) {
				// check the age of the animals to see if one is old enough to reproduce
				for (int i = 0; i < penguinCount; i++) {
					if (penguinPen[i]->getAge() >= 3) {
						ageCheck = true;
					}
				}
				if (ageCheck == true) {
					birthCount = 1 * penguinPen[0]->getBabyMult();
					prev = penguinCount;
					penguinCount += birthCount;
					expandPen(prev, 2);
					temp = 3;
					checkNext = false;
					std::cout << birthCount << msgReader("$B_PENGUIN_") << std::endl;
				}
				else {
					checkNext = true;
					temp++;
				}
			}

			//turtle section
			else if (birthSelect == 3 || checkNext == true) {
				// check the age of the animals to see if one is old enough to reproduce
				for (int i = 0; i < turtleCount; i++) {
					if (turtlePen[i]->getAge() >= 3) {
						ageCheck = true;
					}
				}
				if (ageCheck == true) {
					birthCount = 1 * turtlePen[0]->getBabyMult();
					prev = turtleCount;
					turtleCount += birthCount;
					expandPen(prev, 3);
					temp = 3;
					checkNext = false;
					std::cout << birthCount << msgReader("$B_TURTLE_") << std::endl;
				}
				else {
					checkNext = true;
					temp++;
				}
			}

		}
		
		if (ageCheck == false) {
			std::cout << msgReader("$B_ERROR_") << std::endl;
		}
		break;
	case 4:
		//nothing happens
		std::cout << msgReader("$DEFAULT_") << std::endl;
		break;

	default:
		exit(1);
		break;
	}

}

/*********************************************************************
** Description: expandPen checks input "birthCount" to determine if a new dynamically alocated array needs to be created
** so that the new-born animals can fit. Parameters: previous number of animals (prior to birth of new animals) new updated
** number of animals, type of animal (1 for tiger, 2 for penguin, 3 for turtle)
** expandPen is also used for the purchase of new animals however, the age must be set to adult age outside of this function
** as the default age of new animals is 0 days.
*********************************************************************/
void Zoo::expandPen(int prev, int type) {
	int prevPenSize; //old pen size (not to be confused with previous number of animals prior to births/purchase)
	if (type == 1) {
		if (tigerCount > tigerPenSize) {
			//fill in what space is available in current cage
			for (int i = prev; i < tigerPenSize; i++) {   //this here was the source of many problems this tiny forloop here.
				tigerPen[i] = new Tiger; //don't forget the pain it caused you. You cannot access elements in an array of pointers			
				tigerPen[i]->setAge(0); //that have nothing in them.
			}
			
			prevPenSize = tigerPenSize;
			tigerPenSize += START_CAP;
			Tiger **temp = nullptr;
			temp = new Tiger*[tigerPenSize];

			//transfer previous pointers
			for (int i = 0; i < prevPenSize; i++) {
				temp[i] = new Tiger;
				temp[i] = tigerPen[i];
			}

			//set age of new babies to 0 days (this function treats new animals as babies by default)
			for (int i = prevPenSize; i < tigerCount; i++) {
				temp[i] = new Tiger;
				temp[i]->setAge(0);
			}

			//dealocate memory of prev address
			for (int i = 0; i < prevPenSize; i++) {
				delete tigerPen[i];
			}
			delete[] tigerPen;
			tigerPen = nullptr;

			//reasign array of pointers and pointers inside the array of pointers.
			tigerPen = temp;
			for (int i = 0; i < tigerPenSize; i++) {
				tigerPen[i] = new Tiger;
				tigerPen[i] = temp[i];
			}
		}
		else {
			//if pen expansion is not needed, set additional new members to be babies with age = 0;
			for (int i = prev; i < tigerCount; i++) {
				tigerPen[i] = new Tiger;
				tigerPen[i]->setAge(0);
			}
		}

	}
	else if (type == 2) {
		if (penguinCount > penguinPenSize) {
			//fill in what space is available in current cage
			for (int i = prev; i < penguinPenSize; i++) {
				penguinPen[i] = new Penguin;
				penguinPen[i]->setAge(0);
			}
			
			prevPenSize = penguinPenSize;
			penguinPenSize += START_CAP;
			Penguin **temp = nullptr;
			temp = new Penguin*[penguinPenSize];

			//transfer previous pointers
			for (int i = 0; i < prevPenSize; i++) {
				temp[i] = new Penguin;
				temp[i] = penguinPen[i];
			}

			//set age of new babies to 0 days
			for (int i = prevPenSize; i < penguinCount; i++) {
				temp[i] = new Penguin;
				temp[i]->setAge(0);
			}

			//dealocate memory of prev address
			for (int i = 0; i < prevPenSize; i++) {
				delete penguinPen[i];
			}
			delete[] penguinPen;
			penguinPen = nullptr;

			//reasign pointer
			penguinPen = temp;
			for (int i = 0; i < penguinPenSize; i++) {
				penguinPen[i] = new Penguin;
				penguinPen[i] = temp[i];
			}
		}
		else {
			for (int i = prev; i < penguinCount; i++) {
				penguinPen[i] = new Penguin;
				penguinPen[i]->setAge(0);
			}
		}

	}
	else if (type == 3) {
		if (turtleCount > turtlePenSize) {
			//fill in what is left in the present cage
			for (int i = prev; i < turtlePenSize; i++) {
				turtlePen[i] = new Turtle;
				turtlePen[i]->setAge(0);
			}
			
			//tracking variables & initializing temporary pointer
			prevPenSize = turtlePenSize;
			turtlePenSize += START_CAP;
			Turtle **temp = nullptr;
			temp = new Turtle*[turtlePenSize];

			//copy previous pointers
			for (int i = 0; i < prevPenSize; i++) {
				temp[i] = new Turtle;
				temp[i] = turtlePen[i];
			}

			//set age of new babies to 0 days
			for (int i = prevPenSize; i < turtleCount; i++) {
				temp[i] = new Turtle;
				temp[i]->setAge(0);
			}

			//dealocate memory of prev address
			for (int i = 0; i < prevPenSize; i++) {
				delete turtlePen[i];
			}
			delete[] turtlePen;
			turtlePen = nullptr;

			//reasign pointer
			turtlePen = temp;
			for (int i = 0; i < turtlePenSize; i++) {
				turtlePen[i] = new Turtle;
				turtlePen[i] = temp[i];
			}
		}
		else {
			for (int i = prev; i < turtleCount; i++) {
				turtlePen[i] = new Turtle;
				turtlePen[i]->setAge(0);
			}
		}
	}
	else {
		std::cout << "Error has occured" << std::endl;
	}
}


/*********************************************************************
** Description: profitCalc is the end-step procedure for the virtual Zoo game. 
*********************************************************************/
void Zoo::profitCalc() {
	double dailyProfit = 0.0;
	float choice;
	int status;
	int errorCounter = 0;
	int prev;

	//calculate payoff
	if (tigerCount > 0) {
		std::cout << "Tiger profit: " << tigerCount * (tigerPen[0]->getPayoff()) << std::endl;
		dailyProfit += tigerCount * (tigerPen[0]->getPayoff());
	}
	if (penguinCount > 0) {
		std::cout << "Penguin profit: " << penguinCount * (penguinPen[0]->getPayoff()) << std::endl;
		dailyProfit += penguinCount * (penguinPen[0]->getPayoff());
	}
	if (turtleCount > 0) {
		std::cout << "Turtle profit: " << turtleCount * (turtlePen[0]->getPayoff()) << std::endl;
		dailyProfit += turtleCount * (turtlePen[0]->getPayoff());
	}
	std::cout << "Total profit for this round: $" << std::setprecision(2) << std::fixed << std::showpoint << dailyProfit << std::endl;
	acctBalance += dailyProfit;
	std::cout << "Current balance: $" << std::setprecision(2) << std::fixed << std::showpoint << acctBalance << std::endl;

	//Ask user to buy animal
	std::cout << "***********ANIMAL PURCHASE STAGE / END PHASE**************" << std::endl;
	std::cout << "Would you like to purchase a new adult animal?" << std::endl;
	std::cout << "Enter 1 to purchase an adult animal." << std::endl;
	std::cout << "Enter 2 to continue without pruchasing.";
	errorCounter = 0;
	do {
		if (errorCounter > 1) {
			std::cout << "Invalid selection. Please enter a valid menu selection." << std::endl;
			std::cout << "\"1\" to purchase an adult animal, \"2\" to continue without purchasing." << std::endl;
		}
		errorCounter++;
	} while ((status = getInt(&choice) != 0) || choice > 2 || choice < 1);
	

	//sequence for buying an animal
	if (choice == 1) {
		errorCounter = 0;
		do {
			if (errorCounter > 1) {
				std::cout << "Invalid selection. Please enter a valid menu selection." << std::endl;
			}
			std::cout << "Please select one of the following:  " << std::endl;
			std::cout << "1.	Purchase one adult lion. ($10,000)" << std::endl;
			std::cout << "2.	Purchase one adult penguin. ($1,000) " << std::endl;
			std::cout << "3.      Purchase one adult turtle. ($100)" << std::endl;
			errorCounter++;

		} while (((status = getInt(&choice)) != 0) || choice < 1 || choice > 3);

		if (choice == 1) {
			acctBalance -= 10000;
			prev = tigerCount;
			tigerCount++;
			expandPen(prev, 1);
			//set age of new adult animal (expandPen sets the age of new animals as 0 by default)
			tigerPen[tigerCount - 1]->setAge(3);
		}
		else if (choice == 2) {
			acctBalance -= 1000;
			prev = penguinCount;
			penguinCount++;
			expandPen(prev, 2);
			penguinPen[penguinCount - 1]->setAge(3);
		}
		else {
			acctBalance -= 100;
			prev = turtleCount;
			turtleCount++;
			expandPen(prev, 3);
			turtlePen[turtleCount - 1]->setAge(3);

		}
	}
	std::cout << "DAY " << roundCounter << " has come to an end." << std::endl;
	gameSummary();
}



/*********************************************************************
** Description: gameLoop runs through the primary sequence of the virtual zoo game and prompts the user
** to play another round upon conclusion of round. (Round counter lives here)
*********************************************************************/
void Zoo::gameLoop() {
	int status;
	float choice;
	int errorCounter = 0;
	
	gameInit();
	do {
		roundCounter++;   //this is were the round counter lives
		std::cout << "\n" << std::endl;
		std::cout << "**********START OF DAY **********" << std::endl;
		startOfDay();
		randEvent();
		profitCalc();

		if (acctBalance > 0) {
			errorCounter = 0;
			do {
				//prompt user to end game or keep playing
				if (errorCounter > 1) {
					std::cout << "Invalid selection. Please enter a valid menu selection." << std::endl;
				}
				std::cout << "Round " << roundCounter << " has ended. Please select one of the following:  " << std::endl;
				std::cout << "1.	Play another round! (go to next day of simulation)" << std::endl;
				std::cout << "2.	Exit program." << std::endl;
				errorCounter++;
			} while (((status = getInt(&choice)) != 0) || !(choice == 1 || choice == 2));

			switch (static_cast<int>(choice)) {
			case 1:
				std::cout << "Awesome! Moving on to round " << roundCounter + 1 << "." << std::endl;
				std::cout << "Current game stats:" << std::endl;
				gameSummary();
				break;
			case 2:
				std::cout << "******Final game summary:******** " << std::endl;
				gameSummary();
				std::cout << "Thanks for playing Virtual Zoo." << std::endl;
				exit(0);
				break;
			default: std::cout << "FATAL ERROR" << std::endl;
				exit(1);
				break;
			}

		}
		else {
			std::cout << "Uh-oh... You your zoo has gone broke!" << std::endl;
			std::cout << "******Final game summary:******** " << std::endl;
			gameSummary();
			std::cout << "Thanks for playing Virtual Zoo." << std::endl;
			exit(0);
		}
	} while (choice == 1);

}

/*********************************************************************
** Description: gameSummary displays to the user the current balance, number of tigers, penguins, turtles, and number of rounds
** played.
*********************************************************************/
void Zoo::gameSummary() {
	std::cout << "Balance:        $" << std::setprecision(2) << std::fixed << std::showpoint << acctBalance << std::endl;
	std::cout << "Tigers:          " << tigerCount << std::endl;
	std::cout << "Penguins:        " << penguinCount << std::endl;
	std::cout << "Turtles:         " << turtleCount << std::endl;
	std::cout << "Rounds played:   " << roundCounter << std::endl;
	std::cout << "\n" << std::endl;
}

/*********************************************************************
** Description: startOfDay increments the age of all the animals by 1 and substracts the feed costs from the account balance.
*********************************************************************/
void Zoo::startOfDay() {
	int foodCosts;

	//increment the age of all animals by one day
	if (tigerCount > 0) {
		for (int i = 0; i < tigerCount; i++) {
			tigerPen[i]->incrementAge();
		}
	}
	
	if (penguinCount > 0) {
		for (int i = 0; i < penguinCount; i++) {
			penguinPen[i]->incrementAge();
		}
	}
	
	if (turtleCount > 0) {
		for (int i = 0; i < turtleCount; i++) {
			turtlePen[i]->incrementAge();
		}
	}
	

	//substract feed cost
	if (tigerCount > 0) {
		foodCosts = tigerCount * (tigerPen[0]->getFoodCost());
		acctBalance -= foodCosts;
		std::cout << "$" << foodCosts << " spent on tiger food." << std::endl;
	}
	if (penguinCount > 0) {
		foodCosts = penguinCount * (penguinPen[0]->getFoodCost());
		acctBalance -= foodCosts;
		std::cout << "$" << foodCosts << " spent on penguin food." << std::endl;
	}
	if (turtleCount > 0) {
		foodCosts = turtleCount * (turtlePen[0]->getFoodCost());
		acctBalance -= foodCosts;
		std::cout << "$" << foodCosts << " spent on turtle food." << std::endl;
	}

}



/*********************************************************************
** Description: messageReader (for extra credit) reads through a text file for the appropriate messages
** that need to be displayed acording to each random event. 
*********************************************************************/
std::string Zoo::msgReader(std::string search) {
	std::string ifName = "messages.txt";
	std::string errorStatement = "Search tag could not be found!";
	std::string input;
	std::string readMsg = "";
	std::fstream nameFile;
    int offset = search.length();
	int found;


	nameFile.open(ifName.c_str(), std::ios::in);
	if (!nameFile) {
		std::cout << "File could not be opened." << std::endl;
	}
	
	//the principle of this loop here is the very similar to the search function
	//used in CS161: remember, in this case we do not want to change cases since
	//tags can contain different characters other than letters.
	getline(nameFile, input);		//this here is the sentence or line that we are looking through
	while (nameFile) {				//search line by line

		found = input.find(search);
		if (found != std::string::npos) {	//thanks to find() string member function we can locate the tag
			for (int i = offset; i < input.length(); i++) {  //ignore the tag and input the statement we want
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

