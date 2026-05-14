#include <iostream>
#include "quokka.h"
using namespace std;

Quokka::Quokka()
{
}

Quokka::Quokka(string name, int howAdorable, string profilePic)
{

    // This function has access to all member variables inside the class.
    _name = name;
    _howAdorable = howAdorable;
    _profilePic = profilePic;

    // Quokkas are only found (natively) in Australia, so passing this location
    // as a parameter isn't necessary.
    _location = "Australia";
}

// Recall that we need Quokka:: in front of any functions that are part of the class,
// to distinguish them from free-floating functions that exist outside the class.
// Note that the datatype comes before the class name when defining functions
// within a class.
void Quokka::printInfo()
{
    // This function can refer to all the member variables inside this class!
    cout << _name << " (how adorable: " << _howAdorable
        << ", loc: " << _location << ")" << endl;
}

bool Quokka::haveASnack(string snack)
{
    return true;
}

