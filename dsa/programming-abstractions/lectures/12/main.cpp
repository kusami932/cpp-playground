#include <iostream>
#include "console.h"
#include "quokka.h"
#include "vector.h"  // for Quokka class
using namespace std;

int main()
{
    // Yes, we can create a vector of Quokka objects!
    Vector<Quokka> v;

    v.add(Quokka("Muffinface", 5, "muffinface.jpg"));
    v.add(Quokka("Hemmy", 4, "hemmy.jpg"));
    v.add(Quokka("Percival", 5, "percival.jpg"));
    v.add(Quokka("Fred", 5, "04.jpg"));
    v.add(Quokka("Lovelace", 5, "05.jpg"));
    v.add(Quokka("Night Terror", 5, "06.jpg"));
    v.add(Quokka("Glen", 5, "07.jpg"));

    for (Quokka q : v)
    {
        q.printInfo();
    }
}

/*
We refer to the variables within a class as its MEMBER VARIABLES.
We refer to the functions within a class as its MEMBER FUNCTIONS.
We often say that member variables define the STATE of an object, while member functions define the BEHAVIORS an object can perform.
A function whose name matches the name of the class where it resides is a CONSTRUCTOR function.

Every Quokka we create gets its own copies of the variables above. When that happens, we refer to those variables as INSTANCE VARIABLES. 
In OOP, we sometimes have variables that are shared across all instances of a class. You might hear me use the terms "member variables" 
and "instance variables" interchangeably to refer to the sorts of variables we're defining above.

Note that it's considered best practice not to issue a using namespace std; statement in our quokka.h file. If we did that, 
then that namespace would apply to every source file with an #include "quokka.h" directive. We instead prefer to qualify 
anything from the std namespace in our header file using the tedious std:: syntax.
*/