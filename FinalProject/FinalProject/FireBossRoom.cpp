/*********************************************************************
** Program name: Final Project
** Author: Mario Franco-Munoz
** Date: 11/27/2017
** Description: Source file for the FireBossRoom class. FireBoss class is
** an inherited Space class that represents a space containing a FireBoss
** (mini boss that must be defeated in order to complete the game).
*********************************************************************/

#include "FireBossRoom.hpp"

FireBossRoom::FireBossRoom(int idIn) :Space() {
	this->spaceId = idIn;
	this->baseAttack = 1;
	this->hitpoints = 15;
	this->creatureType = "fire";
}


/*********************************************************************
** Description: in this version of a Special event the player controled BattleMage
** does battle with a mini boss (Fire Elemental).
*********************************************************************/
void FireBossRoom::specialEvent(BattleMage *ptrIn) {
	BattleMage *temp = ptrIn;
	int status;				//user valiation variable
	float choice;			//input from user
	int error;				//user valiation variable
	int rand;				//for storing output random generated number
	int dmg;				//temp variable for storing damage
	int hp;					//temp variable for storing hit points
	int exp;				//temp variable for storing exp points

	if (hitpoints <= 0) {
		std::cout << "Only the smoldering ashes of what is left of the fire lord remain..." << std::endl;
	}

	//BattleMage and MiniBoss: Fire Lord do battle
	else {
		std::cout << "********************************************" << std::endl;
		std::cout << "The air suddently grows warmer..." << std::endl;
		std::cout << "Firelord Ozai-ki is preparing his first attack!" << std::endl;

		//battle loop
		while (temp->getPlayerHealth() > 0 && this->hitpoints > 0) {

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
			//dmg vs Firelord
			dmg = temp->dealDamage();
			this->hitpoints -= dmg;
			std::cout << "You cast " << temp->retSingleSpell(static_cast<int>(choice));
			std::cout << " and deal " << dmg << " damage." << std::endl;

			//reset damage variable
			dmg = 0;

			//firelord vs player
			rand = randNoGen(1, 3);
			if (rand == 1) {
				std::cout << "The firelord casts fireball!" << std::endl;
				dmg = this->baseAttack * randNoGen(3, 5);
			}
			else if (rand == 2) {
				std::cout << "The firelord casts radiant flames!" << std::endl;
				dmg = this->baseAttack * randNoGen(1, 3);
			}
			else {
				std::cout << "The firelord hurls a flaming spear!" << std::endl;
				dmg = this->baseAttack * randNoGen(2, 3);
			}
			hp = temp->getPlayerHealth();
			hp -= dmg;
			temp->setPlayerHealth(hp);
			std::cout << "The firelord deals " << dmg << " damage." << std::endl;

			//display round results
			std::cout << "Your remaining health: " << temp->getPlayerHealth() << std::endl;
			std::cout << "Enemy remaining health: " << hitpoints << "\n" << std::endl;

		}
		if (temp->getPlayerHealth() > 0) {
			//aquire loot (tome of fire)
			std::cout << "You have aquired the tomb of fire!" << std::endl;
			std::cout << "Use the tome to learn a new fire spell!" << std::endl;
			std::cout << "Nice, the Fire Lord also was carrying a health potion!" << std::endl;
			temp->addToBag("Tome of Fire");
			temp->addToBag("Health Potion");
		
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