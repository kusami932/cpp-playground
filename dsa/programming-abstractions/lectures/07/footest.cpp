#include <iostream>
#include "console.h"
using namespace std;

/*
    First Recursive Function

    1. Base Case. Include some sort of terminating condition that returns the result for 
       some canonical case where we know the answer immediately.

    2. Recursive Call. Decompose the current input into subproblems, one of which involves 
       making a recursive call to the function you're writing. Make sure your input is 
       approaching the base case (not growing infinitely in the opposite direction)!
*/

void foo(int n)
{
    if(n == 0)
    {
        cout << "Blastoff!" << endl;
        return;
    }
    cout << n << "..." << endl;
    foo(n - 1);
}

int main()
{
    foo(5);
    return 0;
}

