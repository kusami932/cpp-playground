#include <iostream>
#include "console.h"
using namespace std;

/*
We started by modifying our Node struct from last time to contain a constructor function, 
rather than outsourcing node creation to a free-standing createNode() function. We saw the 
this keyword make a resurgence. Recall that in a class (and also in a struct, as we now know), 
this is a pointer to the class/struct variable upon which we called the given function, and 
we can use it to directly access member variables in that class/struct. This is super helpful 
if we have a local variable in a function that shares a name with one of our struct variables.
*/
struct Node
{
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

