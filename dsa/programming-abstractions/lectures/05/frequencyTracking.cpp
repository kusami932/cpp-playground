/*

Map Application: Frequency Tracking


Maps are great for tracking how many times a key occurs in some data set. The following program opens 
a file (poem.txt) and maps each word in the file to its frequency of occurrence -- a map of strings to integers.

The goal here is not to memorize all the file I/O and string processing functions being used, but rather to 
gain a general awareness that those things exist in our libraries and -- most importantly -- to see how a 
map can be used to track word frequencies.

*/

#include <iostream>
#include "console.h"
#include "filelib.h"
#include "map.h"
#include "strlib.h"
#include "vector.h"
using namespace std;
const int FREQUENCY_THRESHOLD = 100;

bool getFrequencies(string filename, Map<string, int>& map)
{
    ifstream ifs;

    if(!openFile(ifs, filename))
    {
        cout << "Failed to open file in getFrequencies(): " << filename << endl;
        return false;
    }

    Vector<string> lines = readLines(ifs);
    for (string line : lines)
    {
        Vector<string> words = stringSplit(line, " ");
        for (string word : words)
        {
            // Note that map.get(word)++ would not work here, but map[word]++ does.
            map[word]++;
        }
    }

    return true;

}


int main()
{
    Map<string, int> wordToFrequencyMap;
    getFrequencies("poem.txt", wordToFrequencyMap);

    for (string s : wordToFrequencyMap.keys())
    {
        cout << s << ": " << worToFrequencyMap.get(s) << endl;
    }

    wordToFrequencyMap.clear()

    getFrequencies("dracula.txt", wordToFrequencyMap);

    for (string s : wordToFrequencyMap.keys())
    {
        if (wordToFrequencyMap.get(s) > FREQUENCY_THRESHOLD)
        {
            cout << s << ": " << wordToFrequencyMap.get(s) << endl;
        }
    }

    return 0;
}

/*

Map Variable Naming Convention
A common naming convention for map variable names in industry is to frame them in terms of what the keys and values 
represent. For example, if we have a map where the keys are ISBNs and the values are the book titles associated with 
those ISBNs, we might name such a map [isbnToTitleMap]

*/