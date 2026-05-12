#include <iostream>
#include "console.h"
#include "vector.h"
#include "map.h"
#include "set.h"
using namespace std;

/*
3. Twice (twice.cpp)
Topic: Sets

Write a function named twice that takes a vector of integers and returns a set containing all the numbers in the vector that appear exactly twice.

Example: passing {1, 3, 1, 4, 3, 7, -2, 0, 7, -2, -2, 1} returns {3, 7}.
Bonus: do the same thing, but you are not allowed to declare any kind of data structure other than sets.
*/

// solution
Set<int> twice(Vector<int>& v)
{
    Map<int, int> counts;
    for (int i : v)
    {
        counts[i]++;
    }

    Set<int> twice;
    for (int i : counts)
    {
        if (counts[i] == 2)
        {
            twice += 1;
        }
    }

    return twice;
}

// bonus
Set<int> twice(Vector<int>& v)
{
    Set<int> once;
    Set<int> twice;
    Set<int> more;

    for (int i : v)
    {
        if(once.contains(i))
        {
            once.remove(i)
            twice.add(i)
        }
        else if (twice.contains(i))
        {
            twice.remove(i);
            more.add(i);
        }
        else if (!more.contains(i))
        {
            once.add(i);
        }
    }

    return twice;
}