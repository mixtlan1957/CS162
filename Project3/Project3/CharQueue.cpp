/*********************************************************************
** Program name: Project3 & 4 (Fantasy Combat Game - Revised)
** Author: Mario Franco-Munoz
** Date: 10/26/2017
** Description: Source file for stack/linked list queue data structure for holding
** characters.
*********************************************************************/

#include "CharQueue.hpp"

//default constructor
CharQueue::CharQueue() {
	head = new Node;
	head->next = nullptr;
	head->prev = nullptr;
}


//destructor
CharQueue::~CharQueue() {
	clearQueue();
	delete head;
}

/*********************************************************************
** Description: clearQueue deletes all nodes except for head.
*********************************************************************/
void CharQueue::clearQueue() {
	Node *temp = nullptr;
	temp = head->next;
	while (temp != nullptr) {
		//delete temp->c_ptr;
		removeFront();
		temp = head->next;
	}
}

/*********************************************************************
** Description: isEmpty checks if there are any nodes in the Queue other than the head.
** Returns true if Queue is empty, returns false if not empty.
*********************************************************************/
bool CharQueue::isEmpty() {
	if (head->next == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

/*********************************************************************
** Description: addBack adds a node containing a character pointer to the 
** CharQueue ADT. Queue is created with a pointer to a character.
*********************************************************************/
void CharQueue::addBack(Character *ptrIn) {
	Node *ptr = new Node(ptrIn);
	Node *temp = nullptr;
	
	//check for case in which the head and newly added node are the only nodes
	if (head->prev == nullptr) {
		//update head
		head->prev = ptr;
		head->next = ptr;

		//update newly added pointer
		ptr->prev = head;
		ptr->next = head;
	}
	else {
		//get the node at the end of the back of the circular list
		temp = head->prev;

		//reassignment of node that was previously at end of queue.
		temp->next = ptr;

		//update of newly added node
		ptr->next = head;
		ptr->prev = temp;

		//update of head
		head->prev = ptr;
	}
}

/*********************************************************************
** Description: getFront returns a character pointer stored in the first node of the queue.
*********************************************************************/
Character* CharQueue::getFront() {
	Node *temp = nullptr;
	if (head->next == nullptr) {
		return nullptr;
	}
	else {
		temp = head->next;
		return temp->c_ptr;
	}
}

/*********************************************************************
** Description: removeFront deletes the node next to the head (and deletes the
** stored character pointer in the process). Remove node however DOES NOT
** delete character pointer stored in the node, thus this function should be used
** with an additional memory dealocation statement if node contents (Character pointer)
** are to be destroyed as well.
*********************************************************************/
void CharQueue::removeFront() {
	Node *temp = nullptr;
	Node *ptr = nullptr;
	
	ptr = head->next;
	//make sure there is a node to delete
	if (ptr != nullptr) {
		temp = ptr->next;
		//check to see if node that is being deleted is the only node
		if (temp != head) {
			temp->prev = head;
			head->next = temp;
			//delete ptr->c_ptr;
			delete ptr;			//delete node
		}
		//case for which there is only one node
		else {
			head->next = nullptr;
			head->prev = nullptr;
			//delete ptr->c_ptr;
			delete ptr;
		}
	}
}

/*********************************************************************
** Description: sendFrontToBack adjusts the orders of the nodes in the queue.
** Sending the node that was previously at the front to the end. 
*********************************************************************/
void CharQueue::sendFrontToBack() {
	Node *temp;
	
	//check for case in which no nodes are present
	if (head->next == nullptr) {
		std::cout << "An error has occured." << std::endl;
		exit(1);
	}
	else {
		temp = head->next;
		addBack(temp->c_ptr);
		removeFront();
	}
}

/*********************************************************************
** Description: printQueue displays the names of the different characters stored in the
** different notes of the CharQueue circular linked list.
*********************************************************************/
void CharQueue::printQueue() {
	Node *temp = nullptr;
	int rowCount = 0;
	if (head->next != nullptr) {
		temp = head->next;
		while (temp->next != head) {
			rowCount++;
			
			//display the character name of the character stored in the node.
			std::cout << temp->c_ptr->getName() << "  ";
			if (rowCount >= 10) {
				rowCount = 0;
				std::cout << "\n";
			}

			temp = temp->next;
		}
		//print last node
		std::cout << temp->c_ptr->getName();
		std::cout << "\n" << std::endl;
	}
	else {
		std::cout << "An error has occured." << std::endl;
		exit(1);
	}
}



