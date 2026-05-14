#include <iostream>
#include "console.h"
using namespace std;

int main()
{
    int array[5];

    // Prints addresses of all cells in the array.
    for (int i = 0; i < 5; i++)
    {
        cout << "&(array[" << i << "]): " << &(array[i]) << endl;
    }

    // Prints base address of array. Notice this is the same as &(array[0]).
    cout << endl << "Base address of array: " << array << endl;

    return 0;
}

/*
Array looks a lot like a pointer. It contains, in fact, the address of an integer -- the first integer in our array. 
It stands to reason that if we create a pointer of type int *, we should be able to use that to loop through our array, as well. 
*/