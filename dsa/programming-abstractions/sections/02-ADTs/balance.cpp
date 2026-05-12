#include <iostream>
#include "console.h"
#include "stack.h"
/*
4. Check Balance (balance.cpp)
Topic: Stacks

Write a function named checkBalance that accepts a string of source code and uses a Stack to check whether the 
braces/parentheses are balanced. Every ( or { must be closed by a } or ) in the opposite order. Return the index 
at which an imbalance occurs, or -1 if the string is balanced. If any ( or { are never closed, return the string's length.

Here are some example calls:

//   index    0123456789012345678901234567
checkBalance("if (a(4) > 9) { foo(a(2)); }") 
// returns -1 (balanced)

//   index    01234567890123456789012345678901
checkBalance("for (i=0;i<a;(3};i++) { foo{); )")
// returns 15 because } is out of order

//   index    0123456789012345678901234
checkBalance("while (true) foo(); }{ ()")
// returns 20 because } doesn't match any {

//   index    01234567
checkBalance("if (x) {")
// returns 8 because { is never closed
*/

int checkBalance(string code)
{
    Stack<char> parens;
    for (int i = 0; i < code.length(); i++)
    {
        char c = code[i];
        if (c == '(' || c == '{')
        {
            parens.push(c);
        }
        else if (c == ')' || c == '}')
        {
            if(parens.isEmpty())
            {
                return i;
            }
            char top = parens.pop();
            if ((top == '(' && c != ')') || (top == '{' && c != '}'))
            {
                return i;
            }
        }
    }

    if (parens.isEmpty())
    {
        return -1;
    }

    return code.length();
}