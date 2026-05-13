/*
Recursive Problems
	Factorial
	Palindromes
	Coin Flip / Dice Roll
	Binary Search
	Permutations
	Fractals
	Subsets


Fundamental Backtracking Paradigm: "Choose, Explore, Unchoose"

    1. CHOOSE one of those moves and adjusting the board accordingly
    2. pass the newly modified board to the function recursively to EXPLORE whether that move might lead to a solution
    3. If not, that call eventually returns, UNCHOOSE, and move back into position
        => simply put, returning to the previous recursive call.

    problem representation (a string, a grid, etc.) is passed to our recursive calls by value, 
    and so returning to a previous call gets us back to a previous (unmodified) copy of that problem representation.

The Basic Anatomy of a Recursive Backtracking Algorithm (A Bit More Detail)

	1. BASE CASE: We often implement backtracking using recursion. Our base case generally checks whether we've 
	   succeeded at finding a solution to the problem. If so, it might perform some action and/or it might return some value.
	   Either way, the base case gives our algorithm the ability to return to the previous function call.
	
	2. (Optional) CHECK FOR DUPLICATE STATES: explicitly check whether we're in a state that we've already seen. If so, 
	   return from this function call to avoid getting stuck in an infinite loop where we constantly bounce back and 
	   forth between states we've already seen. 

	   Instead of checking for duplicate states explicitly, just set up the for-loop that makes our recursive calls 
	   in a way that ensures only new, unique states are passed to the function with each recursive call.
	   Hence, this step that checks for duplicate states is not always required

	3. GENERATE POSSIBLE MOVES: generally implemented as a loop that changes the parameters passed to this function 
	   in some way in order to generate all possible states we could reach from our current state.

	   3.1 Check Validity of Move (CHECK VALIDITY)
		   In this loop, if we're attempting to make some sort of move, first check whether it's valid.
		   If so, skip to the next iteration of this loop without making a recursive call.

	   3.2 Change State (MAKE THE MOVE => CHANGE PARAMETERS OF FUNCTION)
		   Change the parameters we're passing to our backtracking algorithm to reflect the new state 
		   we'll be in after we make this move. This is the "choose" phase of recursive backtracking.

	   3.3 Perform Recursive Descent (GO DOWN THE RECURSION => REPEAT 3.1 & 3.2)
	       We make our recursive call to the backtracking algorithm, passing it the new state we're in 
		   with this move. This is the "explore" phase of recursive backtracking.

	   3.4 (Optional) Process the Return Value of the Recursive Call (CHECK & SAVE RETURN VALUE)
	        When our recursive function call returns, we might want to capture its return value. It might 
			be returning a boolean indicating whether it found a path to the solution we want. If it did, 
			we might be able to stop making recursive calls.

			Alternatively, if we're looking for every possible solution to this problem, we might continue 
			searching even if this recursive call already found one solution.

       3.5 (Optional) Undo State Change
		    If we return from a recursive call, we might need to undo the state change we did in step 3.2 above 
			before we can go on to the next iteration of this move-generating loop. Sometimes, we were creating 
			new subsets with each recursive call rather than passing by reference. 
			This is the "unchoose" phase of recursive backtracking.
*/