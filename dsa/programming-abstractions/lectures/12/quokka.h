#ifndef QUOKKA_H // "include guards"
#define QUOKKA_H // effectively ensure that bad things don't happen if we #include the same header file multiple times somewhere. 

#include <iostream>

class Quokka
{
    public:
        // member functions (which govern behaviors an object can perform)
        Quokka();
        bool haveASnack(std::string snack);
        void printInfo(); 

        // member variables (which govern the state of an object)
        std::string _name;
        int _howAdorable;
        std::string _location;

};

#endif

/*

In this class definition, we list variable declarations and the functional prototypes that will constitute our class. 
Under the public: heading, we place all the variables and functions we want any client who uses our class to have access. 
Those items constitute our public-facing interface. Under the private: heading, we place variables and functions that 
we don't want our client to have access to. We mostly mark as private anything that a user could 
abuse to leave our class in a broken state. (public and private are called access modifiers.)

There's a function called Quokka() within our Quokka class definition. A function whose name matches our class name 
is called a constructor function. It is called automatically anytime we create an instance of our class, which is 
often useful for doing any important initialization tasks when a class is instantiated.

We #include our class's header file from out .cpp file. That way, this source file is aware of our class definition, 
including all variables and functional prototypes, and so we can freely refer to all those variables and function 
from any functions that we add to this file.

Before each function we define that is part of our class, we must give the class name, followed by two colons, 
like so: ClassName::functionName. This tells C++ that the function we're creating is actually part of the class 
in question and not some free-floating auxiliary function that exists outside of the class.

*/