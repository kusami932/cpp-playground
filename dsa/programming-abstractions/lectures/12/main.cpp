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