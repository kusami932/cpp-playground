#include <iostream>
#include "console.h"
using namespace std;
/*

The base case of our recursive printStringReverse() function is not the right place to print endl. 
We hit the base case before any other characters have printed to the screen, so if we place the endl 
there, we print our newline character before we print out the string in reverse.

We also don't want to tell someone who calls our function that they have to print a newline character 
themselves. It's a natural part of the desired behavior of a string printing function like this one, 
and so we should handle that ourselves.

*/
void printStringReverseHelper(string s)
{
    if (s.length() == 0)
    {
        return;
    }

    printStringReverseForRealsies(s.substr(1));
    cout << s[0];
}

void printStringReverse(string s)
{
    printStringReverseHelper(s);
    cout << endl;
}

int main()
{
    // Calling twice to ensure proper placement of line break in output.
    printStringReverse("hello");
    printStringReverse("hello");

    return 0;
}