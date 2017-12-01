/*********************************************************************
** Program name: Final Project
** Author: Mario Franco-Munoz
** Date: 11/27/2017
** Description: Source file for the FinalBoss class. FinalBoss class is
** an inherited Space class that represents a space containing the Final Boss
** of the game.
*********************************************************************/

#include "FinalBossRoom.hpp"

//constructor
FinalBossRoom::FinalBossRoom(int input) :Space(){
	this->spaceId = input;
	this->baseAttack = 999;
	this->hitpoints = 35;
}


/*********************************************************************
** Description: in this version of a Special event the player controled BattleMage
** does battle with the final Boss.
*********************************************************************/
void FinalBossRoom::specialEvent(BattleMage *ptrIn) {
	BattleMage *temp = ptrIn;
	int status;				//user valiation variable
	float choice;			//input from user
	int error;				//user valiation variable
	int dmg;				//temp variable for storing damage
	int hp;					//temp variable for storing hit points
	int exp;				//temp variable for storing exp points
	std::string spellCast;	//temp variable for storing spell cast
	bool frostShieldActive = false;
	int phase = 0;				//final boss has a charge phase, attack, and recharge phase

	if (hitpoints <= 0) {
		std::cout << "Only a shallow puddle of water remains..." << std::endl;
	}

	//BattleMage and Final Boss
	else {
		std::cout << "********************************************" << std::endl;
		std::cout << "A large and powerful demon lord looms over you..." << std::endl;
		std::cout << "Defeat this boss and you will finally escape the dungeon." << std::endl;

		//battle loop
		while (temp->getPlayerHealth() > 0 && this->hitpoints > 0) {
			phase++;					//boss attack phase counter
			error = 0;
			do {
				if (error > 0) {
					std::cout << "Invalid input. Please select a valid spell." << std::endl;
				}
				//display spells to cast
				temp->displaySpells();
				error++;
			} while ((status = getInt(&choice)) != 0 || choice < 1 || static_cast<int>(choice) > temp->spellCount());

			//calculate damage
			//dmg vs final boss
			dmg = temp->dealDamage();

			spellCast = temp->retSingleSpell(static_cast<int>(choice));
			std::cout << "You cast " << spellCast << std::endl;
			if (spellCast == "Ice Shield") {
				frostShieldActive = true;
				dmg = 0;
				std::cout << " and prevent all incomming damage from next attack!" << std::endl;
			}
			else {
				std::cout << " and deal " << dmg << " damage." << std::endl;
				dmg = temp->dealDamage();	
			}
			this->hitpoints -= dmg;

			//reset damage variable
			dmg = 0;


			//Final Boss vs player
			if (phase == 1) {
				std::cout << "The Demon Lord is charging a powerful attack!" << std::endl;
			}
			else if (phase == 2) {
				std::cout << "The Demon Lord unleashes Grasp of Darkness!" << std::endl;
				if (frostShieldActive == true) {
					frostShieldActive = false;
					std::cout << "The ice shield absorbed all damage!" << std::endl;
					dmg = 0;
				}
				else if (frostShieldActive == false) {
					std::cout << "Maximum damage dealt!" << std::endl;
					dmg = 999;
				}
			}
			else if (phase == 3) {
				std::cout << "The Demon Lord is recharging his dark powers...." << std::endl;
				std::cout << "He cannot attack this turn!" << std::endl;
				//reset phase counter
				phase = 0;
			}

			hp = temp->getPlayerHealth();
			hp -= dmg;
			temp->setPlayerHealth(hp);
		

			//display round results
			std::cout << "Your remaining health: " << temp->getPlayerHealth() << std::endl;
			std::cout << "Enemy remaining health: " << hitpoints << "\n" << std::endl;

		}
		if (temp->getPlayerHealth() > 0) {
			//aquire loot (frost shield)
			std::cout << "The final boss has fallen!!!" << std::endl;
			std::cout << "You have broken free!" << std::endl;
			temp->setEndGameStatus(true);

		}

		//apply experience points
		exp = temp->getExpPoints();
		exp += EXP_YIELD;
		temp->setExpPoints(exp);
		//call levelup function to see if experience points result in level increase
		while (temp->getExpPoints() >= temp->getExpCap()) {
			temp->levelUp();
		}
	}
}
