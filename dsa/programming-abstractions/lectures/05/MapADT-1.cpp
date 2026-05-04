/*

Map Overview
A map is an associative data structure. It maps keys to values (it associates a given key with a value). 
Each key in a map is distinct and maps to exactly one value. If we try to map a key to a new value, we do 
not get a second entry in our map; rather, we overwrite the previous association, and the key is now only 
associated with the new key. Here are some examples:

    1. We could map the social security numbers of everyone in class to their names. The social security numbers 
       would be the keys in the map, and the values would be student names. After constructing such a map, we could 
       feed it a social security number, and it would spit out the name of the person associated with that SSN.

    2. We could map the ISBNs of books to the titles of those books. ISBNs would form the keys in the map, and the 
       values would be the book names. After constructing such a map, we could feed it an ISBN, and it would spit 
       out the name of the corresponding book. We could create a similar map of ISBNs to author names.


    The Stanford map is a homogenous container, in that the keys must all be of the same type, and the value must 
    all be of the same type (although the key type may be different from the value type). Whenever we create a map, 
    we specify the key and value element types for that map as type parameters.
*/

#include <iostream>
#include "console.h"
#include "map.h"
using namespace std;

int main()
{
    Map<string, string> map;

    // Here, the keys are "Sean", "Yasmine", and "Tommy". The values
    // are "Szumlanski", "Alonso", and "DeBenedetti".
    map["Sean"] = "Szumlanski";
    map["Yasmine"] = "Alonso";
    map["Tommy"] = "DeBenedetti";

    cout << map << endl;

    // look up the value associated with some key
    // gets (and prints) the value associated with "Sean"
    cout << map["Sean"] << endl;
    
    // map's get() function:
    cout << map.gets("Sean") << endl;


    return 0;

    /*
    The above output uses colons to indicate what keys are mapped to which values. The value 
    associated with "Yasmine" is "Alonso". Another way of saying that is that the key "Yasmine" 
    maps to the value "Alonso".
    */
}