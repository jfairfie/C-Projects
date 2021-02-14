#include <iostream>
#include "bag5.h"
#include "node2.h"
using namespace std;

int main()
{
    bag<int> bag1;
    for (int i = 7; i >= 1; i--) {
        bag1.insert(i);
    }

    bag1.print_value_range(1, 7); //Prints 1 2 3 4 5 6 7
    bag1.print_value_range(2, 5); //Prints 2 3 4
    bag1.print_value_range(2, 78); //Prints 2 3 4 5 6 7
    bag1.print_value_range(2,1); //Prints 2 3 4 5 6 7
    bag1.print_value_range(8,4); //Prints nothing

    cout << endl;

    bag<int> bag2;
    for (int i = 7; i >= 1; i--) {
        bag2.insert(i);
        if (i == 4) {
            bag2.insert(7);
        }
        if (i == 2) {
            bag2.insert(5);
        }
    }
    bag2.print_value_range(1,8);
    bag2.remove_repetitions();
    bag2.print_value_range(1,8);

    return 0;
}
