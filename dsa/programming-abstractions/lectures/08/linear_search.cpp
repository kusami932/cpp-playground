#include <iostream>
#include "console.h"
#include "random.h"  // for randomInteger()
#include "simpio.h"  // for getInteger()
#include "vector.h"
using namespace std;

/*
This function simply checks the vector sequentially, starting at index 0, and stops as soon 
as it finds the key. This particular approach to searching is called "linear search."
*/


// Takes a vector of integers and some key to search for. Returns true if key is
// in the vector, false otherwise. Passing vector by reference for efficiency.
bool linearSearch(Vector<int>& v, int key)
{
    for (int i = 0; i < v.size(); i++)
    {
        if(v[i] == key)
        {
            return true;
        }
    }

    // If we make it through the loop without finding our key, it must not be in
    // our vector.
    return false;
}

/*
A common alternative approach to a search function like this is to return the first index where 
we find the key we're searching for. In that case, we often return -1 to indicate failure to find 
the key, because -1 is never a valid index in a vector.
*/

// Takes a vector of integers and some key to search for. Returns the first index
// where key occurs, or -1 if key is not present. Passing vector by reference for
// efficiency.
int altLinearSearch(Vector<int>& v, int key)
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