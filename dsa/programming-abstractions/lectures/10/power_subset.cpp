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

/*
Efficiency of printSubsets()

Because we are creating new strings to pass by value to each of our recursive function calls, there is some unnecessary slowness 
inherent to our printSubsets() function. One might be inclined to ignore those operations as trivial in a less explosive function, 
but here those slow concatenation and string copying operations are happening within the context of an exponential algorithm! 
When dealing with a function that makes O(2n) recursive calls, the runtime impact from each of those calls being O(n) instead of 
O(1) can become non-trivial very quickly as n increases.

=> Pass-by-value leads to slower runtime 

There is, however, an important trade-off at play here. The code above is perhaps more straightforward and followable than an 
approach that operates on a pass-by-reference vector. The pass-by-reference approach would require some extra bookkeeping: 
after returning from the recursive call where thisOne was added to soFar, we would have to remove that element from the vector. 
There would also likely be a third function parameter to keep track of: an integer that tells us how far along we are in the 
original set passed to the function (since we likely would not modify that one within our recursive calls and would instead 
focus only on modifying soFar).

=> Pass-by-reference leads to unnecessary complications

Those added layers of complexity might complicate the example unnecessarily and make it less followable in class, and so we 
have avoided them to make the code more approachable. However, it's good to be aware of these trade-offs -- especially before 
heading into a technical interview, where the efficiency hits from the pass-by-value parameters and string creation operations 
could become a topic of discussion.
*/