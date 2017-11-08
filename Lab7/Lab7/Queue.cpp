/*********************************************************************
** Program name: Lab 7
** Author: Mario Franco-Munoz
** Date: 11/07/2017
** Description: (Source file for Queue class) Queue class represents a circular
** linked list that utilizes a structure (QueueNode) as it's node template. Nodes
** contain an integer and a pointer to the next and previous node in the circular linked list.
** New nodes can be added to the front and back of the linked list, and nodes can be removed from
** from the front of the Queue circular linked list by calling removeFront(). 
*********************************************************************/

#include "Queue.hpp"

//Default Constructor
Queue::Queue() {
	head = new QueueNode;
	head->next = nullptr;
	head->prev = nullptr;
}

//Destructor
Queue::~Queue() {
	QueueNode *temp = head;
	while (temp != head) {
		head = head->next;
		temp->next = nullptr;
		delete temp;
		temp = head;
	}
}

/*********************************************************************
** Description: isEmpty checks if the equeue is empty. Returns true if true.
*********************************************************************/
bool Queue::isEmpty() {
	if (head->next == nullptr) {
		return true;
	}
	else {
		return false;
	}
}


/*********************************************************************
** Description: addBack takes a user-inputted integer and creates a QueueNode
** with that integer and appends it to the back of the list.
*********************************************************************/
void Queue::addBack(int valIn) {
	QueueNode *temp = new QueueNode(valIn);
	QueueNode *ptr = nullptr;

	//check for case in which head and newly added node are the only nodes
	if (head->prev == nullptr) {
		head->prev = temp;
		head->next = temp;
		
		//finish initializing new node
		temp->next = head;
		temp->prev = head;
	}

	else {
		//get the node at the end of the back of the circular list
		ptr = head->prev;
		
		//update new node
		temp->next = head;
		temp->prev = ptr;

		//update node that was previously last node
		ptr->next = temp;

		//update head
		head->prev = temp;
	}
}

/*********************************************************************
** Description: getFront returns the value of the node at the front of the queue.
*********************************************************************/
int Queue::getFront() {
	QueueNode *ptr = nullptr;
	//find the value next to the head
	ptr = head->next;

	if (ptr != nullptr) {
		return ptr->val;
	}
	else {
		std::cout << "Error has occured: There are no nodes at the front of the queue!" << std::endl;
		exit(1);
	}
}

/*********************************************************************
** Description: removeFront removes the front QueueNode of the queue and frees
** the memory.
*********************************************************************/
void Queue::removeFront() {
	QueueNode *ptr = nullptr;
	QueueNode *temp = nullptr;

	ptr = head->next;
	//make sure that there is a node to delete
	if (ptr != nullptr) {
		temp = ptr->next;
		//check to see if node that is being deleted is the only node other than the head
		if (temp != head) {
			temp->prev = head;
			head->next = temp;
			delete ptr;
		}
		//case for which there is only one active node (one node other than the head)
		else {
			head->next = nullptr;
			head->prev = nullptr;
			delete ptr;
		}
	}
}


/*********************************************************************
** Description: printQueue traverses through the queue from head using next pointers
** and prints the values of each QueueNode in the queue.
*********************************************************************/
void Queue::printQueue() {
	QueueNode *temp = nullptr;
	int rowCount;
	//QueueNode *ptr = nullptr;
	//print only if there are actually nodes to print
	if (head->next != nullptr) {
		temp = head->next;
		rowCount = 0;
		while (temp->next != head) {
			rowCount++;
			std::cout << temp->val << " ";
			temp = temp->next;
			//conditional return statement
			if (rowCount >= 15) {
				std::cout << "\n";
				rowCount = 0;
			}
		}
		//print last node
		std::cout << temp->val;
		std::cout << "\n" << std::endl;
	}
}

/*********************************************************************
** Description: menu provides the user an interface for which they can interact with the
** linked list that resides within the Queue instanced class.
*********************************************************************/
void Queue::menu() {
	float choice;
	int status = 0;
	int errorCount = 0;

	//introduction statement
	std::cout << "Welcome to my queue! \n" << std::endl;

	//overall loop cycle
	do {
		//Main menu
		errorCount = 0;
		do {
			std::cout << "\n";
			if (status != 0 || errorCount > 0) {
				std::cout << "Invalid input. Please enter a valid menu option." << std::endl;
			}
			std::cout << "Choose from the following options: \n" << std::endl;
			std::cout << "1. Enter a value to be added to the back of queue" << std::endl;
			std::cout << "2. Display first node (front) value" << std::endl;
			std::cout << "3. Remove first node (front) value" << std::endl;
			std::cout << "4. Display the queue contents" << std::endl;
			std::cout << "5. Exit" << std::endl;
			errorCount++;
		} while ((status = getInt(&choice)) != 0 || choice > 5 || choice < 1);

		switch (static_cast<int>(choice)) {
			case 1:
				//validate user input
				status = 0;
				do {
					std::cout << "Enter an integer for new node that will be added to back of queue: ";
					if (status != 0) {
						std::cout << "Invalid input. Please enter an integer." << std::endl;
					}
				} while ((status = getInt(&choice)) != 0);

				//call addBack to create node at end of queue
				addBack(static_cast<int>(choice));
				choice = 0;  //reset choice
				break;
			case 2:
				//validate user input
				if (isEmpty() == true) {
					std::cout << "Queue list is empty! There are no nodes to display!" << std::endl;
				}
				else {
					std::cout << "First node contains the value: ";
					std::cout << getFront();
					std::cout << "\n";
				}
				break;
			case 3:
				if (isEmpty() == true) {
					std::cout << "Queue list is empty! There are no nodes to delete!" << std::endl;
				}
				else {
					removeFront();
					std::cout << "First node next to head has been deleted!" << std::endl;
				}
				break;
			case 4:
				if (isEmpty() == true) {
					std::cout << "Queue list is empty! There are not any nodes to display!" << std::endl;
				}
				else {
					std::cout << "Contents of queue: " << std::endl;
					printQueue();
					std::cout << "\n";
				}
				break;
			case 5:
				break;
		}
	} while (choice != 5);
	std::cout << "Goodbye!" << std::endl;
}

