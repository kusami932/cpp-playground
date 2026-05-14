/*
Introduction to Classes

Fundamentally, a class allows us to package together related pieces of data with functions that operate on that data.
All the ADTs implemented in the Stanford C++ Libraries are classes: Vector, Grid, Stack, Queue, Set, and Map.
A Vector, for example, has underlying data (a collection of elements, as well as size variable maintained behind the scenes) 
as well as functions we can use to manipulate that data (add(), remove(), insert(), and so on).

------------------------------------------------------------------------------------
The OOP Paradigm Shift

In non-object-oriented languages, if we wanted to create a data structure, we had a data representation (typically a struct) 
that was wholly separate from the functions that operated on it. (i.e, a vector variable, we would pass it to an add() function 
as a parameter. The add function typically was not bound to, or part of, the vector variable in any way.)

Object-oriented programming breaks down a bit of the wall between data and functionality and unifies those concepts 
into classes in a way that jives with our notion of how we interact with many objects in the real world.

For example, when I go into an elevator and press a button to take me to the fifth floor, I don't think of myself as 
picking up the elevator and passing it through a goToFloor(elevator, whichFloor) function that is wholly separate 
from the elevator. Rather, I think of that functionality as being built into the elevator. The button and its related 
functionality are fully integrated with the elevator; they are part of the fundamental identity of that elevator.

The object-oriented paradigm allows us to reflect that sort of integration in code and build programs that manipulate 
the state of our data in ways that really reflect our understanding of how we interact with objects in the real world.
------------------------------------------------------------------------------------
Class, Object, Instance
When we create a new class, we are typically also creating a new datatype.
*/

#include <iostream>
#include "console.h"
#include "vector.h"
using namespace std;

int main()
{
    // Below, the Vector class is being used as the datatype for variables v1 and v2.
    // v1 and v2 are both Vector objects. They are instances of the Vector class.
    Vector<int> v1;
    Vector<string> v2;

    return 0;
}

/*
Insofar as a class gives us a new datatype, we can think of a class as being a sort of blueprint that tells us 
how to build a variable of this new type, in the same way that we can take the blueprints for a house and 
build multiple instances of that particular plan. We can take a class and build multiple variables of that type.

They each have their own "interiors," so to speak, which are distinct from one another; 
adding elements to one vector does not add elements to the other. The two vectors' interiors 
are even "decorated" with completely different types of: one contains ints, and the other has strings.

v1 and v2 are OBJECTS. An object is an INSTANCE of a CLASS. 
Specifically, v1 and v2 are instances of the Vector class. 

(Similarly, if we had the blueprints for some house called the "Monroe" model, 
if we built two houses from those blueprints, we would say that we had two 
instances of the Monroe model. Those houses would also be considered objects in the physical world.)
------------------------------------------------------------------------------------
Why build new classes?

Building new classes will allow us to expand and enrich our vocabulary of abstractions, which allow us to solve more problems.
By understanding how classes work, we will gain the ability to add new tools to our problem-solving toolkit that we'll be able
 to use to solve problems that our existing ADTs might not be ideally suited for. importance of using abstractions and how they 
 can enhance the clarity of our code and our ability to communicate efficiently and effectively.
------------------------------------------------------------------------------------
Interface (.h) and Implementation (.cpp)

We have so far taken a client-side approach to ADTs, where we have examined only their interfaces and 
had most of the implementation details for those ADTs abstracted away from us.

When we create a class, there are two primary components we have to code up: the interface and the implementation.

    The interface is what a class looks like from the outside: what data is in the class 
    and what functions we can call. On the interface side, functions are typically presented 
    in the form of functional prototypes, not full-fledged function definitions. When we 
    create a new class, its interface will be articulated in a .h file (a "header file").

    The implementation is where we find the actual definitions of the functions that drive 
    the behaviors of our class -- not just the functional prototypes. When we create a new 
    class, its implementation will be articulated in a .cpp file (an "implementation file").

Think of the interface as telling us "what" the class can do for us and the implementation as telling us "how" those things get done.
*/