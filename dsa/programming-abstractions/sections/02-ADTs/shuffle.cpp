/*
5. Random Shuffling (shuffle.cpp)
How might the computer shuffle a deck of cards? This problem is a bit more complex than it might seem, and while it's 
easy to come up with algorithms that randomize the order of the cards, only a few algorithms will do so in a way that 
ends up generating a uniformly-random reordering of the cards.

One simple algorithm for shuffling a deck of cards is based on the following idea:

Choose a random card from the deck and remove it.
Shuffle the rest of the deck.
Place the randomly-chosen card on top of the deck. Assuming that we choose the card that we put on top 
uniformly at random from the deck, this ends up producing a random shuffle of the deck.

Write a function string randomShuffle(string input) that accepts as input a string, then returns a random 
permutation of the characters of the string using the above algorithm. Your algorithm should be recursive 
and not use any loops (for, while, etc.).

The header file "random.h" includes a function int randomInteger(int low, int high);
that takes as input a pair of integers low and high, then returns an integer greater than or 
equal to low and less than or equal to high. Feel free to use that here.

Interesting note: This shuffling algorithm is a variant of the Fisher-Yates Shuffle. 
*/

string randomShuffle(string input)
{
    /* Base case: There is only one possible permutation of a string
    * with no characters in it.
    */
    if (input.isEmpty())
    {
        return input;
    }
    else 
    {
        /* Choose a random index in the string. */
        int i = randomInteger(0, input.length() - 1);
        /* shuffle the rest of the string, add the removed character on the front
        * the string.
        */
        return input[i] + randomShuffle(input.substr(0, i) + input.substr(i + 1));

        /*
        This function is based on the recursive observation that there is only one possible random shuffle 
        of the empty string (namely, itself), and then using the algorithm specified in the handout for the recursive step.
        */
    }

}