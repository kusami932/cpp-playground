#include <iostream>
#include "console.h"
#include "strlib.h"
#include "vector.h"
using namespace std;

// Be careful to pass the vector by reference!
void rollDice(string soFar, int n, Vector<string>& results)
{
    if (n == 0)
    {
        results.add(soFar);
        return;
    }

    for (int i = 1; i <= 6; i++)
   {
      rollDice(soFar + integerToString(i) + " ", n - 1, results);
   }
}

void rollDice(int n)
{
    Vector<string> results;
    rollDice("", n, results);
    cout << results << endl;

    // Expected output if n == 4: 1296.
    cout << results.size() << endl;
}

int main()
{
    rollDice(4);
    return 0;
}