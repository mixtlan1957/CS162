/*********************************************************************
** Program name: Lab3
** Author: Mario Franco-Munoz
** Date: 10/12/2017
** Description: Game class represents a game of "war". This game consists of two players that each have a die with 
** N-faces of their chosing. Players roll the die x ammount of times (limit of 50 rounds) and face off to see who gets the
** highest number of wins. Players can chose between a normal die and a weighted die which has a considerable higher chance of 
** yielding higher results.
*********************************************************************/

#include "Game.hpp"

//default constructor
Game::Game() {
	currentRound = 0;
	scoreP1 = 0;
	scoreP2 = 0;
	player1Mode = 0;
	player2Mode = 0;
}


/*********************************************************************
** Description: startMenu initializes game and asks player if they want to play or exit program.
*********************************************************************/
void Game::startMenu() {
	float input;
	int choice;
	int status;
	int errorCounter = 0;

	do {
		if (errorCounter > 1) {
			std::cout << "Invalid selection. Please enter a valid menu selection." << std::endl;
		}
		std::cout << "Please enter one of the following options: " << std::endl;
		std::cout << "1.	Play game." << std::endl;
		std::cout << "2.	Exit Program." << std::endl;
		errorCounter++;
	} while (((status = getInt(&input)) != 0) || (input < 1 || input >2));
	choice = static_cast<int>(input);

	//swtich for input of cases
	switch (choice) {
	case 1:
		initializeGame();
		break;
	case 2:
		std::cout << "Now exiting program" << std::endl;
		exit(0);
		break;
	default: std::cout << "FATAL ERROR" << std::endl;
		exit(0);
		break;
	}
}


/*********************************************************************
** Description: intitializeGame Initializes game by asking how many rounds will be played, 
** and what dice will be used by each player.
*********************************************************************/

void Game::initializeGame() {
	float input;
	int choice;
	int status;

	//prompt user to enter how many rounds will be played
	std::cout << "How many rounds will be played? (Minimum 1 round, maximum 50 rounds).";
	while (((status = getInt(&input)) != 0) || input < 1 || input > 50) {
		std::cout << "Invalid selection. Please enter a number of rounds [1..50]." << std::endl;
	}
	choice = static_cast<int>(input);
	rounds = choice;

	//type of die for player 1
	std::cout << "What kind of die will player 1 use? Enter 1 for normal die, enter 2 for loaded die: ";
	while (((status = getInt(&input)) != 0) || !(input == 1 || input == 2)) {
		std::cout << "Invalid selection. Please enter 1 for normal die, 2 for loaded die." << std::endl;
	}
	choice = static_cast<int>(input);
	player1Mode = choice;

	//type of die for player 1
	std::cout << "What kind of die will player 2 use? Enter 1 for normal die, enter 2 for loaded die: ";
	while (((status = getInt(&input)) != 0) || !(input == 1 || input ==2)) {
		std::cout << "Invalid selection. Please enter 1 for normal die, 2 for loaded die." << std::endl;
	}
	choice = static_cast<int>(input);
	player2Mode = choice;
	
	//how many sides will player 1's die have
	std::cout << "Please enter the number of sides player 1's die will have (minimum 2 sides, maximum 500 sides): ";
	while (((status = getInt(&input)) != 0) || input < 2 || input > 500) {
		std::cout << "Invalid selection. Please enter a number [2..500]." << std::endl;
	}
	choice = static_cast<int>(input);
	player1 = new LoadedDie(choice);
	
	//how many sides will player 2's die have
	std::cout << "Please enter the number of sides player 2's die will have (minimum 2 sides, maximum 500 sides): ";
	while (((status = getInt(&input)) != 0) || input < 2 || input > 500) {
		std::cout << "Invalid selection. Please enter a number [2..500]." << std::endl;
	}
	choice = static_cast<int>(input);
	player2 = new LoadedDie(choice);
	std::cout << "\n\n" << std::endl;
}

/*********************************************************************
** Description: displayResults outputs state of game.  State of game includes side and type of die used for each player,
** the number each player rolled, and the score result (culmination of previous rounds and present round).
*********************************************************************/
void Game::displayResults() {
	int tempP1_Roll;
	int tempP2_Roll;
	
	//display final results if appropriate
	
	currentRound++;
	if (rounds >= currentRound) {
		//Player 1 die mode
		if (player1Mode == 1) {
			tempP1_Roll = player1->rollTheDie(1, currentRound);
			std::cout << std::setw(9) << "Player 1 dice type: ";
			std::cout << "Normal" << std::endl;
			std::cout << std::setw(9) << "Player 1 rolled: ";
			std::cout << tempP1_Roll << std::endl;

		}
		else if (player1Mode == 2) {
			tempP1_Roll = player1->loadedRoll(1, currentRound);
			std::cout << std::setw(9) << "Player 1 dice type: ";
			std::cout << "Loaded" << std::endl;
			std::cout << std::setw(9) << "Player 1 rolled: ";
			std::cout << tempP1_Roll << std::endl;

		}
		else;

		//Player 2 die mode
		if (player2Mode == 1) {
			tempP2_Roll = player2->rollTheDie(2, currentRound);
			std::cout << std::setw(9) << "Player 2 dice type: ";
			std::cout << "Normal" << std::endl;
			std::cout << std::setw(9) << "Player 2 rolled: ";
			std::cout << player2->rollTheDie(2, currentRound) << std::endl;			}
		else if (player2Mode == 2) {
			tempP2_Roll = player2->loadedRoll(2, currentRound);
			std::cout << std::setw(9) << "Player 2 dice type: ";
			std::cout << "Loaded" << std::endl;
			std::cout << std::setw(9) << "Player 2 rolled: ";
			std::cout << player2->loadedRoll(2, currentRound) << std::endl;
		}
		else;

		//update score
		if (tempP1_Roll > tempP2_Roll) {
			std::cout << "Player 1 has won round " << currentRound << "!" << std::endl;
			scoreP1++;
		}
		else if (tempP1_Roll < tempP2_Roll) {
			std::cout << "Player 2 has won round " << currentRound << "!" << std::endl;
			scoreP2++;
		}
		else {
			std::cout << "Round " << currentRound << " has ended in a tie!" << std::endl;
		}

		std::cout << "Current score:" << std::endl;
		std::cout << std::setw(9) << "Player1: ";
		std::cout << scoreP1 << std::endl;
		std::cout << std::setw(9) << "Player2: ";
		std::cout << scoreP2 << "\n\n" << std::endl;

	}
	if (rounds == currentRound) {
		std::cout << "Final results:" << std::endl;
		if (scoreP1 > scoreP2) {
			std::cout << "Player 1 has won with a score of " << scoreP1 << "!!!" << std::endl;
			std::cout << "Player 2 has lost with a score of " << scoreP2 << "." << std::endl;
		}
		else if (scoreP2 > scoreP1) {
			std::cout << "Player 2 has won with a score of " << scoreP2 << "!!!" << std::endl;
			std::cout << "Player 1 has lost with a score of " << scoreP1 << "." << std::endl;
		}
		else {
			std::cout << "The game has ended in a tie!" << std::endl;

		}
	}
}

/*********************************************************************
** Description: runGame cycles through display results for the number of rounds selected by user in the initialize
** game section.
*********************************************************************/
void Game::runGame() {
	for (int i = 1; i <= rounds; i++) {
		displayResults();
	}
}

/*********************************************************************
** Description: getRoundNumber returns the current round.
*********************************************************************/
int Game::getRoundNumber() {
	return currentRound;
}