/*********************************************************************
** Program name: Lab3
** Author: Mario Franco-Munoz
** Date: 10/12/2017
** Description: Header file for Game class.
** Game class represents a game of "war". This game consists of two players that each have a die with
** N-faces of their chosing. Players roll the die x ammount of times (limit of 50 rounds) and face off to see who gets the
** highest number of wins. Players can chose between a normal die and a weighted die which has a considerable higher chance of
** yielding higher results.
*********************************************************************/

#include <iomanip>

#include "Integer_Input_Val.hpp"
#include "Die.hpp"
#include "LoadedDie.hpp"

#ifndef GAME_HPP
#define GAME_HPP

class Game {
private:
	LoadedDie *player1 = nullptr;
	LoadedDie *player2 = nullptr;
	int rounds;
	int currentRound;
	int scoreP1;
	int scoreP2;
	int player1Mode;				//to keep track of if player is playing with normal or loaded die.
	int player2Mode;

public:
	Game();
	void startMenu();
	void initializeGame();
	void displayResults();
	void runGame();
	int getRoundNumber();
	
	~Game() {
		delete player1;
		delete player2;
	}
};

#endif

