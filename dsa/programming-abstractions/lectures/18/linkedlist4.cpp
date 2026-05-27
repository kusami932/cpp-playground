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

/*
Head insertion is an O(1) operation. Regardless of how long our linked list is, adding a new element 
to the beginning of our list is simply a matter of creating a new node, setting its next pointer to 
the old head of our linked list, and setting the head to point to our newly created node. 
All of that can be done in O(1) time.

The tail insertion function we saw last time had a linear runtime, but today we explored an idea for 
speeding that up: maintaining a pointer not just to the head of a linked list, but also to the tail! 
If we do that, we can achieve O(1) insertion at the tail of our list: we just set the tail's next pointer 
to a new node, then move the tail pointer forward. This is a ✨dramatic✨ improvement in runtime, and it 
only costs us two things: (1) the memory associated with maintaining a tail pointer (typically just 8 bytes 
in C++) and (2) the complexity and effort associated with writing code that correctly keeps track of the tail pointer.

Maintaining a tail pointer actually even makes our head insertion function more complex. That's because 
if we pass an empty list to our head insertion function, the new node we create will not only be the 
first node in the list, but also the last. If we have just one node in our list, it's both the head 
and the tail -- and so we need our head insertion function to be able to update both our head and tail pointers.
*/

void tailInsert(Node *&head, Node *&tail, int data)
{
    // If tail is nullptr, that means the list is currently empty, and the new node
    // we're creating will be the first node in our list. That means that it is both
    // the head and tail of the list, so we set both of those pointers here.
    if (tail == nullptr)
    {
        head = tail = new Node(data);
        return;
    }

    // Otherwise, if we already have a tail node, simply tack a new node on the end
    // of the list right after it, and then move the tail pointer forward to point
    // to that new node. Tada!
    tail->next = new Node(data);
    tail = tail->next;
}