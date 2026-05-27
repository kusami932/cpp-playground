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

/*
Keep in mind that when writing linked list manipulation functions, we need to be careful
not to dereference null pointers. Along those lines, it's always good to check what your 
linked list functions will do if they receive an empty list or a list with a single node.
*/

void headInsert(Node *&head, int data)
{
    Node *newHead = new Node(data);
    newHead->next = head;
    head = newHead;
}


int offWithItsHead(Node *&head)
{
    if (head == nullptr)
    {
        error("Atempting to remove from empty list in offWithItsHead()!");
    }

    // Hold onto this value so we can return it.
    int retrieval = head->data;

    // Hold onto the old head's address so we can delete it after moving the head
    // pointer forward.
    Node *oldHead = head;

    // Move head pointer to next node in list. If there's no other node, this falls
    // off the end of the list and becomes nullptr, which is exactly what we want.
    head = head->next;
    
    // Now delete the old head node and return the value removed from the list.
    delete oldHead;
    return retrieval;
}