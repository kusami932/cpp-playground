/*
1. Big O, basics
Topics: Big-O, code analysis

What is the Big O runtime of the following functions, in terms of the variable N?
*/

// Code Snippet A
int sum = 0;
for (int i = 1; i <= N + 2; i++) {
    sum++;
}
for (int j = 1; j <= N * 2; j++) {
    sum++;
}
/*
Code Snippet A has a runtime complexity of O(N): The first for loop runs in O(N),
the second also runs in O(N). This makes O(N) + O(N) = O(2N) = O(N), because we 
throw away constants
*/

// Code Snippet B
int sum = 0;
for (int i = 1; i <= N - 5; i++) {
    for (int j = 1; j <= N - 5; j += 2) {
        sum++;
    }
}
/*
Code Snippet B has a runtime complexity of O(N^2): The code in the innermost for
loop is just a sum so that runs in constant time, O(1). The j for loop iterates 
a total of (N - 5)/2 times which is equal to O(N) since we ignore constants and 
scalars. The outermost for loop also runs in O(N). In total we get 
O(1) * O(N) * O(N) = O(N^2)
*/

// Code Snippet C
int sum = 0;
for (int i = 1; i <= 10000000; i++) {
    sum ++;
}
/*
Code Snippet C has a runtime complexity of O(1): This loop doesn't depend on N 
at all, and loops up to a constant 10000000. Therefore runtime is O(1)
*/

// Code Snippet D
int sum = 0;
for (int i = 0; i < 1000000; i++) {
    for (int j = 1; j <= i; j++) {
        sum += N;
    }
    for (int j = 1; j <= i; j++) {
        sum += N;
    }
    for (int j = 1; j <= i; j++) {
        sum += N;
    }
}
/*
Code Snippet D has a runtime complexity of O(1): This is also constant time. The 
outermost for loop loops up until 1000000, which is constant. The 3 inner loops 
all loop until i, which will be always less than 1000000. Therefore total 
runtime is O(1)
*/

// Code Snippet E
int sum = 0;
for (int i = 1; i <= N; i *= 2) {
    sum ++;
}
/*
Code Snippet E has a runtime complexity of O(logN): This runs in logarithmic 
time, O(logN). You can see this by counting the number of times it takes i to get to
n. i starts at 1, then jumps to 2, then 4, ..., n. It takes logN steps to get
to N. This is similar to logarithmic runtime analysis in class that starts from 
n and drops down to 1.
*/