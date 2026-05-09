#include <iostream>
#include "console.h"
using namespace std;

// Prints all possible coin flip sequences (consisting of characters 'H' and/or 'T')
// starting with the sequence we have generated so far (soFar) and ending with n
// additional coin flips.

void coinFlip(string soFar, int n)
{
    // If there are no more coins to flip, we have generated a sequence of the
    // desired length. Print it.
    if (n == 0)
    {
        cout << soFar << endl;
        return;
    }

    // If there are coins remaining to be flipped, generate both possibilities:
    // one where we flip a head (adding 'H' to the sequence we've generated so far)
    // and one where we flip a tail (adding 'T' to soFar). In both cases, we have
    // one less coin to flip. We make both recursive calls because we want to
    // generate all possible sequences, which necessarily means exploring both
    // possible outcomes for this particular coin flip.
    coinFlip(soFar + 'H', n - 1);
    coinFlip(soFar + 'T', n - 1);
}

// Our wrapper function, which serves as a gateway to the recursive coinFlip()
// function above. Generates all possible coin flip sequences (made up of the
// characters 'H' and 'T') of length n.
void coinFlip(int n)
{
    // The empty string we're passing as our first parameter below indicates that
    // we are starting with an empty sequence. We have not yet flipped any coins,
    // and so the sequence does not yet contain any 'H' or 'T' characters.
    coinFlip("", n);
}

int main()
{
    coinFlip(3);
    return 0;
}