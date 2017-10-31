/*********************************************************************
** Program name: Lab 6
** Author: Mario Franco-Munoz
** Date: 10/30/2017
** Description: Node class for the construction of a doubly-linked data structure.
** Node consists of a pointer to the next node, pointer to the previous node, and an
** integer data member.
*********************************************************************/

#include "Node.hpp"
Node::Node() {
	this->val = 0;
	this->prev = nullptr;
	this->next = nullptr;
}


//initialized constructor
Node::Node(int valIn, Node *previous, Node *nextNode) {
	this->val = valIn;
	this->prev = previous;
	this->next = nextNode;
}

/*********************************************************************
** Description: accessor function to return the next linked node 
*********************************************************************/
Node* Node::getForwardLink() const {
	return this->next;
}

/*********************************************************************
** Description: accessor function to return the previous linked node
*********************************************************************/
Node* Node::getBackwardLink() const {
	return this->prev;
}

/*********************************************************************
** Description: accessor function to return the integer value stored in the node
*********************************************************************/
int Node::getVal() const {
	return this->val;
}

/*********************************************************************
** Description: mutator function to set the next linked node
*********************************************************************/
void Node::setForwardLink(Node *nextNode) {
	this->next = nextNode;
}

/*********************************************************************
** Description: mutator function to set the previous linked node
*********************************************************************/
void Node::setBackwardLink(Node *previousNode) {
	this->prev = previousNode;
}

/*********************************************************************
** Description: mutator function to set the value of integer data member val
*********************************************************************/
void Node::setVal(int valIn) {
	this->val = valIn;
}




