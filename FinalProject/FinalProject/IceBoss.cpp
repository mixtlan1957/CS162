/*********************************************************************
** Program name: Final Project
** Author: Mario Franco-Munoz
** Date: 11/27/2017
** Description: Source file for the IceBoss class. IceBoss class is
** an inherited Space class that represents a space containing an IceBoss
** (mini boss that must be defeated in order to complete the game).
*********************************************************************/

#include "IceBoss.hpp"

//copy constructor
IceBoss::IceBoss(int idIn) :Space() {
	this->spaceId = idIn;
	this->baseAttack = 1;
	this->hitpoints = 45;
}

/*********************************************************************
** Description: in this version of a Special event the player controled BattleMage
** does battle with a mini boss (Ice Lord).
*********************************************************************/
void IceBoss::specialEvent(BattleMage *ptrIn) {
	BattleMage *temp = ptrIn;
	int status;				//user valiation variable
	float choice;			//input from user
	int error;				//user valiation variable
	int rand;				//for storing output random generated number
	int dmg;				//temp variable for storing damage
	int hp;					//temp variable for storing hit points
	int exp;				//temp variable for storing exp points
	std::string spellCast;	//temp variable for storing spell cast
	bool frostShieldActive = false;

	if (hitpoints <= 0) {
		std::cout << "Only a shallow puddle of water remains..." << std::endl;
	}

	//BattleMage and MiniBoss: Ice Lord do battle
	else {
		std::cout << "********************************************" << std::endl;
		std::cout << "The ground becomes slick and icy..." << std::endl;
		std::cout << "Trost awakens from his slumber as you enter the room!" << std::endl;

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
			//dmg vs icelord
			
			spellCast = temp->retSingleSpell(static_cast<int>(choice));
			dmg = temp->dealDamage();
			std::cout << "You cast " << spellCast << std::endl;
			
			if (frostShieldActive == false) {

				//add multiplier if fire spell is used
				if (spellCast == "Fireball") {
					dmg *= 2;
					std::cout << "...and woah!!! That fire spell is super effective! Double damage dealt!" << std::endl;
					std::cout << "Ice Lord hit for " << dmg << " damage!!!" << std::endl;
				}
				else {
					std::cout << " and deal " << dmg << " damage." << std::endl;
				}
				
				this->hitpoints -= dmg;
			}
			else {
				frostShieldActive = false;
				std::cout << " But the frost shield has absorbed all incoming damage!" << std::endl;
			}
			
			//reset dmg variable
			dmg = 0;

			//Ice Lord vs player
			rand = randNoGen(1, 3);
			if (rand == 1) {
				std::cout << "The Ice Lord casts Blizzard!" << std::endl;
				dmg = this->baseAttack * randNoGen(2, 5);
			}
			else if (rand == 2) {
				std::cout << "The Ice Lord casts Frost Nova!" << std::endl;
				dmg = this->baseAttack * randNoGen(1, 4);
			}
			else {
				std::cout << "The Ice Lord casts Ice Shield!" << std::endl;
				std::cout << "Damage next turn will be negated!" << std::endl;
				frostShieldActive = true;
				dmg = 0;
			}
			hp = temp->getPlayerHealth();
			hp -= dmg;
			temp->setPlayerHealth(hp);
			std::cout << "The Ice Lord deals " << dmg << " damage." << std::endl;

			//display round results
			std::cout << "Your remaining health: " << temp->getPlayerHealth() << std::endl;
			std::cout << "Enemy remaining health: " << hitpoints << "\n" << std::endl;

		}
		if (temp->getPlayerHealth() > 0) {
			//aquire loot (frost shield)
			std::cout << "You have aquired the tomb of ice!" << std::endl;
			std::cout << "Use the tome to learn a new ice spell - frost shield!" << std::endl;
			std::cout << "Oh goodie! The Ice Lord also was carrying a health potion!" << std::endl;
			temp->addToBag("Tome of Ice");
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