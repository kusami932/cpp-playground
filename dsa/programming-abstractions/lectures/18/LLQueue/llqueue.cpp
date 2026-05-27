#include "llqueue.h"
#include "node.h"
#include "error.h"
using namespace std;


LLQueue::LLQueue()
{
    _head = nullptr;
    _tail = nullptr;
    _size = 0;
}

LLQueue::~LLQueue()
{
    // WARNING!
    // This has a memory leak! We aren't freeing the list in our destructor function.
}

void LLQueue::enqueue(int data)
{
    _size++;

    if (_tail == nullptr)
    {
        _tail = _head = new Node(data);
        return;
    }

    _tail->next = new Node(data);
    _tail = _tail->next;
}

int LLQueue::dequeue()
{
    if (_head == nullptr)
    {
        error("Empty list in dequeue()!");
    }

    int retval = _head->data;
    
    Node *temp = _head;
    _head = _head->next;
    if (_head == nullptr) _tail = nullptr;

    delete temp;
    --_size;
    return retval;
}

int LLQueue::peek() const
{
    if (_head == nullptr)
    {
        error("Empty list in peek()!");
    }

    return _head->data;
}

int LLQueue::size() const
{
    return _size;
}

bool LLQueue::isEmpty() const
{
    return _head == nullptr;
}