#ifndef LLQUEUE_H
#define LLQUEUE_H

#include "node.h"  // for Node struct used in private fields

class LLQueue
{
public:
    LLQueue();
    ~LLQueue();
    void enqueue(int data);
    int dequeue();
    int peek() const;
    int size() const;
    bool isEmpty() const;

private:
    Node *_head;
    Node *_tail;
    int _size;
};

#endif // LLQUEUE_H