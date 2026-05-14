#include <iostream>
#include "quokka.h"
using namespace std;

Quokka::Quokka()
{
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

