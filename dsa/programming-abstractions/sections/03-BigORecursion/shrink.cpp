/*
4. Shrink Words (shrink.cpp)
Topics: recursive backtracking

Write a recursive function named shrinkWord that takes a string word and a Lexicon of words, and shrinks the word 
to the smallest possible word that can be found in the Lexicon. You can think of a the lexicon as a set of all 
words in the English dictionary. Checkout the documentation for Lexicon to learn more.

                                string shrinkWord(string input, Lexicon& lex) 

The function is best described by this example below:

Given a string "starter", we can shrink it to "a" through these: 
starter -> starer (by removing the second t) -> stare (by removing the second r) 
-> tare (by removing s) -> are (by removing t) -> ae (by removing r) -> a (by removing e). 
Hence, we'll return "a". Note that all the intermediate words are english words.

As another example, given string "baker", we can shrink it to "bake" through these: 
baker -> bake (remove r). We can't shrink any further because if we remove a any 
another letter, we can't find the resulting word in the lexicon. Hence, we'll return "bake".

Finally, for "fishpond", we can't make a single transformation. So we'll return "fishpond", unchanged.
*/

string shrinkWord(string input, Lexicon& lex)
{
    // We can't further shrink an empty word.
    // Also, if current word we have now is not
    // an English word(i.e. it isn't contained in 
    // the lexicon), that's also invalid(from the problem
    // description.)
    if (input.isEmpty() || !lex.contains(input))
    {
        return "";
    }

    string shortestWord = input;
    for (size_t i = 0; i < input.length(); i++)
    {
        // Remove the letter at index i and recurse!
        string subWord = input.substr(0, i) + input.substr(i + 1);
        string result = shrinkWord(subWord, lex);

        // Compare the words we've generated so far to 
        // our shortestWord. If our new word is smaller, 
        // we have to change our shortestWord!
        // We need a special check for the empty string
        // because our base case returns "" for invalid inputs.
        if(!result.empty() && result.length() < shortestWord.length())
        {
            shortestWord = result;
        }
    }

    return shortestWord;
}