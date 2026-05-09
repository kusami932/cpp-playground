#include <iostream>
#include "console.h"
#include "random.h"
#include "simpio.h"
#include "vector.h"
using namespace std;

// Binary search from positions lo through hi (inclusive) for our key. Return first
// index where found, or -1 if not found. Passing vector by reference for efficiency.
int binarySearch(Vector<int>& v, int key, int lo, int hi)
{
    // Base case: If our indices have crossed over, the key must not be present.
    if (lo > hi)
    {
        return -1;
    }

    int mid = lo + (hi - lo) / 2;

    if (key < v[mid])
    {
        return binarySearch(v, key, lo, mid - 1);
    }
    else if (key > v[mid])
    {
        return binarySearch(v, key, mid + 1, hi);
    }
    else
    {
        return mid;
    }
}

// Wrapper function for binary search. This is the one our client would call.

/* Function overloading is where we give multiple functions the same name and allow C++ 
to determine which one to call based on the number and types of parameters we're passing 
to the function. This streamlines our code somewhat by freeing us from the need to clutter 
and elongate the names of our helper functions.
*/
int binarySearch(Vector<int>& v, int key)
{
    return binarySearch(v, key, 0, v.size() - 1);
}

Vector<int> createSortedRandoVector(int n)
{
    Vector<int> v;

    for (int i = 0; i < n; i++)
    {
        v.add(randomInteger(0, 50));
    }

    v.sort();
    return v;
}

int main()
{
    Vector<int>v = createSortedRandomVector(10);
    cout << v << endl;

    while (true)
    {
        cout << endl << "What integer shall we search for? (-1 to quit) ";
        int key = getInteger();

        if (key == -1)
        {
            break;
        }

        cout << "-> result: " << binarySearch(v, key) << endl;
    }

    cout << "Bye!" << endl;
    return 0;
}

/*

Binary Search Runtime (and a Reminder of the Awesomeness of Logarithmic Runtimes!)

Notice that with each O(1) comparison to the midpoint of our remaining search space, binary search cuts 
our search space in half. This repeated halving of our search space matches the pattern we saw for 
logarithmic runtimes in our lecture on Big-O. Indeed, the worst-case runtime for binary search is 
O(log n). The best-case runtime is O(1), where the key we're searching for is at the very middle of 
the vector and is therefore the first element we examine.

LOG RUNTIMES ARE AMAZING!!!

*/