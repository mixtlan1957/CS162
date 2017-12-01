/*********************************************************************
** Program name: Final Project
** Author: Mario Franco-Munoz
** Date: 11/27/2017
** Description: Source file for MobsRoom class. MobsRoom class represents a space
** with an enemy demon that must be defeated.
*********************************************************************/


#include "MobsRoom.hpp"


//(copy) constructor
MobsRoom::MobsRoom(int idIn) :Space() {
	this->spaceId = idIn;
	this->creatureBaseAtk = 1;
	this->creatureStrength = 10;
}


/*********************************************************************
** Description: in this version of a Special event the player controled BattleMage
** does battle with a creature inhabiting the space.
*********************************************************************/
void MobsRoom::specialEvent(BattleMage *ptrIn) {
	BattleMage *temp = ptrIn;
	int status;				//user valiation variable
	float choice;			//input from user
	int error;				//user valiation variable
	int rand;				//for storing output random generated number
	int dmg;				//temp variable for storing damage
	int hp;					//temp variable for storing hit points
	int exp;				//temp variable for storing exp points
	std::string spellCast;

	if (creatureStrength <= 0) {
		std::cout << "Only the mangled corpse of a demon and it's stench remains..." << std::endl;
	}

	//BattleMage and demon do battle
	else {
		std::cout << "********************************************" << std::endl;
		std::cout << "Uh oh... There is a demon blocking the path." << std::endl;
		

		//battle while loop between room's "mob" and player controlled character
		while (temp->getPlayerHealth() > 0 && this->creatureStrength > 0) {
			//prompt user to cast a spell
			error = 0;
			do {
				if (error > 0) {
					std::cout << "Invalid input. Please select a valid spell." << std::endl;
				}
				//display spells to cast
				temp->displaySpells();
				error++;
			} while ((status = getInt(&choice)) != 0 || choice < 1 ||  static_cast<int>(choice) > temp->spellCount());
		
			//calculate damage
			//dmg vs mob
			dmg = temp->dealDamage();
			
			spellCast = temp->retSingleSpell(static_cast<int>(choice));
			std::cout << "You cast " << spellCast << std::endl;
			if (spellCast == "Ice Shield") {
				std::cout << "Ice Shield will prevent incoming damage!" << std::endl;
				dmg = 0;
			}
			std::cout << " and deal " << dmg << " damage." << std::endl;
			this->creatureStrength -= dmg;

			//mob vs player
			if (spellCast != "Ice Shield") {
				dmg = this->creatureBaseAtk * randNoGen(0, 4);
				hp = temp->getPlayerHealth();
				hp -= dmg;
				temp->setPlayerHealth(hp);
				std::cout << "The creature deals " << dmg << " damage." << std::endl;
			}
			else {
				std::cout << "All incomming damage prevented by Ice Shield!" << std::endl;
			}
			//display round results
			std::cout << "Your remaining health: " << temp->getPlayerHealth() << std::endl;
			std::cout << "Enemy remaining health: " << creatureStrength << "\n" << std::endl;
		
		}

		if (temp->getPlayerHealth() > 0) {
			//aquire loot (let there be a 40% chance to pick up a healing potion)
			std::cout << "The demon in the room has been defeated!" << std::endl;
			rand = randNoGen(1, 5);
			if (rand == 1 || rand == 2) {
				std::cout << "Oh look! The demon was carying a health potion." << std::endl;
				temp->addToBag("Health Potion");
			}
			else {
				std::cout << "Demon had nothing on him to loot...\n" << std::endl;
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
	std::cout << "********************************************" << std::endl;
	}
}






