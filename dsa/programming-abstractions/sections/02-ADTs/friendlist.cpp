#include <iostream>
#include "console.h"
#include "vector.h"
#include "map.h"
#include "set.h"
using namespace std;

/*
2. Friends (friendlist.cpp)
Topic: Maps, Sets

a. Building the friendList
Write a function named friendList that takes in a file name, reads friend relationships from the file, 
and writes them to a Map. friendList should return the populated Map. Friendships are bi-directional, 
so if Abby is friends with Barney, Barney is friends with Abby. The file contains one friend relationship 
per line, with names separated by a single space. You do not have to worry about malformed entries.

If an input file named buddies.txt looked like this:

Barney Abby
Abby Clyde

Then the call of friendList("buddies.txt") should return a resulting map that looks like this:
    {"Abby":{"Barney", "Clyde"}, "Barney":{"Abby"}, "Clyde":{"Abby"}}

Here is the function prototype you should implement:
    Map<string, Set<string> > friendList(String filename)
*/

Map<string, Set<string> > friendList(string filename)
{
    ifstream in;
    Vector<string> lines;

    if(openFile(in, filename))
    {
        lines = readLines(in);
    }

    Map<string, Set<string>> friends;
    for (string line : lines)
    {
        Vector<string> people = stringSplit(line, " ");
        string s1 = people[0];
        string s2 = people[2];
        friends[s1] += s2;
        friends[s2] += s1;
    }

    return friends;

}

/*
b. Finding common friends
Write a function named mutualFriends that takes in the friendList above, and two strings representing two friends, 
and returns the names of the mutual friends they have in common. For example, if the friendList is 
{"Abby":{"Barney", "Clyde"}, "Barney":{"Abby"}, "Clyde":{"Abby"}} and friend1 is Barney and friend2 is Clyde, 
then your function should return {"Abby"}
*/

Set<string> mutualFriends(Map<string, Set<string> >& friendList,
                string friend1, string friend2)
{
    return friendList[friend1] * friendList[friend2];
}