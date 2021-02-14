#pragma once
struct node {
	int xCoordinate;
	int yCoordinate; 
	int power; 
	node* next;
};

class SpaceShip
{
	public: 
		SpaceShip();
		void getNewEnemy(int newPower);
		void displayAll();
		void removeTail(); 
	private: 
		node* head, *tail; 
};

