#include <string>
#include "bst.h"
using namespace std;

int rnd() {
	return rand() % 10000;
}

int main() {
	binary_search_tree<string> bst;
	cout << bst << endl;
	bst.insert("baker");
	cout << bst << endl;

	// making sure the output operator was working properly.
	bst.get_root()->set_left(new binary_tree_node<string>("able"));
	cout << bst << endl;
	bst.get_root()->set_right(new binary_tree_node<string>("charlie"));
	cout << bst << endl;

	bst.insert("arthur");
	print(bst.get_root(), 0);
	cout << endl;

	string data[] = { "able", "baker", "charlie", "dog", "easy", "fox", "george" };
	int size = 7;
	binary_search_tree<string> bst1;
	for (int i = 0; i < size; ++i) {
		bst1.insert(data[i]);
		cout << bst1 << endl;
	}
	cout << "balanced? " << bst1.is_balanced() << endl << endl;;

	string data2[] = { "dog", "baker", "able", "fox", "charlie",  "george", "easy" };
	binary_search_tree<string> bst2;
	for (int i = 0; i < size; ++i) {
		bst2.insert(data2[i]);
		cout << bst2 << endl;
	}
	print(bst2.get_root(), 0);
	cout << "balanced? " << bst2.is_balanced() << endl << endl;

	binary_search_tree<int> bst3;
	for (int i = 0; i < 50; i++) {
		bst3.insert(rnd());
	}
	cout << bst3 << endl;
	cout << "balanced? " << bst3.is_balanced() << endl << endl;
	
	cout << "remove " << bst2.remove("able") << endl;
	cout << bst2 << endl;
	cout << "remove " << bst2.remove("baker") << endl;
	cout << bst2 << endl;
	cout << "remove " << bst2.remove("fox") << endl;
	cout << bst2 << endl;

	print(bst2.get_root(), 0);

	int data4[] = { 6, 4, 3, 5, 8, 7, 9 };
	binary_search_tree<int> bst4; 
	for (int i = 0; i < 7; ++i) {
		bst4.insert(data4[i]); 
	}
	cout << endl; 
	cout << bst4 << endl; 
	print(bst4.get_root(), 0); 
	cout << endl; 
	cout << "Ordered List:: "; 
	bst4.print_ordered_list(); 
}