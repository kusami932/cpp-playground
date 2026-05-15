#include <iostream>
#include "console.h"
#include "quokka.h"
#include "simpio.h"
using namespace std;

Quokka_Immortal * createQuokka()
{
    cout << "in createQuokka..." << endl;
    getline();
    
    Quokka_Immortal *q = new Quokka_Immortal("Muffinface");

    cout << "about to leave createQuokka..." << endl;
    getline();

    return q;
}

int main()
{
    for (int i = 0; i < 100000000; i++)
    {
        // We now have a box called q that holds the address of our dynamically
        // allocated quokka!
        Quokka_Immortal *q = createQuokka();
        delete q;
        // This releases the memory associated with the address stored in q!
        // Goodbye, memory leak! (This also causes our Quokka object's destructor
        // function to be called!)
    }
}