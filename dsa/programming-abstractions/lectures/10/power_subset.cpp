#include <iostream>
#include "console.h"
using namespace std;

// Takes a string and prints it using set notation, where each character is treated
// as an element in the set. For example, "abc" is printed as: {a, b, c}
void fancyPrint(string s)
{
    cout << "{";

    for (int i = 0; i < s.length(); i++)
    {
        cout << s[i];

        // We don't need a comma after our last element in the set, but we do want a
        // comma after all the others.
        if (i != s.length - 1)
        {
            cout << ", ";
        }
    }

    cout << "}" << endl;
}

// 'soFar' is the (sub)set we have built so far. 'rest' contains the elements about
// which we have yet to make our binary choice (either include or throw away as we
// generate all possible subsets).
void printSubsets(string soFar, string rest)
{
    if(rest.isEmpty())
    {
        fancyPrint(soFar);
        return;
    }

    // Pluck an element from our set of remaining elements ('rest'). Below, we will
    // make a binary choice about whether to include thisOne in the subsets we
    // generate.
    char thisOne = rest[0];
    string newRest = rest.substr(1);

    // This is the recursive call where we simply discard thisOne.
    printSubsets(soFar, newRest);

    // This is the recursive call where we include thisOne in our new subset.
    printSubsets(soFar + thisOne, newRest);
}

// For simplicity, we represent our sets as strings. Each character is considered
// an element. For example, the set {a, b, c} is represented as the string "abc".
void printSubsets(string s)
{
    printSubsets("", s);
}

int main()
{
    printSubsets("abc");
    return 0;
}