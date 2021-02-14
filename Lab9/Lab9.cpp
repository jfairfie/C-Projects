// Lab9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "stack_pair.h"

void test1() {
	//Test 1
	stack_pair<int> stack;

	stack.push_a(5);
	stack.push_a(10);
	stack.push_a(15);
	stack.push_b(3);
	stack.push_b(6);
	stack.push_b(9);

	int test_a = 15;
	int test_b = 9;
	int temp;
	//Test 1 
	for (int i = 3; i > 0; i--) {
		temp = stack.pop_a();
		std::cout << temp << " ";
		if (temp == test_a) {
			test_a -= 5;
		}
		else {
			std::cout << "THE PROGRAM FAILED" << std::endl;
			exit(0);
		}

		if (stack.is_empty_a()) {
			std::cout << std::endl;
			for (int i = 3; i > 0; i--) {
				temp = stack.pop_b();
				std::cout << temp << " ";
				if (temp = test_b) {
					test_b -= 3;
				}
				else {
					std::cout << "THE PROGRAM FAILED" << std::endl;
					exit(0); 
				}
			}
		}
	}
	std::cout << "\nThe program printed out the correct items" << std::endl; 
}

void test2() {
	//Test 2
	stack_pair<int> stack; 

	for (int i = 5; i <= 75; i += 5) {
		stack.push_a(i);
	}

	for (int i = 3; i <= 45; i += 3) {
		stack.push_b(i);
	}

	if (stack.is_full_a() && stack.is_full_b()) {
		std::cout << "\nThe program is full" << std::endl;
	}
	else {
		std::cout << "THE TEST FAILED";
		exit(0);
	}

}

void test3() {
	stack_pair<int> stack;

	for (int i = 5; i <= 75; i += 5) {
		stack.push_a(i);
	}

	for (int i = 3; i <= 45; i += 3) {
		stack.push_b(i);
	}

	//Adding another item
	stack.push_a(5); 
}

void test4() {
	//Test 4 
	stack_pair<int> stack;
	stack.pop_a();
	std::cout << "TEST 4 FAILED" << std::endl;
}

int main()
{
	//Test 1 ensures the program adds and pops a few numbers correctly 
	//Test 2 ensures the program gets full properly
	//Test 3 ensures that the program cannot add anything more
		//When the program cannot add anything more, it will not add anything and print out that fact
	//Test 4 ensures the program cannot pop an empty stack


	test1(); 
	test2(); 
	test3();
	test4(); 
}
