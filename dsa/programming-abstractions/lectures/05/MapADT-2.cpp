/*

Pinging Keys That Aren't in a Map: Two Interesting Behaviors

If we try to look up the value associated with some key that isn't in a map, we get two interesting behaviors:
    
    1. Firstly, the Stanford map will return some default value (0 for integers, the empty string for strings)
    2. Secondly, if we use the map[key] syntax for a key that is not present in our map, the Stanford map adds 
       that key to the map and associates it with whatever default value it returns! This does not happen with 
       the get(key) syntax.
*/

#include <iostream>
#include "console.h"
#include "map.h"
#include "vector.h"
using namespace std;

int main()
{
    Map<string, string> map;

    // Here, the keys are "Sean", "Yasmine", and "Tommy". The values
    // are "Szumlanski", "Alonso", and "DeBenedetti".
    map["Sean"] = "Szumlanski";
    map["Yasmine"] = "Alonso";
    map["Tommy"] = "DeBenedetti";

    // Below, the stars (*) are printed just to show that there are no characters --
    // not even spaces -- in the empty string results we're getting.

    // This prints an empty string. "Nathan" is not added to the map.
    cout << "result: *" << map.get("Nathan") << "*" << endl;

    // This also prints an empty string, but "Sonia" does get added to the map.
    cout << "result: *" << map["Sonia"] << "*" << endl;

    // Here, we verify the map has changed. "Sonia" has been added, but not "Nathan".
    cout << map << endl;
    

    if (map.containsKey("Sonia"))
    {
        // We only execute this line if "Sonia" is present in the map as a key. So,
        // there should be no change to the map this time.
        cout << "result: *" << map["Sonia"] << "*" << endl;
    }

    // The map should have only the two original associative mappings. "Sonia" was not
    // added as a key this time.
    cout << map << endl;

    return 0;

}

/*
ISBNs and Book Mappings

I mentioned briefly in class today that we could create a map that associates book titles with author names. 
One problem with that, however, is that there are many books in the world that have the same title as one another 
but that were written by different authors. So, a more likely thing to do would be to map ISBNs to book names and 
author names. A problem there is that the latest ISBN standard uses 13 digits, which a normal int in C++ cannot 
handle. To get around that, we could actually just store 13-digit ISBNs as strings instead of integers.

I should also mention that it's unlikely that we would maintain multiple maps for our books: one for mapping ISBNs 
to book titles, another for mapping ISBNs to the authors of those books, and so on. We would more likely create a 
new datatype that would allow us to bundle together a bunch of information about a book (its title, author(s), 
publisher, publication date, and so on). If we called that datatype BookInfo, for example, we would then map ISBN 
keys to BookInfo values. We will actually talk later this quarter about how to bundle data together like that and 
create new datatypes.
*/

void distinctMapKeys()
{

    Map<string, string> map;

    // Here, the keys are "Sean", "Yasmine", and "Tommy". The values
    // are "Szumlanski", "Alonso", and "DeBenedetti".
    map["Sean"] = "Szumlanski";
    map["Yasmine"] = "Alonso";
    map["Tommy"] = "DeBenedetti";

    // Here, we associate "Julie" with "Zelenski".
    map["Julie"] = "Zelenski";

    // This overwrites the mapping of "Julie" to "Zelenski". The "Julie" key is
    // instead mapped to "Stanford" now, and we lose the old mapping!
    map["Julie"] = "Stanford";

    cout << map << endl;
    cout << "Map size: " << map.size() << endl;

    return 0;
}

// Associating First Names with Multiple Last Names
// The single value that a key maps to could be an entire data structure that holds multiple elements.

void multipleValueMaps()
{
    Map<string, Vector<string>> map;

    // Super Important:
    // Notice the need for the & to create references in the lines below!

    // We know that initially, "Julie" is not in the map. However, the brackets
    // syntax will automatically associate that key with an empty vector of strings.
    Vector<string>& julieNames = map["Julie"];
    julieNames.add("Zelenski");
    julieNames.add("Stanford");

    Vector<string>& chrisNames = map["Chris"];
    chrisNames.add("Gregg");
    chrisNames.add("Piech");

    Vector<string>& nickNames = map["Nick"];
    nickNames.add("Troccoli");
    nickNames.add("Parlante");

    cout << map << endl;

    // Notice that there are only three values in the map, not size!
    // Each vector is a value, and there are only three vectors here.
    cout << "Map size: " << map.size() << endl;
}

void vectorMap()
{
    Map<string, Vector<string>> map;

    map["Julie"].add("Zelenski");
    map["Julie"].add("Stanford");
    map["Chris"].add("Gregg");
    map["Chris"].add("Piech");
    map["Nick"].add("Troccoli");
    map["Nick"].add("Parlante");

    cout << map << endl;

    // Notice that there are only three values in the map, not size!
    // Each vector is a value, and there are only three vectors here.
    cout << "Map size: " << map.size() << endl;
}