#include <iostream>
#include "console.h"
#include "random.h"  // for randomInteger()
#include "simpio.h"  // for getInteger()
#include "vector.h"
using namespace std;

// Creates and returns a vector of n random integers on the range 0 through
// 100 (inclusive). Assumes n is non-negative.
Vector<int> createRandomVector(int n)
{
    Vector<int> v;
    
    for (int i = 0; i < n; i++)
    {
        // Generate random integer on the range 0 through 100 (inclusive) and add
        // to vector.
        v.add(randomInteger(0, 100));
    }

    return v;
}

// Takes a vector of integers and some key to search for. Returns the first index
// where key occurs, or -1 if key is not present. Passing vector by reference for
// efficiency.
int search(Vector<int>& v, int key)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == key)
        {
            return i;
        }
    }

    // If we make it through the loop without finding our key, it must not be in
    // our vector.
    return -1;
}

int main()
{
    // Create vector with 10 random integers and print to screen.
    Vector<int> v = createRandomVector(10);
    cout << v << endl;

    while(true)
    {
        cout << endl << "What integer shall we search for? (-1 to quit) ";
        int key = getInteger();

        if (key == -1)
        {
            break; // Jump to end of loop and continues executing main().
        }

        cout << "result: " << search(v, key) << endl;
    }
    cout << "Bye!" << endl;
    return 0;
}