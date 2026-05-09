#include <iostream>
#include "console.h"
using namespace std;
/*
Recursive Permutation Generation

A permutation is just a re-ordering of elements. The approach we saw today generated a soFar string 
that kept track of the permutation we had built so far on our recursive journey through the function. 
It also maintained a rest string with the characters that had yet to be included in soFar at each step.
*/
void permute(string soFar, string rest)
{
    if (rest == "")
    {
        cout << soFar << endl;
        return;
    }

    for (int i = 0; i < rest.length(); i++)
    {
        string newRest = rest.substr(0, i) + rest.substr(i + 1);
        permute(soFar + rest[i], newRest);
    }
}

void permute(string s)
{
    permute("", s);
}

int main()
{
    permute("act");
    return 0;
}