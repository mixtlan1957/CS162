/*********************************************************************
** Program name: Final Project
** Author: Mario Franco-Munoz
** Date: 11/27/2017
** Description: 
*********************************************************************/

#include "GameBoard.hpp"


//default constructor
GameBoard::GameBoard() {
	//initialize all the game spaces
	player = new BattleMage;
	gameTimer = 15;
	finalBossDefeated = false;

	//initialize the game grid
	room0 = new DefaultRoom(0);
	room1 = new DefaultRoom(1);
	room2 = new MobsRoom(2);
	room3 = new DefaultRoom(3);
	room4 = new FireBossRoom(4);
	room5 = new MobsRoom(5);
	room6 = new DefaultRoom(6);
	room7 = new IceBoss(7);
	room8 = new MobsRoom(8);
	room9 = new FinalBossRoom(9);

	//link the spaces on the game board together.
	//space 0 - starting space
	room0->setTop(room1);
	//space1
	room1->setTop(room2);
	//space2
	room2->setTop(room5);
	room2->setLeft(room3);
	//space3
	room3->setRight(room2);
	room3->setLeft(room4);
	//space4
	room4->setRight(room3);
	//space5
	room5->setBottom(room2);
	room5->setRight(room6);
	room5->setTop(room8);
	//space6
	room6->setLeft(room5);
	room6->setRight(room7);
	//space7
	room7->setLeft(room6);
	//space8
	room8->setBottom(room5);
	room8->setTop(room9);
	//space9
	room9->setBottom(room8);

	//iniitialize "current room" pointer
	currentRoom = room0;

}

//destructor
GameBoard::~GameBoard() {
	delete room0;
	delete room1;
	delete room2;
	delete room3;
	delete room4;
	delete room5;
	delete room6;
	delete room7;
	delete room8;
	delete room9;
	delete player;
}


/*********************************************************************
** Description: introduction explains to user how to play game.
*********************************************************************/
void GameBoard::introduction() {
	std::cout << "Welcome to the Escape the Dungeon game." << std::endl;
	std::cout << "The goal of this game is to navigate your Battle Mage (player controlled character)" << std::endl;
	std::cout << "out of the dungeon." << std::endl;
	std::cout << "To do this you must first defeat the two mini bosses (denoted by the ^ and * on the dungeon map)" << std::endl;
	std::cout << "to gain tomes which will teach your Battle Mage new spells key to defeating the final boss ('!' on map).\n" << std::endl;
	std::cout << "Note: this game is on a movement limit!" << std::endl;
	std::cout << "After 15 steps the game will automatically end with a loss! \n" << std::endl;
	std::cout << "Controls:\n";
	std::cout << "When prompted, you will have the option of moving to the next space on the board." << std::endl;
	std::cout << "Your character (escaped Battle Mage) is denoted by a the character 'o' on the map." << std::endl;
	//std::cout << "Walls are represented by the '#' character." << std::endl;
	std::cout << "You will be prompted to enter: A (move left) W (move up) S (move down) D (move right).\n" << std::endl;
	std::cout << "Hints:" << std::endl;
	std::cout << "Defeat the Fire Lord First denoted by the '^' character, then defeat the Ice Boss denoted  " << std::endl;
	std::cout << "by the '*' character before facing the final boss denoted by the '!' character." << std::endl;
}

/*********************************************************************
** Description: moveCharacter prompts user to move character in a given direction.
** and then calls that room's special event function.
*********************************************************************/
void GameBoard::moveCharacter() {
	int status;		//for input validation
	char input;		//for user input
	int error;		//for user input validation
	int error2;		//count for validating that the next space is not a nullptr
	Space *temp;	//temp pointer for verifying that movement is valid

	error2 = 0;
	do {
		if (error2 > 0) {
			std::cout << "You cannot move in that direction. Please enter a different space to move to." << std::endl;
		}

		//prompt the user to enter a bearing
		error = 0;
		do {
			std::cout << "Enter a direction to move in (A - left, S - down, D - right, W - up)" << std::endl;
			if (error > 0) {
				std::cout << "Invalid input entered. Please select a valid direction to move in." << std::endl;
			}
			error++;
		} while ((status = getValidChar(&input)) != 0 || !(input == 'a' || input == 's' || input == 'd' || input == 'w'));

		if (input == 'a') {
			temp = currentRoom->getLeft();
		}
		else if (input == 's') {
			temp = currentRoom->getBottom();
		}
		else if (input == 'd') {
			temp = currentRoom->getRight();
		}
		else if (input == 'w') {
			temp = currentRoom->getTop();
		}
		else {
			std::cout << "Critical Error." << std::endl;
			exit(1);
		}
		error2++;
	} while (temp == nullptr);
	//update currentRoom variable
	currentRoom = temp;
}

/*********************************************************************
** Description: useItems is the last phase prior to moving to another space where
** the player gets a chance to use items in his backpack.
*********************************************************************/
void GameBoard::useItems() {
	int status;		//for input validation
	float choice;   //for user input
	int error;		//for user input validation
	
	std::cout << "Before moving to the next room... " << std::endl;
	error = 0;
	do {
		if (error > 0) {
			std::cout << "Invalid input." << std::endl;
		}
		std::cout << "View bag contents and select an item to use?" << std::endl;
		std::cout << "Enter 1. to view bag contents." << std::endl;
		std::cout << "Enter 2. to continue without viewing item storage." << std::endl;
		error++;
	} while ((status = getInt(&choice) != 0) || choice < 1 || choice > 2);

	if (choice == 1) {
		player->useItem();
	}

}

/*********************************************************************
** Description: gameLoop provides a primary interface for the user with the
** Dungeon Escape game. Loops until objective is complete or characacter controlled
** player dies or runs out of steps "lantern oil".
*********************************************************************/
void GameBoard::gameLoop() {
	int status;
	bool playAgain;
	char selection;
	int error;
	
	do {
		playAgain = false;		//reinitialize player selection bool

		//display map
		std::cout << "\n\n\n\n" << std::endl;
		printBoard(currentRoom->getID());
		std::cout << "\n" << std::endl;
		
		//prompt the user to move
		moveCharacter();

		//display updated map
		std::cout << "\n";
		printBoard(currentRoom->getID());
		std::cout << "\n";

		//update StepCount
		gameTimer--;
		std::cout << "Steps remaining: " << gameTimer << std::endl;

		//activate the next room's special event
		if (currentRoom != room0) {
			currentRoom->specialEvent(player);
		}

		//initiate recovery phase - a chance to use items
		if (player->getPlayerHealth() > 0 && player->getEndGameStatus() == false) {
			useItems();
		}
		
		
		//display current stats
		std::cout << "Current Hit Points (Health):      " << player->getPlayerHealth() << std::endl;
		if (player->getPlayerHealth() > 0 && player->getEndGameStatus() == false) {
			std::cout << "Current level of Battle Mage:     " << player->getLevel() << std::endl;
			std::cout << "Base Damage:                      " << player->getLevel() << std::endl;;
			std::cout << "Exp needed for next level         " << (player->getExpCap()) - (player->getExpPoints()) << std::endl;


			//prompt the user to continue playing or quit
			error = 0;
			do {
				if (error > 0) {
					std::cout << "Invalid input." << std::endl;
				}
				std::cout << "Continue Playing? (y/n) " << std::endl;
				error++;
				
			} while ((status = getValidChar(&selection)) != 0 || !(selection == 'y' || selection == 'n'));

			if (selection == 'y') {
				playAgain = true;
			}
			else {
				playAgain = false;
			}
		}

	} while (player->getEndGameStatus() == false && (player->getPlayerHealth()) > 0 && gameTimer > 0 && playAgain == true);
	//loss by running out of steps
	if (gameTimer == 0) {
		std::cout << "Uh oh... You ran out of steps!" << std::endl;
		std::cout << "YOU HAVE DIED." << std::endl;
		std::cout << "GAME OVER." << std::endl;
	}
	//loss by defeat
	else if ((player->getPlayerHealth()) <= 0) {
		std::cout << "No hit points left... gg no re..." << std::endl;
		std::cout << "YOU HAVE DIED." << std::endl;
		std::cout << "GAME OVER." << std::endl;
	}
	//win
	else if (player->getEndGameStatus() == true) {
		std::cout << "********************************************************" << std::endl;
		std::cout << "********************************************************" << std::endl;
		std::cout << "********************************************************" << std::endl;
		std::cout << "Congratulations! You made it out of the dungeon alive!" << std::endl;
	}
	else {
		std::cout << "Thank you for playing. Program will now exit." << std::endl;
	}
}



/*********************************************************************
** Description: printBoard displays the dungeon where the player is denoted by the 'o'
** mini bosses are denoted by "*" and the final boss is denoted by the '!' character
*********************************************************************/
void GameBoard::printBoard(int roomIn) {
	if (roomIn == 0) {
		grid[5][3] = 'o';
		generateGrid();
		grid[5][3] = ' ';
	}
	else if (roomIn == 1) {
		grid[4][3] = 'o';
		generateGrid();
		grid[4][3] = ' ';
	}
	else if (roomIn == 2) {
		grid[3][3] = 'o';
		generateGrid();
		grid[3][3] = ' ';
	}
	else if (roomIn == 3) {
		grid[3][2] = 'o';
		generateGrid();
		grid[3][2] = ' ';
	}
	else if (roomIn == 4) {
		grid[3][1] = 'o';
		generateGrid();
		grid[3][1] = '^';
	}
	else if (roomIn == 5) {
		grid[2][3] = 'o';
		generateGrid();
		grid[2][3] = ' ';
	}
	else if (roomIn == 6) {
		grid[2][4] = 'o';
		generateGrid();
		grid[2][4] = ' ';
	}
	else if (roomIn == 7) {
		grid[2][5] = 'o';
		generateGrid();
		grid[2][5] = '*';
	}
	else if (roomIn == 8) {
		grid[1][3] = 'o';
		generateGrid();
		grid[1][3] = ' ';
	}
	else {
		grid[0][3] = 'o';
		generateGrid();
		grid[0][3] = '!';
	}

}

/*********************************************************************
** Description: generateGrid displays the grid that represents the playing field.
*********************************************************************/
void GameBoard::generateGrid() {
	for (int i = 0; i < MAP_ROWS; i++) {
		for (int k = 0; k < MAP_COLS; k++) {
			std::cout << grid[i][k];
		}
		std::cout << "\n";
	}
}