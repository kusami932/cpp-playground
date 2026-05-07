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

// simply swap the order of our cout and printStringReverse() lines in the original 
// recursive function, and let the program stack take care of reversing the string for us:
void printStringReverse(string s)
{
    if (s.length() == 0)
    {
        cout << endl;  // This is problematic.
        return;
    }

    printStringReverse(s.substr(1));
    cout << s[0];

}

// An alternative approach to this problem would be to print the last character of the string in each recursive call
void printStringReverse2(string s)
{
    if (s.length() == 0)
    {
        cout << endl;
        return;
    }

    cout << s[s.length() - 1];
    printStringReverse2(s.substr(0, s.length() - 1));
}

int main()
{
    // Calling twice to ensure proper placement of line break in output.
    printString("hello");
    printString("hello");

    // the output actually places the newline character before each reversed string, not after. 
    printStringReverse("hello");
    printStringReverse("hello");

    return 0;
}