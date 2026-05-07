#include <iostream>
#include "console.h"
using namespace std;

// for n > 0, n! has at least one other factorial embedded in it: (n - 1)!.
int factorial(unsigned int n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

int main()
{
    cout << factorial(5) << endl;
    return 0;
}