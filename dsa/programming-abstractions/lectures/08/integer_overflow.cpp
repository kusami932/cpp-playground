#include <iostream>
#include "console.h"
using namespace std;

/*
On most systems, an int variable in C++ can hold values -2,147,483,648 through 2,147,483,647. 
If we add 1 to the maximum possible integer value, it actually wraps back around to the opposite 
end of the range and gives us -2,147,483,648. This is called integer overflow:
*/
int main()
{
    int biggest = 2147483647;
    biggest++;

    cout << biggest << endl;  // prints -2147483648

    return 0;
}


