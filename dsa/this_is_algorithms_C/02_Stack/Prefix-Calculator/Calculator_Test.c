#include <stdio.h>
#include <string.h>
#include "Calculator.h"

int main(void)
{
    char Infix[100];
    char Postfix[100];

    double Result = 0.0;

    memset(Infix, 0, sizeof(Infix));
    memset(Postfix, 0, sizeof(Postfix));

    printf("Enter Infix Expression:");
    scanf("%s", Infix);

    GetPostFix(Infix, Postfix);

    printf("Infix: %s\nPostfix:%s\n",
            Infix, Postfix);
    
    Result = Calculate(Postfix);

    printf("Calculation Result: %f\n", Result);

    return 0;
}