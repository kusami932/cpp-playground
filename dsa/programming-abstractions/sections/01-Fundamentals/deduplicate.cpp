#include <iostream>
#include <string>
using namespace std;

/*
5. Debugging Deduplicating (deduplicate.cpp)
Topics: Vector, strings, debugging

Consider the following incorrect C++ function, which accepts as input a Vector<string> 
and tries to modify it by removing adjacent duplicate elements:

void deduplicate(Vector<string> vec) 
{
    for (int i = 0; i < vec.size(); i++) 
    {
        if (vec[i] == vec[i + 1]) 
        { 
            vec.remove(i);
        }
    }
}

Vector<string> hiddenFigures = {
    "Katherine Johnson",
    "Katherine Johnson",
    "Katherine Johnson",
    "Mary Jackson",
    "Dorothy Vaughan",
    "Dorothy Vaughan"
};

deduplicate(hiddenFigures);
// hiddenFigures = ["Katherine Johnson", "Mary Jackson", "Dorothy Vaughan”]

The problem is that the above implementation of deduplicate does not work correctly. 
In particular, it contains three bugs. First, find these bugs by writing test cases 
that pinpoint potentially erroneous situations in which the provided code might fail, 
then explain what the problems are, and finally fix those errors in code.


There are three errors here:
    1. Calling .remove() on the Vector while iterating over it doesn’t work particularly nicely. 
       Specifically, if you remove the element at index i and then increment i in the for loop, 
       you’ll skip over the element that shifted into the position you were previously in.

    2. here’s an off-by-one error here: when i = vec.size() - 1, the indexing vec[i + 1] reads 
       off the end of the Vector.

    3. The Vector is passed in by value, not by reference, so none of the changes made to it 
       will persist to the caller.
*/

// solution 1
void deduplicate1(Vector<string>& vec)
{
    for(int i = 0; i < vec.size() - 1;)
    {
        if(vec[i] == vec[i + 1])
        {
            vec.remove(i);
        }
        else
        {
            i++;
        }
    }
}

// solution 2
void deduplicate2(Vector<string>& vec)
{
    for(int i = vec.size() -1; i > 0; i--)
    {
        if(vec[i] == vec[i - 1])
        {
            vec.remove(i)
        }
    }
}