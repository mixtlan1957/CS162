/*********************************************************************
** Program name: Final Project
** Author: Mario Franco-Munoz
** Date: 11/27/2017
** Description: Source file for the BattleMage class. This class represetns
** a player controlled character that used to play the Dungeon Escape game.
*********************************************************************/

#include "randNoGen.hpp"
#include "Integer_Input_Val.hpp"

#include <map>
#include <string>
#include <iterator>
#include <iostream>

#ifndef BATTLEMAGE_HPP
#define BATTLEMAGE_HPP

class BattleMage {
private:
	int health;					//variable to track current health of character
	int maxHP;					//maximum ammount of health of character
	int exp_Points;				//to track current exp points
	int levelUpExp;				//exp threshold for next level up - to vary by level
	int level;
	int baseDamage;				//base damage dealt to enemies
	bool finalBossDefeated;

	const int BACKPACK_SIZE = 10;
	std::map<int, std::string> backpack;

	const int DMG_INCREASE = 2;	// const variable to denote by how much the base damage will increase
								// for each level gained.

	std::map<int, std::string> spellbook;



public:

	//for throwing exceptions
	class OutOfRange {
	};

	//default constructor
	BattleMage();

	//mutators
	void setPlayerHealth(int);
	void setExpPoints(int);
	void increaseLevel();
	void incBaseDamage();
	void setEndGameStatus(bool);

	//accesors
	int getPlayerHealth();
	int getExpPoints();
	int getExpCap();
	int getLevel();
	int dealDamage();
	int getBaseDamage();
	bool getEndGameStatus();
	

	//increase base damage
	void levelUp();

	//add items to backpack
	void addToBag(std::string);
	void useItem();

	//display spells
	void displaySpells();
	std::string retSingleSpell(int);
	int spellCount();


	
};
#endif