#include <iostream>
#include "console.h"
using namespace std;

int main()
{
    int i = 10087;
    int *p = &i;

    int *q1 = i;
    int *q2 = &i;
    int *q3 = p;
    int *q4 = &p;
    int *q5 = *p;
    int *q6 = nullptr;


    // assign pointer to un-initialized variable
    int x;
    int *a = &x;  // is this okay?
    x = 50;
    /*
    Answer: Yes, this is totally fine. :) On line 2, we are only asking for the address of i. 
    Even though we have not yet stored a meaningful value in i by the time we reach that line, 
    i has been declared and therefore has an address that we can store in p.
    */
}