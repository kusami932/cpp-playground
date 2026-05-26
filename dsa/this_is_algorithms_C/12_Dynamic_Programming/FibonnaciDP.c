#include <stdio.h>
#include <stdlib.h>

typedef unsigned long ULONG;

ULONG Fibonnaci(int N)
{
    int i;
    ULONG Result;
    ULONG *FibonnaciTable;

    if (N == 0 || N == 1) return N;

    FibonnaciTable = (ULONG*)malloc(sizeof(ULONG) * (N + 1));

    FibonnaciTable[0] = 0;
    FibonnaciTable[1] = 1;

    for (i = 2; i <= N; i++)
    {
        FibonnaciTable[i] = FibonnaciTable[i - 1] + FibonnaciTable[i - 2];
    }

    Result = FibonnaciTable[N];

    free(FibonnaciTable);

    return Result;
}

int main(void)
{
    int N = 46;
    ULONG Result = Fibonnaci(N);

    printf("Fibonacci(%d) = %lu\n", N, Result);

    return 0;
}

