#include "SpaceShip.h"
#include <cstddef>
#include <iostream>
node* head, *tail; 

SpaceShip::SpaceShip() {
	node* space = new node; 
	space->xCoordinate = 0; 
	space->yCoordinate = 0; 
	space->power = 0;
	tail = space; 
	head = space; 
}

void SpaceShip::getNewEnemy(int newPower) {
	if (head == NULL) {
		node* newNode = new node;
		head = newNode;
		return; 
	}

	node* newNode = new node; 
	newNode->xCoordinate = 0; 
	newNode->yCoordinate = 0; 
	newNode->power = newPower; 
	newNode->next = head; 
	head = newNode; 
}

void SpaceShip::displayAll() {
	node* temp = head;
	while (temp != NULL) {
		std::cout << temp->power << " "; 
		temp = temp->next; 
	}
}

void SpaceShip::removeTail() {
	if (tail != NULL) {
		tail = NULL; 
		tail = head; 
		while (tail->next != NULL) {
			tail = tail->next; 
		}
	}
}