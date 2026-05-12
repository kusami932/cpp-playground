#include <iostream>
#include <string>
using namespace std;

/*
4. Returning and printing
Topics: Function call and return, return types

Below is a series of five printLyrics_v# functions, each of which has a blank 
where the return type should be. For each function, determine

    what the return type of the function should be,
    what value, if any, is returned, and
    what output, if any, will be produced if that function is called.
    Is it appropriate for each of these functions to be named printLyrics? Why or why not?

*/

/*
The function printLyrics_v1 doesn't return anything - it just sends information to the console. 
As a result, its return type should be void. Since this function prints out the string 
"Havana ooh na na.", the name “printLyrics” is appropriate!
*/
void printLyrics_v1() {
    cout << "Havana ooh na na" << endl;
}


/*
The functions printLyrics_v2 and printLyrics_v3 both return strings, since C++ treats anything 
in double-quotes as a string. Neither of these functions actually prints the string though, 
which means that the name “printLyrics” is inappropriate for both functions.
*/

string printLyrics_v2() {
    return "Havana ooh na na";
}

string printLyrics_v3() {
    return "H";
}

/*
The function printLyrics_v4 returns a char, since C++ treats anything in single-quotes as a character. 
This function also does not print anything, which means that the name “printLyrics” is inappropriate.
*/
char printLyrics_v4() {
    return 'H';
}

/*
Finally, the function printLyrics_v5 doesn't return anything, which means its return type is void. 
This function does print out a char. The name “printLyrics” is still inappropriate because only 
a single character is being printed from this function, not an entire line of lyrics.
*/

void printLyrics_v5() {
    cout << 'H' << endl;
}
