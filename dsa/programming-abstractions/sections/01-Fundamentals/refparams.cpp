#include <iostream>
#include <string>
using namespace std;

/*
1. References Available Upon Request
    Topics: Reference parameters, range-based for loops

Reference parameters are an important part of C++ programming, but can take some getting 
used to if you’re not familiar with them. Trace through the following code. What does it print?

*/

void maui(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        s[i] += 2;
    }
}

void sina(string& s)
{
    for (int i = 0; i < s.length(); i++)
    {
        s[i] += 2;
    }
}

void moana(string& s)
{
    for (char ch : s)
    {
        ch += 2;
    }
}

void heihei(string& s)
{
    for (char& ch : s)
    {
        ch += 2;
    }
}

string teFiti(string& s)
{
    string result;
    for (char& ch : s)
    {
        result += (ch + 2);
    }

    return result;
}

int main()
{
    string s = "umm";

    maui(s);
    cout << s << endl;

    sina(s);
    cout << s << endl;

    moana(s);
    cout << s << endl;

    heihei(s);
    cout << s << endl;

    teFiti(s);
    cout << s << endl;

    return 0;
}

/*
Solution

Here’s the output from the program:
    umm
    woo
    woo
    yqq
    yqq
Here’s a breakdown of where this comes from:

1. The maui function takes its argument by value, so it’s making changes to a copy of the string, 
   not the original string itself. That means that the values are unchanged back in main.

2. The sina function, on the other hand, takes its argument by reference and loops through the 
   string directly, so the original string is modified back in main.

3. The moana function uses a range-based for loop to access the elements of the string. Even though 
   the string is passed by reference, the loop makes a copy of each character of the string, 
   so the changes made in the loop only change the temporary copies of the characters and 
   not the characters of the string. That makes the string remain unchanged back in main.

4. heihei, on the other hand, uses char& as its type for the range-based for loop, so in a sense 
   it’s really iterating over the elements of the underlying string. Therefore, its changes stick.

5. The teFiti function creates and returns a new string with a bunch of updated values, but the 
   return value isn’t captured back in main.
*/