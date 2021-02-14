// Sorter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void print_arr(int data[], size_t n) {
	for (size_t i = 0; i < n; i++) {
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}

void space_printer(size_t n) {
	for (size_t i = 0; i < n; i++) {
		std::cout << " "; 
	}
}

void make_heap(int data[], size_t n) {
	if (n == 0) {
		return; 
	}

	if (data[n] > data[(n - 1) / 2]) {
		int temp = data[n]; 
		data[n] = data[(n - 1) / 2]; 
		data[(n - 1) / 2] = temp; 
		make_heap(data, n - 1); 
	}

	make_heap(data, n - 1); 
}

int exponent(size_t n) {
	if (n == 0) {
		return 0; 
	}

	int result = 2; 
	for (int i = n - 1; i > 0; i--) {
		result *= result; 
	}
	return result + exponent(n-1); 
}

void print_heap(int data[], int n) {
	int index = 0; 

	for (int i = 0; i < n; i++) {
		if (i > exponent(index)) {			
			index += 1; 
			std::cout << std::endl;
		}
		std::cout << data[i] << " "; 
	}
	std::cout << std::endl; 
}



int main()
{
	int data[] = {21, 35, 22, 27, 23, 45, 42, 19, 4, 5}; 
	
 	make_heap(data, 10);  
	print_heap(data, 10); 

}