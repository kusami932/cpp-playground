#include <iostream>
#include "console.h"
using namespace std;

struct Node
{
    int data;
    Node *next; // a pointer to a Node -- the next node in our list
};

int main()
{
    Node *head = nullptr;

    head = new Node;
    head->data = 10;
    head->next = nullptr;

    // Here's what we have so far:
    //
    // addr:    0xf9800
    //        +---------+
    // data:  |   10    |
    //        +---------+
    // next:  | nullptr |
    //        +---------+

    // Let's continue hooking up nodes manually. In class, we carefully explored how
    // the following lines constructed a valid linked list.

    head->next = new Node;
    head->next->data = 25;
    head->next->next = nullptr;

    // We now have the following:
    //
    // addr:    0xf9800          0xf4d33
    //        +---------+      +---------+
    // data:  |   10    |      |   25    |
    //        +---------+ ---> +---------+
    // next:  | 0xf4d33 |      | nullptr |
    //        +---------+      +---------+

    // Let's keep going...

    head->next->next = new Node;
    head->next->next->data = 12;
    head->next->next->next = nullptr;

    // We now have the following:
    //
    // addr:    0xf9800          0xf4d33          0xc625e
    //        +---------+      +---------+      +---------+
    // data:  |   10    |      |   25    |      |   12    |
    //        +---------+ ---> +---------+ ---> +---------+
    // next:  | 0xf4d33 |      | 0xc625e |      | nullptr |
    //        +---------+      +---------+      +---------+

    // WARNING!
    // This has a memory leak! We aren't freeing the list before returning from main().

    
}