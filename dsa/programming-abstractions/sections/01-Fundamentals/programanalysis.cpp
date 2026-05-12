#include <iostream>
#include <string>
#include "SimpleTest.h"
#include "vector.h"
#include "strlib.h"
using namespace std;

/*
3. Program analysis: C++isms you should know
Topics: Types, References, range based loops, strings, stanford C++ library

   @param input: input string whose last names will be filtered
   @param suffix: the substring which we will filter last names by
   Functionality: this function filters the input string and returns last names
        that end with 'suffix'

*/
Vector<string> filter(string input, string suffix)
{
    Vector<string> filteredNames;
    Vector<string> names = stringSplit(input, ',');

    for (string name : names)
    {
        // convert to lowercase so we can easily compare the strings
        if (endsWith(toLowerCase(name), toLowerCase(suffix)))
        {
            filteredNames.add(name);
        }
    }
    return filteredNames;
}

STUDENT_TEST("Filter Names")
{
    Vector<string> results = filter("Zelenski,Szumlanski,Alonso", "Ski");
    EXPECT_EQUAL(results, {"Zelenski", "Szumlanski"});

    results = filter("AmbaTi,Szumlanski,Tadimeti", "TI");
    Vector<string> expected = {"AmbaTi", "Tadimeti"};
    EXPECT(results == expected);

    results = filter("Zelenski,Szumlanski,Alonso", "nso");
    EXPECT_EQUAL(results, {"Alonso"});

    results = filter("Szumlanski,Coronado", "AaS");
    EXPECT_EQUAL(results, {});

    // what other tests could you add?
    results = filter("Zelenski,Szumlanski,Rodriguez Cardenas", "uez");
    EXPECT_EQUAL(results, {});
    // Since the input string is split by commas, "Rodriguez Cardenas" 
    // is processed as one string, which does not end on "uez".
}