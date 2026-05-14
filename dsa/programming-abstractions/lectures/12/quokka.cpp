#include <iostream>
#include "lexicon.h"
#include "quokka.h"
#include "strlib.h"
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

string Quokka::getName()
{
    return _name;
}

void Quokka::setName(string name)
{
    Lexicon lex("bad_words.txt");
    for(string naughtyWord : lex)
    {
        if (stringContains(toLowerCase(name), toLowerCase(naughtyWord)))
        {
            error("Name contains bad word: " + naughtyWord);
        }
    }
    _name = name;
}

int Quokka::howAdorable()
{
    return _howAdorable;
}

string Quokka::location()
{
    return _location;
}

string Quokka::profilePic()
{
    return _profilePic;
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

