/*
Map Iteration (Keys and Values)

As with sets, the keys in a map are not associated with a numeric index, so we can't iterate over a map 
using a traditional integer-based for-loop. We can, however, use for-each loops to iterate over.
*/

#include <iostream>
#include "console.h"
#include "map.h"
#include "vector.h"
using namespace std;

int main()
{
    Map<string, Vector<string>> map;

    map["Julie"].add("Zelenski");
    map["Julie"].add("Stanford");
    map["Chris"].add("Gregg");
    map["Chris"].add("Piech");
    map["Nick"].add("Troccoli");
    map["Nick"].add("Parlante");

    cout << "Keys:" << endl;
    for (string s : map.keys())
    {
        cout << " - " << s << endl;
    }

    cout << endl << "Values: " << endl;

    for(Vector<string> s : map.values())
    {
        cout << " - " << s << endl;
    }

    // if we iterate over a map directly -- without reference to its keys() or values() functions -- we get the keys:
    for (string s : map)
    {
        cout << s << endl;
    }

    return 0;
}

/*
Sortedness of Map Keys

You might notice that the keys in our map are printed in ASCIIbetical order, just as the elements in our sets. 
Also much like our sets, the insertion and lookup operations for the Stanford map are much more efficient than, 
say, looping through an entire vector to see if some key is present



*/