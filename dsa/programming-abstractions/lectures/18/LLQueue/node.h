#ifndef NODE_H
#define NODE_H

struct Node
{
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = nullptr;
    }
};

#endif // NODE_H