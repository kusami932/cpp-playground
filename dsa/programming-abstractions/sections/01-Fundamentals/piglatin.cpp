#include <iostream>
#include <string>
using namespace std;

/*
2. Pig-Latin (piglatin.cpp)
Topics: Strings, reference parameters, return types

Write two functions, pigLatinReturn and pigLatinReference, that accept a string and convert said string into 
its pig-Latin form. To convert a string into pig-Latin, you must follow these steps:

    1. Split the input string into 2 strings: a string of characters BEFORE the first vowel, 
       and a string of characters AFTER (and including) the first vowel.
    2. Append the first string (letters before the first vowel) to the second string.   
    3. Append the string "ay" to the resulting string.

Here are a few examples…
    sean -> eansay
    yasmine -> asmineyay
    tommy -> ommytay

You will need to write this routine in two ways: once as a function that returns the pig-Latin string 
to the caller, and once as a function that modifies the supplied parameter string and uses it to store 
the resulting pig-Latin string. These will be done in pigLatinReturn and pigLatinReference, respectively. 
You may assume that your input is always a one-word, all lowercase string with at least one vowel.

Here's a code example of how these functions differ…

-------------------------------------------------------------------------------------
string name = "yasmine";
string str1 = pigLatinReturn(name);
cout << str1 << endl; // prints "asmineyay"

pigLatinReference(name);
cout << name << endl; // prints "asmineyay"
-------------------------------------------------------------------------------------
Once you've written these functions, discuss with your section the benefits and drawbacks of these two approaches. 
Which do you feel is easier to write? Which do you think is more convenient for the caller? 
Do you think one is better style than the other?
*/

// Use const because VOWELS won't change -- no need to declare repeatedly
// in isVowel.
const string VOWELS = "aeiouy";

// Helper function, which I'd highly recommend writing!
bool isVowel(char ch)
{
    // A little kludgy, but the handout guarantees that
    // ch will ALWAYS be lower case :)
    // NOTE: For an assignment, you probably want a more robust isVowel.
    return VOWELS.find(ch) != string::npos;

}

string pigLatinReturn(string input)
{
    int strOneIndex = 0;
    for(int i = 0; i < input.length(); i++)
    {
        if(isVowel(input[i]))
        {
            strOneIndex = i;
            break;
        }
    }
    string strOne = input.substr(0, strOneIndex);
    string strTwo = input.substr(strOneIndex);
    return strTwo + strOne + "ay";
}

void pigLatinReference(string &input)
{
    int strOneIndex = 0;
    for(int i = 0; i < input.length(); i++)
    {
        if(isVowel(input[i]))
        {
            strOneIndex = i;
            break;
        }
    }
    string strOne = input.substr(0, strOneIndex);
    string strTwo = input.substr(strOneIndex);
    input = strTwo + strOne + "ay";
}

/*
Notice how similar these two approaches are – the only difference is how the result is handled at the very end. 
To address the discussion questions, although the pigLatinReference function is marginally more efficient because 
it doesn't need to make a copy of the input string, pigLatinReturn is probably more intuitive for both the caller 
and the writer: if the function's job is to somehow output some product, returning is the most explicit way to do 
so. In that way, a function that returns is also better style – it's makes the purpose of the function clearer 
to the reader.

If you wanted to combine the efficiency of pigLatinReference with the clarity of pigLatinReturn, I would recommend 
writing a function that takes in the input string by const reference, basically

string pigLatin(const string &input);

Although the const isn't explicitly necessary, it's nice to have because you never need to modify input. 
Moreover, you still get the efficiency gains from pass-by-reference while also writing very-understandable code.
*/