/*********************************************************************
** Program name: Lab 7
** Author: Mario Franco-Munoz
** Date: 11/07/2017
** Description:(Header file for Queue class) Queue class represents a circular
** linked list that utilizes a structure (QueueNode) as it's node template. Nodes
** contain an integer and a pointer to the next and previous node in the circular linked list.
*********************************************************************/

#include <iostream>
#include <string>

//function headers
#include "Integer_Input_Val.hpp"

#ifndef QUEUE_HPP
#define QUEUE_HPP

class Queue {
	//QueueNode structure
	struct QueueNode {
		QueueNode *next;
		QueueNode *prev;
		int val;
		//default struct constructor
		QueueNode() {
			val = -1;
			next = nullptr;
			prev = nullptr;
		}
		//initialized constructor
		QueueNode(int intIn) {
			val = intIn;
			next = nullptr;
			prev = nullptr;
		}
	};

private:
	QueueNode *head;

public:
	//constructor
	Queue();
	//destructor
	virtual ~Queue();

	bool isEmpty();
	void addBack(int);
	int getFront();
	void removeFront();
	void printQueue();

	void menu();

};
#endif