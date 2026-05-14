#include <iostream>
#include "console.h"
using namespace std;

int main()
{
    int *p = nullptr;
    *p = 50; // dereferencing a null pointer will give you a segmentation fault

    int i = 0;


    // The star and address operators are processed from right to left in C++. 
    // So, that *&i line first gets the address of i, and then we dereference it 
    // with the star operator (i.e., we go to that address). 
    // That takes us to the variable i, of course, and we put the value 55 there.
    *&i = 55;

    cout << i << endl;

    *&*&*&*&*&*&*&*&*&*&*&*&i = 55; // this is possible
    ***&&&i = 55 // this does not work. Once we've taken the address of a variable, we can't take the address again
    
    return 0;

}