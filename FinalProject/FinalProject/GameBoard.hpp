/*********************************************************************
** Program name: Final Project
** Author: Mario Franco-Munoz
** Date: 11/27/2017
** Description: Header file for the GameBoard Class. The GameBoard class
** is where the player's character interacts with the different rooms or squares
** as the player progresses through thte game.
*********************************************************************/

#include "BattleMage.hpp"
#include "DefaultRoom.hpp"
#include "MobsRoom.hpp"
#include "FireBossRoom.hpp"
#include "IceBoss.hpp"
#include "FinalBossRoom.hpp"
#include "char_Input_Val.hpp"



#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP

class GameBoard {
private:
	int gameTimer;
	bool finalBossDefeated;

	BattleMage *player;

	//pointer to point at where the player is currently at
	Space *currentRoom;

	//Spaces representative of the different rooms in the dungeon
	DefaultRoom *room0;
	DefaultRoom *room1;	
	MobsRoom *room2;
	DefaultRoom *room3;   		
	FireBossRoom *room4; 
	MobsRoom *room5;
	DefaultRoom *room6;   
	IceBoss *room7;
	MobsRoom *room8;
	FinalBossRoom *room9;
						

	const int MAP_COLS = 7;
	const int MAP_ROWS = 6;
	char grid[6][7] = { {'X', 'X', 'X', '!', 'X', 'X', 'X'},
						{'X', 'X', 'X', ' ', 'X', 'X', 'X'},
						{'X', 'X', 'X', ' ', ' ', '*', 'X'},
						{ 'X', '*', ' ', ' ', 'X', 'X', 'X' },
						{ 'X', 'X', 'X', ' ', 'X', 'X', 'X' },
						{'X', 'X', 'X', ' ', 'X', 'X', 'X'}, };

public:
	//default constructor
	GameBoard();
	void introduction();
	void gameLoop();
	void printBoard(int);
	void generateGrid();
	void moveCharacter();
	void useItems();

	//destructor
	virtual ~GameBoard();

};
#endif 

