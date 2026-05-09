#include <iostream>
#include "console.h"
#include "strlib.h"
using namespace std;

// Transform the two recursive calls from the coinFlip() function 
// into a series of six recursive calls for our dice.
void rollDice(string soFar, int n)
    {
    if (n == 0)
    {
        cout << soFar << endl;
        return;
    }

   for (int i = 1; i <= 6; i++)
   {
        // cleaned up by rolling the recursive calls into a for-loop, 
        // which requires us to convert the looping integer to a string
        rollDice(soFar + integerToString(i) + " ", n - 1);
   }
}

void rollDice(int n)
{
    rollDice("", n);
}

int main()
{

}