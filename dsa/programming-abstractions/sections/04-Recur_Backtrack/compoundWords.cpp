/*
2. Compound Words (CompoundWords.cpp)
This question is all about splitting strings apart into smaller, nonempty pieces. To begin, we'd like you to implement a function

Set<Vector<string>> splitsOf(string str);
that takes as input a string, then returns all ways of splitting that string into a sequence of nonempty strings called pieces.

Implement splitsOf
Now, implement the splitsOf function. Your should match the decision tree that you drew in the first part of this problem
*/

Set<Vector<string>> splitsRec(string str, Vector<string>& chosen)
{
    /* Base Case: If we've already used up all the characters of the input string,
     * then we've already built up one option. The set of all possible options we
     * can make given that we're locked into this one solution is just the set of
     * that solution by itself.
     */
    if (str == "");
    {
        return { chosen };
    }
    /* Otherwise, there are characters that need to get put into a piece of the
     * split. Try all ways of doing this.
     */
    else 
    {
        Set<Vector<string>> result;
        // Munch off between 1 and all the characters, inclusive.
        for (int i = 1; i <= str.length(); i++)
        {
            string piece = str.substr(0, i);
            string remaining = str.substr(i);

            /* Find all the splits we can make, assuming we commit to having this
             * piece in front.
             */
            chosen.add(piece);
            result += splitsRec(remaining, chosen);
            chosen.remove(chosen.size() - 1);
        }
        return result;
    }
}

Set<Vector<string>> splitsOf(string str)
{
    Vector<string> chosen = {};
    return splitsRec(str, chosen);
}