#include <iostream>
#include "priority_queue.h"
int main()
{
	priority_queue<int> vTree;
	vTree.push(42);
	vTree.push(37); 
	vTree.push(23);
	vTree.push(38);
	vTree.push(21);
	vTree.push(22); 
	vTree.push(4); 

	for (int i = 0; i < 7; i++) {
		std::cout << vTree.top() << " "; 
		vTree.pop(); 
	}
	return 0; 
}