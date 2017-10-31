/*********************************************************************
** Program name: Lab 6
** Author: Mario Franco-Munoz
** Date: 10/30/2017
** Description: int_LinkedList is a class that represents a doubly-linked list data structure.
** int_LinkedList uses the Node class which contains a pointer to next node, pointer to previous node and
** an integer data type. This class provides the user with options for entering new nodes from the head,
** from the tail, deleting nodes (from the head or tail), and traversing nodes.
*********************************************************************/

#include "Int_LinkedList.hpp"

//default constructor
Int_LinkedList::Int_LinkedList() {
	this->head = new Node(0, nullptr, tail);
	this->tail = new Node(0, head, nullptr);
	this->head->setForwardLink(tail);
	this->tail->setBackwardLink(head);
	this->reload = false;
}


/*********************************************************************
** Description: addNode_Head adds a Node to the list one step up from the head.
** Node that previously pointed at head now points at inserted node.
*********************************************************************/
Node* Int_LinkedList::addNode_Head(int valIn) {
	Node *temp = new Node;
	Node *ptr;

	//if the only elements in the linked list are the head and tail
	if (head->getForwardLink() == tail) {
		//update the head node
		head->setForwardLink(temp);

		//update the new node
		temp->setBackwardLink(head);
		temp->setForwardLink(tail);
		temp->setVal(valIn);
		
		//update the tail node
		tail->setBackwardLink(temp);
	}
	else {
		
		//whatever node was present prior to new node being added to the head gets shifted back one node away from the head
		ptr = head->getForwardLink();
		//shift the node that previously pointed at the head
		ptr->setBackwardLink(temp);

		//update the new node
		temp->setForwardLink(ptr);
		temp->setVal(valIn);
		temp->setBackwardLink(head);

		//update the head
		head->setForwardLink(temp);


		
	}
	return temp;
}

/*********************************************************************
** Description: addNode_Tail adds a Node to the list one step below from the tail.
** Node that previously pointed at tail now points at inserted node.
*********************************************************************/
Node* Int_LinkedList::addNode_Tail(int valIn) {
	Node *temp = new Node;
	Node *ptr;   //previous node that is being shifted downwards

	//if the only elements in the linked list are the head and tail
	if (tail->getBackwardLink() == head) {
		//update the tail node
		tail->setBackwardLink(temp);

		//update the new node
		temp->setForwardLink(tail);
		temp->setForwardLink(head);
		temp->setVal(valIn);

		//update the head node
		head->setForwardLink(temp);
	}
	else {
		//update displaced/shifted node
		ptr = tail->getBackwardLink();
		ptr->setForwardLink(temp);

		//update new node
		temp->setForwardLink(tail);
		temp->setBackwardLink(ptr);
		temp->setVal(valIn);

		//update the tail
		tail->setBackwardLink(temp);
		
	}
	return temp;
}


/*********************************************************************
** Description: deletes the first node connected to the head. (This function should not be
** implemented in a way that the only existing nodes are the tail and head, however a
** check does exist within the function.)
*********************************************************************/
void Int_LinkedList::delete_FirstNode() {
	Node *ptr = nullptr;    //ptr is the pointer that is to be deleted
	Node *temp = nullptr;  //temp is the node one up from ptr
	if (head->getForwardLink() == tail) {
		std::cout << "ERROR: ONLY TAIL AND HEAD NODES ARE PRESENT" << std::endl;
	}
	else {
		//find what the pointer that is to be deleted is pointing to up the chain.
		ptr = head->getForwardLink();
		temp = ptr->getForwardLink();
		//make the head point to that node that is being pointed to up the chain
		if (temp == tail) {
			head->setForwardLink(tail);
			tail->setBackwardLink(head);
			delete ptr;
		}
		else {
			head->setForwardLink(temp);
			temp->setBackwardLink(head);
			delete ptr;
		}
	}
}


/*********************************************************************
** Description: deletes the last node connected to the tail. (This function should not be
** implemented in a way that the only existing nodes are the tail and head, however a
** check does exist within the function.)
*********************************************************************/
void Int_LinkedList::delete_LastNode() {
	Node *ptr = nullptr;
	Node *temp = nullptr;
	if (tail->getBackwardLink() == head) {
		std::cout << "ERROR: ONLY TAIL AND HEAD NODES ARE PRESENT" << std::endl;
	}
	else {
		//find what the pointer that is to be deleted is pointing to down the chain.
		ptr = tail->getBackwardLink();
		temp = ptr->getBackwardLink();
		//make the tail point to that node that is being pointed to down the chain
		if (temp == head) {
			tail->setBackwardLink(head);
			head->setForwardLink(tail);
			delete ptr;
		}
		else {
			tail->setBackwardLink(temp);
			temp->setForwardLink(tail);
			delete ptr;
		}
	}
}

/*********************************************************************
** Description: print_reverse prints the values stored in all the nodes in the linked list starting with the tail.
*********************************************************************/
void Int_LinkedList::print_reverse() const {
	Node *ptr = nullptr;
	ptr = tail->getBackwardLink();
	while (ptr->getBackwardLink() != nullptr) {
		std::cout << ptr->getVal() << " ";
		ptr = ptr->getBackwardLink();
	}
	std::cout << "\n";
}

/*********************************************************************
** Description: print_forward prints the values stored in all the nodes in the linked list starting with the head.
*********************************************************************/
void Int_LinkedList::print_forward() const {
	Node *ptr = nullptr;
	//identify the pointer that needs to be printed - start at the head in this case
	ptr = head->getForwardLink();
	while (ptr->getForwardLink() != nullptr) {
		std::cout << ptr->getVal() << " ";
		ptr = ptr->getForwardLink();
  	}
	std::cout << "\n";
}


/*********************************************************************
** Description: menu provides options for user to access, create, delete, and print nodes in linked list.
*********************************************************************/
void Int_LinkedList::menu() {
	float choice;
	int status = 0;
	
	//introduction statement
	std::cout << "Welcome to my linked list! \n" << std::endl;
	
	//overall loop cycle
	do {
		//Main menu
		do {
			std::cout << "\n";
			if (status != 0) {
				std::cout << "Invalid input. Please enter a valid menu option." << std::endl;
			}
			std::cout << "Choose from the following options: \n" << std::endl;
			std::cout << "1. Add a new node to the head." << std::endl;
			std::cout << "2. Add a new node to the tail." << std::endl;
			std::cout << "3. Delete from head." << std::endl;
			std::cout << "4. Delete from tail." << std::endl;
			std::cout << "5. Traverse the list reversely." << std::endl;
			std::cout << "*****EC OPTIONS ********" << std::endl;
			std::cout << "6. Print the value of the Node the head is pointing to." << std::endl;
			std::cout << "7. Print the value of the Node the tail is pointing to." << std::endl;
			std::cout << "8. Create a linked list by reading from a pre-made text file." << std::endl;
			std::cout << "9. Exit." << std::endl;

		} while ((status = getInt(&choice)) != 0 || choice > 9 || choice < 1);


		switch (static_cast<int>(choice)) {
			
		case 1:
			//prompt the user for a positive integer
			std::cout << "Please enter a positive integer: \n" << std::endl;
			status = 0;
			do {
				if (status != 0) {
					std::cout << "Invalid entry. Please enter a positive integer." << std::endl;
				}
			} while ((status = getInt(&choice)) != 0 || choice < 1);
			addNode_Head(static_cast<int>(choice));

			//traverse the list
			std::cout << "Your linked list is: ";
			print_forward();
			std::cout << "\n";
			
			break;
		case 2:
			//prompt the user for a positive integer
			std::cout << "Please enter a positive integer: \n" << std::endl;
			status = 0;
			do {
				if (status != 0) {
					std::cout << "Invalid entry. Please enter a positive integer." << std::endl;
				}
			} while ((status = getInt(&choice)) != 0 || choice < 1);
			addNode_Tail(static_cast<int>(choice));
			
			//traverse the list
			std::cout << "Your linked list is: ";
			print_forward();
			std::cout << "\n";

			break;
		case 3:   //delete first node
			if (head->getForwardLink() == tail) {
				std::cout << "There aren't any nodes to delete! The head is currently pointing at the tail!" << std::endl;
			}
			else {
				std::cout << "First node has been deleted!" << std::endl;
				delete_FirstNode();
				
				//display updated linked list
				std::cout << "Your linked list is: ";
				print_forward();
				std::cout << "\n";
			}

			break;
		case 4:   //delete last node
			if (tail->getBackwardLink() == head) {
				std::cout << "There aren't any nodes to delete! The head is currently pointing at the tail!" << std::endl;
			}
			else {
				std::cout << "Last node has been deleted!" << std::endl;
				delete_LastNode();
				
				//display updated linked list
				std::cout << "Your linked list is: ";
				print_forward();
				std::cout << "\n";
			}

			break;
		case 5:   // Traverse list reversely.
			if (head->getForwardLink() == tail) {
				std::cout << "There aren't any nodes to display! The head is currently pointing at the tail!" << std::endl;
			}
			else {
				std::cout << "Your linked list (in reverse) is: ";
				print_reverse();
			}

			break;
		case 6: //Print the value of the Node the head is pointing to
			if (head->getForwardLink() == tail || head->getForwardLink()  == nullptr) {
				std::cout << "There aren't any nodes to display values for! Only the head and tail exist." << std::endl;
			}
			else {
				std::cout << "The value of the Node the head is pointing to:   ";
				Node *ptr = head->getForwardLink();
				std::cout << ptr->getVal() << std::endl;
			}

			break;

		case 7: //Print the value of the Node the tail is pointing to
			if (tail->getBackwardLink() == head || tail->getBackwardLink() == nullptr) {
				std::cout << "There aren't any nodes to display values for! Only the head and tail exist." << std::endl;
			}
			else {
				std::cout << "The value of the Node the tail is pointing to:   ";
				Node *ptr = tail->getBackwardLink();
				std::cout << ptr->getVal() << std::endl;
			}

			break;
		case 8:
			if (reload == false) {
				listFromFile();
			}
			else {
				std::cout << "Linked list has already been loaded from template text file!" << std::endl;
				std::cout << "Current list is being deleted and linked list will be recreated!" << std::endl;
				//clear the current linked list for reload!
				Node *ptr = head;
				while (ptr != nullptr) {
					Node *temp = ptr;
					ptr = ptr->getForwardLink();
					delete temp;
				}
				
				//re initialize the head and the tail
				this->head = new Node(0, nullptr, tail);
				this->tail = new Node(0, head, nullptr);
				this->head->setForwardLink(tail);
				this->tail->setBackwardLink(head);
				
				//create new linked list
				reload = false;
				listFromFile();
			}
			break;
		case 9:
			break;
		default:
			break;
		}
	} while (choice != 9);

}

/*********************************************************************
** Description: listFromFile generates a linked list from a text file containing integers
*********************************************************************/
void Int_LinkedList::listFromFile() {
	std::string ifname = "integers.txt";
	std::string input; //line of input being read in as a string from text file ('\n' delimited)
	int intInput;     
	std::ifstream ifs;
	std::stringstream ss;   //string stream for converting strings into integers

	ifs.open(ifname.c_str(), std::ios::in);
	if (!ifs) {
		std::cout << "Error opening file!" << std::endl;
	}
	
	else {
		getline(ifs, input);
		while (ifs) {
			ss << input;        //send string to string stream
			if (!(ss >> intInput)) {  //check to make sure stringstream contains an integer
				intInput = 9999999;
			}
			addNode_Head(intInput);  //create node and add it to head using integer read
			getline(ifs, input);
			ss.clear();
		}
		this->reload = true;
	}
	ifs.close();
}


//Destructor for memory dealocation
Int_LinkedList::~Int_LinkedList() {
	Node *ptr = head;
	while (ptr != nullptr) {
		Node *temp = ptr;
		ptr = ptr->getForwardLink();
		delete temp;
	}
}
