/*********************************************************************
** Program name: Lab 6
** Author: Mario Franco-Munoz
** Date: 10/30/2017
** Description: header file for int_LinkedList. int_LinkedList is a class that represents 
** a doubly-linked list data structure.
** int_LinkedList uses the Node class which contains a pointer to next node, pointer to previous node and
** an integer data type. This class provides the user with options for entering new nodes from the head,
** from the tail, deleting nodes (from the head or tail), and traversing nodes.
*********************************************************************/

//class headers
#include "Node.hpp"

//function headers
#include "Integer_Input_Val.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#ifndef INT_LINKEDLIST_HPP
#define INT_LINKEDLIST_HPP

class Int_LinkedList {
private:
	Node *head;
	Node *tail;

	bool reload;

public:
	Int_LinkedList();

	Node* addNode_Head(int);
	Node* addNode_Tail(int);
	void delete_FirstNode();
	void delete_LastNode();
	void print_reverse() const;
	void print_forward() const;

	void menu();

	void listFromFile();


	//destructor
	virtual ~Int_LinkedList();


};

#endif
