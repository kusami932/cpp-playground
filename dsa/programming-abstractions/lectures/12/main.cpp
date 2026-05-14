#include <iostream>
#include "console.h"
#include "quokka.h"  // for Quokka class
using namespace std;

int main()
{
    // If we didn't #include "quokka.h" above, the compiler would have no idea what
    // a Quokka was when it reached the following lines, and so our program would
    // fail to compile.

    // (Terminology) Below, when we declare q1, we are doing all of the following:
    //  - creating a Quokka
    //  - instantiating the Quokka class
    //  - creating an instance of the Quokka class
    //  - creating a Quokka object

    Quokka q1;
    q1._name = "Muffinface";
    q1._howAdorable = 5;
    q1._location = "Australia";

    // q2 has its own member variables that are distinct from the member variables
    // of q1. Note that Hemmy's adorableness score is only a 4 -- possibly because
    // no matter how adorable you are, it's just hard to look like a 5/5 when you're
    // standing next to Chris Hemsworth.
    Quokka q2;
    q2._name = "Hemmy";
    q2._howAdorable = 4;
    q2._location = "Australia";

    q1.printInfo();
    q2.printInfo();

    return 0;
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