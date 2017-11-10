/*********************************************************************
** Program name: Project 3 & 4 (Fantasy Combat Game)
** Author: Mario Franco-Munoz
** Date: 10/27/2017
** Description: Source file for Game class.
** Game class contains the primary functionalies of the fantasy combat game. Functionality includes:
** Battles between the different  characters of the game, user prompts, character info, results,
** and game loop.
*********************************************************************/

#include "Game.hpp"

Game::Game() {
	round = 1;
}



/*********************************************************************
** Description: introduction function introduces users to the game 
*********************************************************************/
void Game::introduction() {
	std::cout << "Welcome to Fantasy Combat Game." << std::endl;
	std::cout << "Game begins by chosing two mythical oponents to do battle battle commences." << std::endl;
	std::cout << "First battle is broken down by round, where each round has the following: " << std::endl;
	std::cout << "Phase 1:   Attacks are declared and damage dice rolls and effects are enacted." << std::endl;
	std::cout << "Phase 2:   Special abilities that affect the outcome of the battle are resolved." << std::endl;
	std::cout << "Phase 3:   Damage is calculated (where dmg = Dmg Dealt - defense - armor)" << std::endl;
	std::cout << "Phase 4:   Additional special effects if applicable are resolved.\n" << std::endl;
	std::cout << "Battle continues until only one team remains!\n" << std::endl;
}


/*********************************************************************
** Description: menu prompts user to select fighters for Fantasy Combat.
*********************************************************************/
void Game::menu() {
	float choice;
	int status;
	int charSelect = 0;
	Character *ptr = nullptr;
	int teamCount;
	std::string name;
	int error;

	//prompt user to enter number of characters for each team and validate input
	error = 0;
	do {
		std::cout << "To begin, please enter how many chacters each team will contain. (Min: 1, Max: 50)." << std::endl;
		if (error != 0) {
			std::cout << "Invalid input. Please enter a number between 1 and 50" << std::endl;
		}
		error++;
	} while ((status = getInt(&choice) != 0) || choice > 50 || choice < 1);

	teamCount = static_cast<int>(choice);

	for (int i = 0; i < 2; i++) {
		charSelect = 0;
		std::cout << "Please enter the characters (and their names) for team " << i + 1 << " : \n" << std::endl;
		while (charSelect < teamCount) {

			error = 0;
			//do-while loop to present options to users.
			do {
				if (error != 0) {
					std::cout << "Invalid selection. Please enter a valid menu selection. [1-5]" << std::endl;
				}
				std::cout << "Please select your fighters! Choose a number for fighter " << charSelect + 1 << ":" << std::endl;
				std::cout << "1.    Vampire" << std::endl;
				std::cout << "2.    Barbarian" << std::endl;
				std::cout << "3.    Blue Men" << std::endl;
				std::cout << "4.    Medusa" << std::endl;
				std::cout << "5.    Harry Potter" << std::endl;
				error++;
			} while (((status = getInt(&choice)) != 0) || (choice < 1 || choice > 5));

			//create Vampire if applicable
			if (static_cast<int>(choice) == 1) {
				//create character
				ptr = new Vampire;
				
				//prompt user for name
				std::cout << "Enter the " << ptr->getType() << "'s name:" << std::endl;
				
				//store and set name
				getline(std::cin, name);
				ptr->setName(name);
				
				//add to the appropriate team
				if (i == 0) {
					team1.addBack(ptr);
				}
				else {
					team2.addBack(ptr);
				}
			}
			//create Barbarian if applicable
			else if (static_cast<int>(choice) == 2) {
				ptr = new Barbarian;
				std::cout << "Enter the " << ptr->getType() << "'s name:" << std::endl;
				getline(std::cin, name);
				ptr->setName(name);
				if (i == 0) {
					team1.addBack(ptr);
				}
				else {
					team2.addBack(ptr);
				}

			}
			//create BlueMen if applicable
			else if (static_cast<int>(choice) == 3) {
				ptr = new BlueMen;
				std::cout << "Enter the " << ptr->getType() << "'s name:" << std::endl;
				getline(std::cin, name);
				ptr->setName(name);
				if (i == 0) {
					team1.addBack(ptr);
				}
				else {
					team2.addBack(ptr);
				}
			}
			//create Medusa if applicable
			else if (static_cast<int>(choice) == 4) {
				ptr = new Medusa;
				std::cout << "Enter the " << ptr->getType() << "'s name:" << std::endl;
				getline(std::cin, name);
				ptr->setName(name);
				if (i == 0) {
					team1.addBack(ptr);
				}
				else {
					team2.addBack(ptr);
				}
			}
			else {
				ptr = new HarryPotter;
				std::cout << "Enter the " << ptr->getType() << "'s name:" << std::endl;
				getline(std::cin, name);
				ptr->setName(name);
				if (i == 0) {
					team1.addBack(ptr);
				}
				else {
					team2.addBack(ptr);
				}
			}
			charSelect++;
		}
	}
}


/*********************************************************************
** Description: gameLoop function prompts to user to continue running Fantasy Combat battles
** or exit program after each battle concludes.
*********************************************************************/
void Game::gameLoop() {
	float choice;
	int status = 0;
	int error;
	introduction();
	
	do {
		//main order of events: menu, tournament until one team is exausted of all players, display results
		menu();
		tournament();
		displayResults();

		error = 0;
		do {
			if (error != 0) {
				std::cout << "Invalid menu selection. Please select 1 to battle again or 2 to exit program." << std::endl;
			}
			std::cout << "1.      Play again?" << std::endl;
			std::cout << "2.      Exit program." << std::endl;
			error++;
		} while (status = getInt(&choice) != 0 || (choice > 2) || (choice < 1));

		team1.clearQueue();
		team2.clearQueue();
		grave.clearQueue();

		round = 0;
	} while (choice == 1);
	std::cout << "Thank you for playing Fantasy Combat Game!!!" << std::endl;
}

/*********************************************************************
** Description: tournament (an update to the Fantasy Combat Game) is where the two teams
** do battle. Characters that are defeated are sent to the "grave" CharQueue and the winner
** recovers for a random amount of health.
*********************************************************************/
void Game::tournament() {
	Character *fighter1;
	Character *fighter2;
	int f1_startHealth;
	int f2_startHealth;
	double recoveryMult;
	double temp;
	int updatedHealth;

	//Display teams
	std::cout << "******************************************************************" << std::endl;
	std::cout << "Teams (in fight order) are:" << std::endl;
	std::cout << "Team1: ";
	team1.printQueue();
	std::cout << "Team2: ";
	team2.printQueue();
	std::cout << "******************************************************************" << std::endl;

	while (team1.isEmpty() == false && team2.isEmpty() == false) {
		//copy the first fighter from each respective team into the "fight" vector
		fighter1 = team1.getFront();
		fighter2 = team2.getFront();

		//save the starting health/strength of both fighters (for later recovery of winner)
		f1_startHealth = fighter1->getStrength();
		f2_startHealth = fighter2->getStrength();

		//call fight function after vector has been loaded
		characters.push_back(fighter1);
		characters.push_back(fighter2);

		fight();

		//find the victor and the loser and send to graveyard
		if (fighter1->getStrength() <= 0) {
			grave.addBack(fighter1);
			characters.pop_back();
			team1.removeFront();

			//recovery for winner - recovery can be anywhere between 10 and 50%
			//of health
			recoveryMult = static_cast<double>(randNoGen(1, 5)) / 10.0;
			temp = static_cast<double>(f2_startHealth) *  recoveryMult;
			//display recovered hitpoints
			std::cout << team2.getFront()->getName() << " recovered " << static_cast<int>(temp) << " hitpoints!" << std::endl;

			updatedHealth = fighter2->getStrength() + static_cast<int>(temp);
			fighter2->setStrength(updatedHealth);

			//call sendFrontToBack
			team2.sendFrontToBack();
			//finish clearing the characters vector.
			characters.pop_back();

		}
		else {
			grave.addBack(fighter2);
			characters.pop_back();
			team2.removeFront();

			//recovery for winner - recovery can be anywhere between 10 and 50%
			//of max health
			recoveryMult = static_cast<double>(randNoGen(1, 5)) / 10.0;
			temp = static_cast<double>(f1_startHealth) *  recoveryMult;
			std::cout << team1.getFront()->getName() << " recovered " << static_cast<int>(temp) << " hitpoints!" << std::endl;

			updatedHealth = fighter1->getStrength() + static_cast<int>(temp);
			fighter1->setStrength(updatedHealth);

			//call sendFrontToBack
			team1.sendFrontToBack();
			//finish clearing the characters vector
			characters.pop_back();
		}

	}
}


/*********************************************************************
** Description: fight function operates the fighting in Fantasy Combat battles by phases. 
*********************************************************************/
void Game::fight() {
	int damage1;
	int damage2;
	int diceRoll;
	int temp;
	std::string special1;
	std::string special2;
	
	std::cout << "*********IT'S TIME TO THROW DOWN! ************" << std::endl;
	std::cout << "COMBATANT #1:     " << characters[0]->getType() << std::endl;
	std::cout << "COMBATANT #2:     " << characters[1]->getType() << std::endl;

	//continue fight until only one survives.
	while (characters[0]->getStrength() > 0 && characters[1]->getStrength() > 0) {
		std::cout << "************ROUND " << round << " ****************************" << std::endl;
		std::cout << "*" << std::endl;
		std::cout << "*" << std::endl;
		std::cout << "************************************************" << std::endl;
		//set attack damage and defense for round
		characters[0]->setAttackDmg();
		characters[0]->setDefense();
		characters[1]->setAttackDmg();
		characters[1]->setDefense();

		//store specials
		special1 = characters[0]->getSpecial();
		special2 = characters[1]->getSpecial();

		//store rolled damage
		damage1 = characters[0]->getDamage();
		damage2 = characters[1]->getDamage();


		//calculate damage (first attacker)
		std::cout << "**********CHARACTER 1 ATTACK!!!************" << std::endl;
		std::cout << std::left << std::setw(30) << "Attacker type:" << characters[0]->getType() << std::endl;
		std::cout << std::left<< std::setw(30) << "Unmitigated attacker damage:" << damage1 << std::endl;
		std::cout << std::left << std::setw(30) << "Defender type:" << characters[1]->getType() << std::endl;
		std::cout << std::left << std::setw(30) << "Defender Armor:" << characters[1]->getArmor() << std::endl;
		std::cout << std::left << std::setw(30) << "Defender Strength:" << characters[1]->getStrength() << std::endl;
		std::cout << std::left << std::setw(30) << "Defender Defense roll:" << characters[1]->getDefense() << std::endl;
		std::cout << "\n";
		//put specials on the stack
		//special ability "Glare"
		if (special1 == "Glare" && damage1 == 12) {
			std::cout << characters[0]->getType() << " Glare ability has been activated! Max damage dealt!" << std::endl;
			damage1 = 999;
		}
		//Special ability "Charm" 50% chance to reduce incomming atk damage to 0.
		if (special2 == "Charm") {
			diceRoll = randNoGen(1, 2);
			if (diceRoll == 2) {
				std::cout << characters[1]->getType() << " Charm ability has been activated!" << std::endl;
				damage1 = 0;
			}
		}
		std::cout << "\n";
		std::cout << "************DAMAGE CALCULATION STEP***********" << std::endl;
		damage1 = damage1 - characters[1]->getArmor() - characters[1]->getDefense();
		if (damage1 < 0) {
			damage1 = 0;
		}		
		temp = characters[1]->getStrength();
		characters[1]->setStrength(temp - damage1);
		
		//additional specials
		if (special2 == "Hogwarts" && characters[1]->getStrength() <=0) {
			if (characters[1]->getGeneralFlag() == true) {
				std::cout << characters[1]->getType() << " Hogwarts ability has been activated!!!!!!!!!!!!!!!" << std::endl;
				characters[1]->setStrength(20);
				characters[1]->setGeneralFlag(false);
			}
		}
		//display damage stats
		std::cout << std::left << std::setw(30) << "Damage dealt (actual):" << damage1 << std::endl;
		std::cout << std::left << std::setw(30) << "Remaining Strength:" << characters[1]->getStrength() <<"\n" <<std::endl;


		if (characters[1]->getStrength() <= 0) {
			characters[1]->setStrength(0);
			std::cout << "K.O.!!!!!!!" << std::endl;
			std::cout << characters[0]->getName() << " a ";
			std::cout << characters[0]->getType() << "(from team 1) has won!!!" << std::endl;
			std::cout << "\n" << std::endl;
		}

		if (characters[1]->getStrength() > 0) {

			//calculate damage (second attacker)
			std::cout << "**********CHARACTER 2 ATTACK!!!************" << std::endl;
			std::cout << std::left << std::setw(30) << "Attacker type:" << characters[1]->getType() << std::endl;
			std::cout << std::left << std::setw(30) << "Unmitigated attacker damage:" << damage2 << std::endl;
			std::cout << std::left << std::setw(30) << "Defender type:" << characters[0]->getType() << std::endl;
			std::cout << std::left << std::setw(30) << "Defender Armor:" << characters[0]->getArmor() << std::endl;
			std::cout << std::left << std::setw(30) << "Defender Strength:" << characters[0]->getStrength() << std::endl;
			std::cout << std::left << std::setw(30) << "Defender Defense roll:" << characters[0]->getDefense() << std::endl;
			std::cout << "\n";
			//put specials on the stack
			//special ability "Glare"
			if (special2 == "Glare" && damage2 == 12) {
				std::cout << characters[1]->getType() << " Glare ability has been activated! Max damage dealt!!!!!!!!" << std::endl;
				damage2 = 999;
			}
			//Special ability "Charm" 50% chance to reduce incomming atk damage to 0.
			if (special1 == "Charm") {
				diceRoll = randNoGen(1, 2);
				if (diceRoll == 2) {
					std::cout << characters[0]->getType() << " Charm ability has been activated!" << std::endl;
					damage2 = 0;
				}
			}
			std::cout << "\n";
			std::cout << "************DAMAGE CALCULATION STEP***********" << std::endl;
			damage2 = damage2 - characters[0]->getArmor() - characters[0]->getDefense();
			//in case armor + defense roll exceeds the damage dealt:
			if (damage2 < 0) {
				damage2 = 0;
			}
			//calculate damage (prior to any life-saving special effects)
			temp = characters[0]->getStrength();
			characters[0]->setStrength(temp - damage2);

			//additional specials
			if (special1 == "Hogwarts" && characters[0]->getStrength() <= 0) {
				if (characters[0]->getGeneralFlag() == true) {
					std::cout << characters[0]->getType() << " Hogwarts ability has been activated!!!!!!!!!!!!!!!" << std::endl;
					characters[0]->setStrength(20);
					characters[0]->setGeneralFlag(false);
				}
			}

			//display damage stats
			std::cout << std::left << std::setw(30) << "Damage dealt (actual):" << damage2 << std::endl;
			std::cout << std::left << std::setw(30) << "Remaining Strength:" << characters[0]->getStrength() << "\n" << std::endl;
			
			if (characters[0]->getStrength() <= 0) {
				std::cout << "K.O.!!!!!!!" << std::endl;
				std::cout << characters[1]->getName() << " a ";
				std::cout << characters[1]->getType() << "(from team 2) has won!!!" << std::endl;
				std::cout << "\n" << std::endl;
			}
			round++;
		}
	}
	
}

/*********************************************************************
** Description: displayResults displays the members of the winning team and provides
** the user the option of viewing characters that lost matchups.
*********************************************************************/
void Game::displayResults() {
	int status;
	float choice;
	int error;

	if (team1.isEmpty() == true) {
		std::cout << "TEAM 2 HAS EMERGED VICTORIOUS!!!!!!" << std::endl;
		std::cout << "Team 2 members still standing:" << std::endl;
		team2.printQueue();
	}
	else {
		std::cout << "TEAM 1 HAS EMERGED VICTORIOUS!!!!!!" << std::endl;
		std::cout << "Team 1 members still standing:" << std::endl;
		team1.printQueue();
	}

	std::cout << "Display list of fallen warriors?" << std::endl;
	
	error = 0;
	do {
		std::cout << "Enter \"1\" to display contents of graveyard." << std::endl;
		std::cout << "Enter \"2\" to continue without displaying graveyard." << std::endl;
		if (error != 0) {
			std::cout << "Invalid input. Please enter a 1 or 2." << std::endl;
		}
		error++;
	} while ((status = getInt(&choice) != 0) || choice < 1  || choice > 2);

	if (choice == 1) {
		grave.printQueue();
	}

}