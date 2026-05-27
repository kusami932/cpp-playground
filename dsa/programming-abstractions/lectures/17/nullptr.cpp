#include <iostream>
#include "console.h"
using namespace std;

int main()
{
    int *ptr = nullptr;

    // Suppose we have many lines of code here, and the logic is complex and twisty,
    // and we aren't quite sure at first glance whether ptr has ever been updated to
    // point to an actual integer. If not, we don't want to dereference it, because
    // that could lead to a segmentation fault and crash our program.
    //
    // No worries! We can just check whether its still nullptr, like so:

    if (ptr != nullptr)
    {
        cout << "Aha! It's safe to dereference ptr." << endl;
        *ptr = 50;
    }
    else
    {
        cout << "OoOOOOoh! We didn't dereference the pointer! Hooray!" << endl;
    }

    return 0;
}

/*

Dereferencing a null pointer will cause a segmentation fault

*** STANFORD C++ LIBRARY
*** The LinkedLists program has terminated unexpectedly (crashed)
*** A segmentation fault (SIGSEGV) occurred during program execution

    This error indicates your program attempted to dereference a pointer
    to an invalid memory address (possibly out of bounds, deallocated, nullptr, ...)

*** To get more information about a program crash,
*** run your program again under the debugger.

*/