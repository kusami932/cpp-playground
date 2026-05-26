#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdlib.h>
#include <LinkedListStack.h>

typedef enum
{
    LEFT_PAREN = '(', RIGHT_PAREN =')',
    PLUS = '+', MINUS = '-',
    MULT = '*', DIV = '/',
    SPACE = ' ', OPERAND
} SYMBOL;


int IsNumber(char Cipher);
unsigned int GetNextToken(char *Expression, char *Token, int *TYPE);
int IsPrior(char Operator1, char Operator2);
void GetPostFix(char *Infix, char *Postfix);
double Calculate(char *Postfix);

#endif 