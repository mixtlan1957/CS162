/*********************************************************************
** Program name: Project3 & 4 (Fantasy Combat Game - Revised)
** Author: Mario Franco-Munoz
** Date: 10/26/2017
** Description: Source file for stack/linked list queue data structure for holding
** characters.
*********************************************************************/

#include "Character.hpp"

#include <iostream>


#ifndef CHARQUEUE_HPP
#define CHARQUEUE_HPP

class CharQueue {
	struct Node {
		Node *next;
		Node *prev;
		Character *c_ptr;

		Node() {
			next = nullptr;
			prev = nullptr;
			c_ptr = nullptr;
		}
		Node(Character *ptrIn) {
			next = nullptr;
			prev = nullptr;
			c_ptr = ptrIn;
		}

	};

private:
	Node *head;

public:
	CharQueue();
	
	virtual ~CharQueue();

	bool isEmpty();
	void addBack(Character *);
	Character* getFront();
	void removeFront();
	void sendFrontToBack();
	void printQueue();
	void clearQueue();
};

#endif 

