#include <iostream>
#include "console.h"
using namespace std;

int main()
{
    int array[5] = {10, 15, 20, 25, 30};

    int *p = array;

    for (int i = 0; i < 5; i++)
    {
        cout << p[i] << endl;
    }

    return 0;
    
}

/*
while an array might look a lot like a pointer, the key difference is that a pointer can be assigned a new value, 
causing it to point elsewhere. An array variable name, on the other hand, is bound to the array it represents 
and cannot be made to point elsewhere.
*/