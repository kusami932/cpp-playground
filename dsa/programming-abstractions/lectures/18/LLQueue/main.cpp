#include <iostream>
#include "console.h"
#include "llqueue.h"
using namespace std;

int main()
{
    LLQueue q;

    q.enqueue(10);
    q.enqueue(10);
    q.enqueue(10);
    q.enqueue(10);

    while (!q.isEmpty())
    {
        cout << q.dequeue() << " (new size: " << q.size() << ")" << endl;
    }

    q.enqueue(11);
    q.enqueue(16);
    q.enqueue(21);

    cout << endl;
    while (!q.isEmpty())
    {
        cout << q.dequeue() << " (new size: " << q.size() << ")" << endl;
    }

    return 0;
}

