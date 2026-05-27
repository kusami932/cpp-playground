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
    Node *current = head;

    while (current != nullptr)
    {
        cout << current->data;
        if (current->next != nullptr)
        {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
}

// Insert a new node at the end of the linked list.
void tailInsert(Node *&head, int data)
{
    // If we have an empty list, just create a new node (which becomes our head)
    // and return back to main().
    if (head == nullptr)
    {
        head = createNode(data);
        return;
    }

    Node *current = head;
    // Loop forward until 'current' points to last node, which happens when its
    // 'next' pointer is nullptr (not when current itself is nullptr; if that
    // happens, we will have fallen off the end of our list).

    while (current->next != nullptr)
    {
        current = current->next;
    }
    // When we get here, 'current' points to the last node in the list. We set
    // its 'next' field equal to a new node to tack onto the end of the list.
    current->next = createNode(data);
}

int main()
{
    Node *head = nullptr;

    tailInsert(10);
    tailInsert(25);
    tailInsert(12);

    printList(head);
}

/*
if we hadn't initialized head to nullptr in main(), and if we didn't have a compiler flag set 
to prevent us from using uninitialized variables, then head would contain a garbage memory 
address, and our tail insertion function would likely have crashed.

The tail insertion function below has a linear runtime.
*/