#include <iostream>
#include "console.h"
using namespace std;

// Swap the characters at indices i and j in our string. We use this helper function
// to keep our permute() function as clutter-free and readable as possible.
void swap(string& s, int i, int j)
{
    int temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

// Permute all characters in our string starting at index k. Print all resulting
// permutations.
void permute(string& s, int k)
{
    // k is the first of all indices in our string that remain to be permuted. If
    // k == s.length() (which is not a valid index in our string), that means we
    // must have permuted all the characters already, and were are therefore ready
    // to print a permutation and return to previous recursive calls.
    if (k == s.length())
    {
        cout << s << endl;
        return;
    }

    // Of the remaining characters (from index k onward), let's select each of them
    // to be swapped down into index k and make a recursive call for each of those
    // options.
    for (int i = k; i < s.length(); i++)
    {
        swap(s, k, i);
        perumte(s, k + 1);
        swap(s, k, i);
    }
}

// Our wrapper function, which serves as a gateway to the recursive permute()
// function above.
 void permute(string& s)
{
    // The 0 (zero) in the function call below indicates that we start our
    // permutation process by choosing a character to freeze into place
    // at index 0. Our recursive calls will move forward to choose other
    // characters to freeze into place at the remaining indices.
    permute(s, 0);
}

int main()
{
    string s = "cat";
    permute(s);

    return 0;
}

