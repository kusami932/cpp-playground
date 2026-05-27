/*
Passing pointer to a function that takes an int * parameter 
will get an entirely new copy of that pointer in our other function. 
Changing its value there will not change the value of ptr back in main()
*/

void illuminate(int *ptr)
{
    ptr = nullptr;
}

int main()
{
    int x = 50;
    int *ptr = &x;

    illuminate(ptr);

    return 0;
}


/*

    illuminate():

    ptr
    +------------+
    |  0xdec08   | <-- illuminate() has its own local variable called ptr!
    +------------+     This is *not* the same variable as the one in main()!

    main():

    x     0xdec08
    +-----------+
    |    50     |
    +-----------+

    ptr   0x55824
    +-----------+
    |  0xdec08  |
    +-----------+


    illuminate():

    ptr
    +------------+
    |  nullptr   | <-- We only changed the local copy of nullptr.
    +------------+     This does *not* affect the copy back in main()!

    main():

    x     0xdec08
    +-----------+
    |    50     |
    +-----------+

    ptr   0x55824
    +-----------+
    |  0xdec08  | <-- This remains unaffected!
    +-----------+

*/

// By injecting an ampersand here, we turn this ptr variable into a reference to the
// pointer variable back in whatever function called this one. ptr is now an alias or
// synonym for the corresponding parameter back in our calling function. If we set
// ptr equal to something, we're actually changing the value contained in the
// corresponding variable back in our calling function.
void right_illuminate(int *&ptr)
{
    ptr = nullptr;
}

/*
illuminate():

   ptr
   +------------+
   |     🌀     | <-- Because we passed by reference, this is now just a portal to
   +------|-----+     the ptr variable back in main()! It no longer has its own copy
          |                   of the memory address in question (0xdec08)!
main():   +----------+
                     |
   x     0xdec08     |
   +-----------+     |
   |    50     |     |
   +-----------+     |
                     |
   ptr   0x55824     |
   +-----------+     |
   |  0xdec08  <-----+
   +-----------+

illuminate():

   ptr
   +------------+
   |     🌀     | <-- Nothing has changed here. This is still just a portal to the
   +------|-----+     ptr variable back in main()!
          |
          |
main():   +----------+
                     |
   x     0xdec08     |
   +-----------+     |
   |    50     |     |
   +-----------+     |
                     |
   ptr 0x55824       |
   +-----------+     |
   |  nullptr  <-----+   <-- This value changed! Since the ptr in illuminate() was just
   +-----------+             a reference (i.e., portal) to this pointer, changing ptr
                             in illuminate() actually changed the value of this pointer
                                                  back in main()!

If you have a pointer in some function foo(), and you want some function bar() 
to be able to change the value that the pointer in function foo() contains, 
you should pass that pointer to bar() by reference using a *& parameter.

We could also give illuminate() the power to change ptr back in main() 
by passing the function a "double pointer" (a pointer to a pointer: int **ptr),
but that's a bit more complex. 

*/