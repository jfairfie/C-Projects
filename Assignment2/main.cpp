#include <iostream>
#include "Sequence.h"
using namespace std;
    int main()
    {
        Sequence c;

        c.advance();
        cout << c.current();
        return 0;
    }
