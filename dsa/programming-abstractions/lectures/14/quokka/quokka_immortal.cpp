#include <iostream>
#include "quokka.h"
using namespace std;

Quokka::Quokka()
{
}

Quokka::Quokka(string name)
{
    _name = name;
    cout << "Hello, " << _name << endl;
}

Quokka::~Quokka()
{
    cout << "R.I.P " << _name << endl;
}