#include <iostream>
#include "console.h"
using namespace std;

struct Node
{
    int data;
    Node *next;  // a pointer to a Node -- the next node in our list
};

Node *createNode(int data)
{
    Node *n = new Node;
    n->data = data;
    n->next = nullptr;

    return n;
}

// Prints the contents of our linked list.
void printList(Node *head)
{
    // Remember that this local variable called 'head' is separate from the one
    // called 'head' down in main()! We can change the address stored in this local
    // copy without changing what 'head' points to back in main(). So, we could
    // have moved 'head' forward through this list instead of creating the helper
    // variable, 'current'.

    Node *current = head;

    while (current != nullptr)
    {
        cout << current->data;

         // If this isn't the last node, print an arrow, because there's more to come.
        if (current->next != nullptr)
        {
            cout << " -> ";
        }

        current = current->next;
    }
    cout << endl;
}

int main()
{
    Node *head = nullptr;

    head = createNode(10);
    head->next = createNode(25);
    head->next->next = createNode(12);

    // We now have the following:
    //
    // addr:    0xf9800          0xf4d33          0xc625e
    //        +---------+      +---------+      +---------+
    // data:  |   10    |      |   25    |      |   12    |
    //        +---------+ ---> +---------+ ---> +---------+
    // next:  | 0xf4d33 |      | 0xc625e |      | nullptr |
    //        +---------+      +---------+      +---------+

    printList(head);

    // WARNING!
    // This has a memory leak! We aren't freeing the list before returning from main().

    return 0;
}

/*
Be sure you're comfortable with the while-loop's terminating condition, as well as the 
slightly different condition for checking whether we've hit the last node (used to 
determine whether to print an arrow to the screen). You'll also want to be super familiar 
with the current = current->next; idiom that we use to move pointers forward when traversing a linked list.

Rather than creating an auxiliary function that exists outside our Node struct, we could 
create a constructor function within the struct. (C does not allow that sort of thing, but C++ does.)

*/