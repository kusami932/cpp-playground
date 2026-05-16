/*
2. Big O, Recursive Functions - Fibonacci
Topics: Big-O, code analysis, recursion

What is the Big O runtime of the following function, in terms of the variable n?
*/
int fibonnaci(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return fibonnaci(n - 1) + fibonnaci(n - 2);
}
/*
The time complexity for fibonacci is exponential, O(2^n). This is tricky! 
We can speculate that it's exponential because 1 recursive call makes 2 
others which in turn make 4 others and so on. In general this is how you 
can analyze Big O of recursive functions. First, find what the runtime 
is in 1 recursive call. Next, count how many recursive calls we make in 
terms of N.

In a single recursive call to fibonacci, we just make other calls to Fibonacci.
So outside of the recursive calls, we do constant time amount of work. Next,
let's analyze how many calls we make in terms of n. To do that, it helps to
try a few examples. Fibonacci(3) calls Fibonacci(2) and Fibonacci(1). 
Fibonacci(2) then calls Fibonacci(1) and Fibonacci(0). In total, for N = 3, 
we make 4 recursive calls. Let's try another example for Fibonacci(4). 
Fibonacci(4) calls Fibonacci(3) and Fibonacci(2). From the above, we know 
that Fibonacci(3) results in 4 recursive calls. Fibonacci(2) then calls 
Fibonacci(1) and Fibonacci(0). In total, we make 8 recursive calls.

Do you see some kind of pattern here? From our simple examples, it appears 
for each n, we make approximately 2^(n - 1) recursive calls (It's approximate 
because this formula doesn't fit for all n). We can write 2^(n - 1) as 
2^n / 2. Therefore we can write the Big O as O(1)[for amount of work in a 
single recursive call] * O(2^n / 2)[the total number of recursive calls we
make]. Remember that in Big O, we discard constant multipliers, so the Big O
for fibonacci simplifies to O(2^n).

----------------------------------------

Interesting note (beyond the scope of what we cover in this class):

Note that if fibonacci(n) called fibonacci(n-1) twice, the number of calls
would be approximately 2^(n-1). However, this formula is not super precise
for Fibonacci -- and is actually an overestimate of the runtime -- because
the function is making two different function calls: one to fibonacci(n-1)
and one to fibonacci(n-2). If we diagram out these calls with a decision
tree, rather than seeing a nice, symmetrical tree with approximately
2^(n-1) calls, we see a lopsided tree in which the right-hand side is
smaller than the left-hand side.

A more precise indication of the runtime is actually O(Φ^n) ≈ O(1.618^n).
A careful analysis of the runtime is beyond the scope of this class but
can be found if you google "Fibonacci runtime analysis," if you're curious!
*/