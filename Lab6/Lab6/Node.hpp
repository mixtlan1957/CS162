/*********************************************************************
** Program name: Lab 6
** Author: Mario Franco-Munoz
** Date: 10/30/2017
** Description: Header file for Node class for the construction of a doubly-linked data structure.
** Node consists of a pointer to the next node, pointer to the previous node, and an
** integer data member.
*********************************************************************/


#ifndef NODE_HPP
#define NODE_HPP

class Node {
private:
	Node *prev;
	Node *next;
	int val;
public:
	//constructors
	Node();
	Node(int, Node *, Node *);

	//accessors
	Node *getForwardLink() const;
	Node *getBackwardLink() const;
	int getVal() const;

	//mutators
	void setForwardLink(Node *);
	void setBackwardLink(Node *);
	void setVal(int);

};

#endif


