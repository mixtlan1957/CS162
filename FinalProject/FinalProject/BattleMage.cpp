/*********************************************************************
** Program name: Final Project
** Author: Mario Franco-Munoz
** Date: 11/27/2017
** Description: Source file for the Player_BattleMage class. This class represetns
** a player controlled character that used to play the Dungeon Escape game.
*********************************************************************/

#include "BattleMage.hpp"


//default constructor
BattleMage::BattleMage() {
	//initialize map
	for (int i = 1; i <= BACKPACK_SIZE; i++) {
		backpack[i] = "";
	}
	spellbook[1] = "Bolt of Lightining";

	this->health = 15;
	this->maxHP = 15;
	this->exp_Points = 0;
	this->levelUpExp = 10;
	this->level = 1;
	this->baseDamage = 3;
	this->finalBossDefeated = false;
}


/*********************************************************************
** Description: setPlayerHealth sets the health of the BattleMage
*********************************************************************/
void BattleMage::setPlayerHealth(int input) {
	this->health = input;

}

/*********************************************************************
** Description: setExpPoints sets the current exprience points of the BattleMage
*********************************************************************/
void BattleMage::setExpPoints(int input) {
	exp_Points = input;
}


/*********************************************************************
** Description: incLevel increases the level of the character. This doubles
** the number of experience points needed till the next level.
*********************************************************************/
void BattleMage::increaseLevel() {
	this->level++;
}

/*********************************************************************
** Description: setBaseDamage is used to update the base damage of the BattleMage
** when she goes up in level.
*********************************************************************/
void BattleMage::incBaseDamage() {
	this->baseDamage++;
}

/*********************************************************************
** Description: getPlayerHealth returns the current health of the BattleMage
*********************************************************************/
int BattleMage::getPlayerHealth() {
	return this->health;
}

/*********************************************************************
** Description: getExpPoints returns the current exp points of the BattleMage
*********************************************************************/
int BattleMage::getExpPoints() {
	return this->exp_Points;
}

/*********************************************************************
** Description: getLevel returns the current level that the BattleMage is at.
*********************************************************************/
int BattleMage::getLevel() {
	return this->level;
}

/*********************************************************************
** Description: dealDamage returns an int representing the amount of damage dealt
** by the BattleMage to enemies. 
*********************************************************************/
int BattleMage::dealDamage() {
	return this->baseDamage + randNoGen(0, 3);
}

/*********************************************************************
** Description: displaySingleSpell returns the name of the spell taking as input the
** map index.
*********************************************************************/
std::string BattleMage::retSingleSpell(int selection) {
	return spellbook.at(selection);
}

/*********************************************************************
** Description: levelUp increases the level of the BattleMage and updates the
** stats. 
*********************************************************************/
void BattleMage::levelUp() {	
	if (exp_Points >= levelUpExp) {
		//hit points increase by 1/4th
		this->maxHP = this->maxHP + ((this->maxHP) / 4);

		//base damage increases by 2
		for (int i = 0; i < DMG_INCREASE; i++) {
			incBaseDamage();
		}

		//update current exp points
		exp_Points = levelUpExp - exp_Points;
		
		//increase EXP cap
		levelUpExp *= 2;

		//increase level
		level++;

		//display new level and stats
		std::cout << "You have gained a level! You are now at level " << level << "!" << std::endl;
		std::cout << "Max Hitpoints:       " << maxHP << std::endl;
		std::cout << "Base Damage:         " << baseDamage << std::endl;
	}
}

/*********************************************************************
** Description: addToBag adds an item to the bag. 
*********************************************************************/
void BattleMage::addToBag(std::string itemIn) {
	int status;
	float choice;
	int error;


	//display current bag contents
	std::cout << "Current bag contents:" << std::endl;
	for (auto i = backpack.begin(); i != backpack.end(); i++) {
		std::cout << "Slot " << i->first << ": ";
		std::cout << i->second << std::endl;
	}

	
	//obtain and validate user input
	error = 0;
	do {
		if (error > 0) {
			std::cout << "Invalid input. Please select a bag slot between 1 and 10." << std::endl;
		}
		std::cout << "Add " << itemIn << " to which slot?" << std::endl;
		std::cout << "Enter 0 to discard and do not add to bag." << std::endl;
		error++;
	} while ((status = getInt(&choice)) != 0 || choice < 0 || choice > 10);

	//std::map<int, std::string>::iterator iter = backpack.begin();
	if (choice > 0) {
		backpack.at(static_cast<int>(choice)) = itemIn;
	}
}

/*********************************************************************
** Description: useItem displays the items stored in the bag and prompts user to select
** an item to use.
*********************************************************************/
void BattleMage::useItem() {
	int status;					//user input and validation variables
	float choice;				//user input and validation variables
	int error;					//user input and validation variables
	int error2;					//user input and validation variables
	bool useAnother = false;	
	std::string check;			//user input and validation variables
	int count;					//variable for checking number of items in map

	error2 = 0;
	do {
		if (error2 > 0 && useAnother == false) {
			std::cout << "Invalid input." << std::endl;
		}
		else {
			//reset useAnother flag
			useAnother = false;
		}

		//display current bag contents
		std::cout << "Current bag contents:" << std::endl;
		for (auto i = backpack.begin(); i != backpack.end(); i++) {
			std::cout << "Slot " << i->first << ": ";
			std::cout << i->second << std::endl;
		}

		//prompt user to select an item
		error = 0;
		do {
			if (error > 0) {
				std::cout << "Invalid input. Please select a bag slot between 1 and 10." << std::endl;
			}
			std::cout << "Use which item? (Enter number denoting item you wish to use." << std::endl;
			error++;
		} while ((status = getInt(&choice)) != 0 || choice < 1 || choice > 10);


		check = backpack.at(static_cast<int>(choice));
		if (check == "") {
			std::cout << "There's nothing in that slot to use!" << std::endl;
		}
		//potion case
		else if (check == "Health Potion") {
			std::cout << "Gulp gulp gulp..." << std::endl;
			std::cout << "Health has been restored to full!" << std::endl;
			this->health = this->maxHP;
			//clear the slot
			backpack[static_cast<int>(choice)] = "";
			
		}

		//tome of fire (learn radiant flames)
		else if (check == "Tome of Fire") {
			std::cout << "You have learned a new spell: Fireball!" << std::endl;
			std::cout << "This will be key against your fight against the Ice Lord!" << std::endl;
			backpack[static_cast<int>(choice)] = "";
			spellbook[2] = "Fireball";
		}

		//tome of ice (learn ice shield) 
		else if (check == "Tome of Ice") {
			std::cout << "You have learned a new spell: Ice Shield!" << std::endl;
			std::cout << "Ice shield prevents all damage from incomming attack." << std::endl;
			std::cout << "Very usefull for protecting against strong charged attacks." << std::endl;
			std::cout << "This will be key against your fight against the Final Boss!" << std::endl;
			backpack[static_cast<int>(choice)] = "";
			spellbook[3] = "Ice Shield";
		}

		else {

		}

		//prompt the user if she would like to use another item
		error = 0;
		do {
			if (error > 0) {
				std::cout << "Invalid input. Please enter 1 (select another item) or 2 (continue)." << std::endl;
			}
			std::cout << "Use another item? Enter \"1\" - yes, \"2\" - no." << std::endl;
			error++;
		} while ((status = getInt(&choice)) != 0 || choice < 1 || choice > 2);

		if (choice == 1) {
			useAnother = true;
		}
		else {
			useAnother = false;
		}

	} while (useAnother == true);

}


/*********************************************************************
** Description: displaySpells displays the spells that the player controlled BattleMage
** has at his disposal.
*********************************************************************/
void BattleMage::displaySpells() {

	std::cout << "Select a spell to cast: " << std::endl;
	for (auto i = spellbook.begin(); i != spellbook.end(); i++) {
		std::cout << "Spell " << i->first << ": " << i->second << std::endl;
	}
}

/*********************************************************************
** Description: spellCount returns the number of spells the available. Used for user valiation.
*********************************************************************/
int BattleMage::spellCount() {
	return spellbook.size();
}


/*********************************************************************
** Description: getExpCap returns the total number of exp points needed for next level.
*********************************************************************/
int BattleMage::getExpCap() {
	return this->levelUpExp;
}

/*********************************************************************
** Description: getBaseDamage returns the base damage of the Battle Mage
*********************************************************************/
int BattleMage::getBaseDamage() {
	return this->baseDamage;
}

/*********************************************************************
** Description: getEndGameStatus returns whether or not the final boss has been defeated.
*********************************************************************/
bool BattleMage::getEndGameStatus() {
	return this->finalBossDefeated;
}

/*********************************************************************
** Description: setEndGameStatus updates the "killed final boss" flag.
*********************************************************************/
void BattleMage::setEndGameStatus(bool boolInput) {
	this->finalBossDefeated = boolInput;
}