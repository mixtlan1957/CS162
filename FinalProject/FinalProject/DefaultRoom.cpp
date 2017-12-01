/*********************************************************************
** Program name: Final Project
** Author: Mario Franco-Munoz
** Date: 11/27/2017
** Description: Source file for the DefaultRoom class. DefaultRoom class is
** an inherited Space class that represents a typical "square" or space on the
** GameBoard.
*********************************************************************/

#include "DefaultRoom.hpp"

//(copy) constructor
DefaultRoom::DefaultRoom(int idIn):Space() {
	this->spaceId = idIn;
	alreadyVisited = false;
}

/*********************************************************************
** Description: for a "defaultRoom" there is a 50% chance that a treasure chest appears.
** the contents of the treasure chest interact with the player in different ways.
*********************************************************************/
void DefaultRoom::specialEvent(BattleMage *input) {
	int status;			//for user selection and input validation
	float choice;		//for user selection and input validation
	int error;			//for input validation
	int rand = 0;		//variable for storing outcome of opening chest
	int temp = 0;		//variable for updating the character's health
	this->charSlot = input;


	if (alreadyVisited == false) {
		//intro
		std::cout << "You slowly open the door to the next room..." << std::endl;
		std::cout << "And..." << std::endl;

		//generate a treasure chest if applicable
		if (randNoGen(1, 2) == 2) {
			std::cout << "There is a treasure chest in this room!" << std::endl;

			//prompt the user for a choice to interact with the treasure chest.
			error = 0;
			do {
				if (error > 0) {
					std::cout << "Incorrect input entered." << std::endl;
				}
				std::cout << "Please select one of the following: " << std::endl;
				std::cout << "1.   Open the chest." << std::endl;
				std::cout << "2.   Leave the chest closed." << std::endl;

				error++;
			} while ((status = getInt(&choice)) != 0 || choice < 1 || choice > 2);

			if (choice == 1) {
				rand = randNoGen(1, 6);
				//outcome 1: nothing in the chest
				if (rand == 1 || rand == 3) {
					std::cout << "Hahaha! The chest is empty!" << std::endl;
				}
				//outcome 2: cursed chest
				else if (rand == 2) {
					std::cout << "Uh oh! This chest was cursed!" << std::endl;
					std::cout << "The curse has inflicted you with 3 points of dark damage!" << std::endl;

					//update the player's health
					temp = charSlot->getPlayerHealth();
					temp -= 3;
					charSlot->setPlayerHealth(temp);

				}
				//outcome 3: health potion
				else if (rand >= 4 && rand <= 6) {
					std::cout << "The chest contnained a health potion!" << std::endl;
					std::cout << "This health potion can be used outside of battle and replenish your HP to full!" << std::endl;
					charSlot->addToBag("Health Potion");
				}
			}
		}
		else {
			std::cout << "...there is nothing here! Just an empty room." << std::endl;
		}
		alreadyVisited = true;
	}
	else {
		std::cout << "You confidently bash the door open - you've already cleared this room." << std::endl;
	}
}

