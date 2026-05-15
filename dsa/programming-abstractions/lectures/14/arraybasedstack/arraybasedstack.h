#ifndef ARRAYBASEDSTACK_H
#define ARRAYBASEDSTACK_H

// Starting with a ridiculously small initial capacity so we can observe the
// expansion of the stack in a small test case.
#define DEFAULT_STACK_CAPACITY 3

class ArrayBasedStack
{
    public:
        ArrayBasedStack();
        ~ArrayBasedStack();
        void push(int value);
        int pop();
        int peek() const;
        int size() const;
        bool isEmpty() const;

    private:
        int *_elements;
        int _size;
        int _capacity;
};

#endif 

