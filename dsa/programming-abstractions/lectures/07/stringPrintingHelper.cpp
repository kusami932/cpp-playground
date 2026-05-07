#include <iostream>
#include "console.h"
using namespace std;

void printStringHelper(string& s, int k)
{
    if (k == s.length())
    {
        cout << endl;
        return;
    }

    cout << s[k];
    printStringHelper(s, k + 1);
}

void printString(string& s)
{
    printStringHelper(s, 0);
}

int main()
{
    string s = "hello";
    printString(s);
    printString(s);

    return 0;
}