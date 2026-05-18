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

/*
iii. Implement isCompoundWord
Now that you've gotten a warmup in, let's take aim at a related question. A compound word is an English word like 
"doorbell" or "heretofore" that can be split apart into multiple English words ("doorbell" becomes "door" and "bell;" 
"heretofore" becomes "here," "to," and "fore.") Your task is to write a function

                                bool isCompoundWord(string word, Lexicon& english);

that takes as input a word, then returns whether it's a compound word.
You will likely want to build on the work you've done earlier in this problem. A few things have changed, though. 
First, you have to split the word apart into multiple pieces. Second, each piece must itself be a word. There are 
many ways to account for this; explore and see what you find!
*/

/*
SOLUTION

Perhaps the trickiest bit here is handling the fact that we have to split into two or more words. There are many ways 
to do this. Our strategy will be the following. Our recursive logic will completely ignore this requirement, and will 
be perfectly content to split a string apart into a single word if it feels like it. To force the function to always 
require at least one word to be munched off, we'll have our wrapper function do an initial splitting step in which it 
isn't permitted to munch all the characters. Here's what that looks like:
*/

// Can the given input string be split apart into zero or more English words?
bool isCompoundRec(string str, Lexicon& english)
{
    /* Base Case: If the string is empty, we can write it as zero words
     * all glued together.
     */
    if (str == "")
    {
        return true;
    }
    /* Recursive Case: Split off some number of characters from the front that
     * form a word, then recursively see if what's left is a compound word.
     */
    else 
    {
        // Grab between one and all of the characters from the front.
        for (int i = 1; i <= str.length(); i++)
        {
            /* This is a good split if what we've grabbed is a word and the
             * remainder is an English word.
             */
            if (english.contains(str.substr(0, i)) && 
                isCompoundRec(str.substr(i), english)) 
            {
                    return true;
            }
        }
        return false;
    }
}

bool isCompoundWord(string word, Lexicon& english)
{
    // If we aren't a word, then we aren't a compound word.
    if (!english.contains(word)) return false;

    /* Otherwise, try pulling off a word from the front and seeing if what's
     * left can be made from gluing one or more words together.
     */
    for (int i = 1; i < word.length(); i++)
    {
        if (english.contains(word.substr(0, i)) &&
            isCompoundRec(word.substr(i), english))
        {
            return true;
        }
    }
    // Nope, it's not a compound word, since we tried every option.
    return false;
}