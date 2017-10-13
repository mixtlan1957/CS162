/*********************************************************************
** Program name: Lab3
** Author: Mario Franco-Munoz
** Date: 10/12/2017
** Description: Main file for implementation of the Game class which represents a game of war.
** From the Game class description:
** "Game class represents a game of "war". This game consists of two players that each have a die with
** N-faces of their chosing. Players roll the die x ammount of times (limit of 50 rounds) and face off to see who gets the
** highest number of wins. Players can chose between a normal die and a weighted die which has a considerable higher chance of
** yielding higher results."
*********************************************************************/

#include <iostream>

#include "LoadedDie.hpp"
#include "Die.hpp"
#include "Game.hpp"

int main() {
	Game instance;

	//introduction
	std::cout << "Welcome to WAR with dice!\n" << std::endl;

	instance.startMenu();
	instance.runGame();

	return 0;
}