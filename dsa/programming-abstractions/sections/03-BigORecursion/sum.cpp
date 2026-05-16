/*
3. Win some, lose sum (sum.cpp)
Topics: recursive backtracking

Write a recursive function named canMakeSum that takes a reference to a Vector<int> and an int target value 
and returns true if it is possible to have some selection of values from the Vector that sum to the target value. 
In particular, you should be implementing a function with the following declaration

                                bool canMakeSum(Vector<int>& values, int target)

For example, let's say that we executed the following code

        Vector<int> nums = {1,1,2,3,5};
        canMakeSum(nums, 9)

    We should expect that the call to canMakeSum should return true. 
    Given the values specified in nums, we can select 1, 3, and 5 such that 5 + 3 + 1 = 9.

However, let's say that we executed the following code instead

        Vector<int> nums = {1,4,5,6};
        canMakeSum(nums, 8);

    We should expect that the call to canMakeSum in this case should return false, since there is no possible 
    combination of values from the vector that sum up to the target value of 8.
*/

// SOLUTION 1
bool canMakeSumHelper(Vector<int>& v, int target, int sumSoFar)
{
    if(v.isEmpty())
    {
        return sumSoFar == target;
    }

    /* Here we choose the last element in the vector.
     * We could have chosen any element, but the last
     * is the easiest and fastest method.
     */
    int choice = v[v.size() - 1];
    v.remove(v.size() - 1);

    bool with = canMakeSumHelper(v, target, sumSoFar + choice);
    bool without = canMakeSumHelper(v, target, sumSoFar);

    // And then we unchoose, by adding this back!
    v.add(choice);

    return with || without;
}

bool canMakeSum(Vector<int>& v, int target)
{
    return canMakeSumHelper(v, target, 0);
}

// SOLUTION 2
/*
 * This solution is similar to the one above, except it uses 
 * an additional index parameter in a vector to make the choices, 
 * instead of removing from the vector like solution 1 did.
 */
bool canMakeSumHelper(Vector<int>& v, int target, int sumSoFar, int index)
{
    if (index >= v.size())
    {
        return sumSoFar == target;
    }

    // This is our choice now. Remember we can choose any element
    // in the vector, so we choose the element at 'index'
    int choice = v[index];

    bool with = canMakeSumHelper(v, target, sumSoFar + choice, index + 1);
    bool without = canMakeSumHelper(v, target, sumSoFar, index + 1);

    // We don't have to add back, because we never removed!
    return with || without;
}

bool canMakeSum(Vector<int>& v, int target)
{
    return canMakeSumHelper(v, target, 0, 0);
}