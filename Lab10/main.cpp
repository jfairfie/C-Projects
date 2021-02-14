// Lab10
//Created by Joshua Fairfield 

#include <iostream>
void recursion1(int levels, int cursor) {
	if (cursor == (levels * 2) - 1) {
		std::cout << "This ALSO written by number " << cursor - cursor + 1 << std::endl; 
	}
	else {
		if (cursor == levels) {
			std::cout << "This was written by number " << levels << std::endl;
			std::cout << "This ALSO written by number " << levels << std::endl; 
			recursion1(levels, cursor + 1);
		} else if (cursor > levels) {
			std::cout << "This ALSO written by number " << levels - (cursor - levels) << std::endl; 
			recursion1(levels, cursor + 1); 
		} else {
			std::cout << "This was written by number " << cursor << std::endl; 
			recursion1(levels, cursor + 1); 
		}
	}

}

//Part 2 of Lab 10
double sumover(int n) {
	if (n == 0) {
		return 0; 
	}
	
	return 1 / (double)n + sumover(n - 1); 
}

//Main Function 
int main()
{
	//First Part of Assignment
	recursion1(4, 1); 
	std::cout << std::endl;
	recursion1(2, 1); 
	std::cout << std::endl; 
	
	//Second Part of Assignment 
	std::cout << sumover(0) << std::endl; 
	std::cout << sumover(1) << std::endl; 
	std::cout << sumover(2) << std::endl;
	std::cout << sumover(3) << std::endl;
}
