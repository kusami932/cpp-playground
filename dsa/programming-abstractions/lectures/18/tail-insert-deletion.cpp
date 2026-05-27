#include <iostream>
#include "console.h"
#include "error.h"
using namespace std;

struct Node
{
    int data;
    Node *next;  // a pointer to a Node -- the next node in our list

    Node(int d)
    {
        data = d;
        next = nullptr;
    }
};

void headInsert(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;

    // If tail is null and we have been keeping both our head and tail pointers up
    // to date, that means the node we just inserted is the only node currently in
    // the list -- making it both the head and the tail. We update the tail pointer
    // accordingly.
    if (tail == nullptr)
    {
        tail = head;
    }
}

int offWithItsHead(Node *&head, *&tail)
{
    if (head == nullptr)
        error("Empty list in offWithItsHead().");
    
    // Let's hold onto our return value before deleting the head.
    // "retval" stands for "return value."
    int retval = head->data;

    // Let's hold onto the head node we'll be deleting.
    Node *temp = head;

    // Move our head pointer forward.
    head = head->next;

    // If moving our head pointer forward caused it to fall off the end of the list,
    // that means the list is now empty. We need to update the tail pointer in this
    // case to reflect that.
    if (head == nullptr) tail = nullptr;
    
    delete temp;
    return retval;
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    headInsert(head, tail, 10);
    headInsert(head, tail, 12);
    headInsert(head, tail, 15);

    while (head != nullptr)
    {
        cout << offWithItsHead(head, tail) << endl;
    }

    cout << endl << "Pointers (should be 0 for nullptr):" << endl;
    cout << head << endl;
    cout << tail << endl;

    return 0;
}

/*
Note that if someone asked what the runtime is for insertion at the tail of a linked list, 
a precise answer would be to say, "It depends. If we maintain a tail pointer, 
we can do that in O(1) time. If not, it takes O(n) time."

Note that deletion at the tail of a linked list is O(n), even if we maintain a pointer to the 
tail of the list. With a tail pointer, we could certainly delete the dynamically allocated tail 
node in O(1) time, but we would then have to move the tail pointer back by one node in order to 
keep that pointer current -- and we can't do that in a traditional linked list. We have to start 
at the beginning of the list and loop forward until we find that next-to-last node, which will take O(n) time.


	    insertion	               deletion

head	    O(1)	                O(1)

tail	O(1) if tail pointer    O(1) if tail pointer and doubly-linked
        O(n) otherwise	         O(n) otherwise
*/
