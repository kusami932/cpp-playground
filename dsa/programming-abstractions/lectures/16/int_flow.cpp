#include <iostream>
#include "console.h"
using namespace std;

int main()
{
    int i = 20000000;

    while (i > 0)
    {
        i++;
    }

    // When we get here, we will have just overflowed. That means we expect i to be
    // the smallest integer C++ can store in an int type.
    cout << i << endl; // -2147483648

    // If we subtract 1 from i, we encounter integer underflow and expect to get the
    // largest integer C++ can store in an int type.
    cout << (i - 1) << endl; // 2147483647

    return 0;


}