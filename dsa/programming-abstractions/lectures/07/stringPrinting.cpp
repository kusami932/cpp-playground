#include <iostream>
#include "console.h"
using namespace std;

// a recursive function that prints a string, with the restriction that 
// any given call can only print a single character.

void printString(string s)
{
    if(s.length() == 0)
    {
        cout << endl;
        return;
    }

    cout << s[0];

    // The string passed recursively has s[0] shaved off.
    printString(s.substr(1, s.length() - 1))
}

int main()
{
    // Calling twice to ensure proper placement of line break in output.
    printString("hello");
    printString("hello");

    return 0;
}