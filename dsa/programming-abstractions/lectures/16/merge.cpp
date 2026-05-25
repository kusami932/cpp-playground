/*
MergeSort Runtime Analysis

1. The runtime for the work being performed at each individual layer of the diagram is O(n). 
    At the top layer, we have an O(n) merge operation to merge the left and right halves of the array. 
    At the bottom layer, we have n base cases, each of which take O(1) time to execute -- so, 
    a total runtime of O(n) for all of the base cases in that btotom layer. In the layers between, 
    the runtimes of the repeated but smaller merge operations add up to O(n) for each layer.

2. The number of layers in the diagram is approximately log2(n) + 1, which is O(log n).

3. Multiplying the number of layers by the runtime associated with each layer gives us our overall runtime of O(n log n).

*/

void mergeSort(Vector<int>& v, int lo, int hi)
{
    // Base case: one (or fewer) elements in this portion of the vector.
    if (lo >= hi)
    {
        return;
    }

    int mid = lo + (hi - lo) / 2;

    // Sort left and right halves recursively.
    mergeSort(v, lo, mid);
    mergeSort(v, mid + 1, hi);

    // Merge results back together in auxiliary vector.
    Vector<int> aux;

    int i = lo;
    int j = mid + 1;

    while (i <= mid || j <= hi)
    {
        if (i > mid)
        {
            // If i is invalid, j must be valid.
            aux.add(v[j]);
            j++;
        }
        else if (j > hi)
        {
            // If j is invalid, i must be valid.
            aux.add(v[i]);
            i++;
        }
        else if (v[i] < v[j])
        {
            // If both i and j are valid, we check whether v[i] < v[j] or not.
            // We want the smaller value.
            aux.add(v[i]);
            i++;
        }
        else
        {
            // This is the case where i and j are valid, and v[j] <= v[i].
            aux.add(v[j]);
            j++;
        }
    }

    // Copy everything from the auxiliary vector back into the original.
    for (i = lo; i <= hi; i++)
    {
        v[i] = aux[i - lo];
    }
}

/*

Downside of MergeSort

    1. It takes up extra space for the auxiliary vector used when merging the two halves back together. 
    Tight on space? The recursive calls to merge sort also take up space in the call stack.

    2. Speaking of the call stack, all the recursive calls we make to merge sort take time! We have to put 
    a new call on our program stack, instantiate local variables, and then almost immediately to all of 
    that over again to make two more recursive calls. The overhead involved with those recursive calls 
    is significant enough that for small(ish) vectors, selection and insertion sort can actually 
    end up out-performing merge sort.

    3. As mentioned earlier, the ease of coding up and debugging an algorithm can also play a role in 
    whether it's worthwhile to use it for a particular application. Sometimes when we're trying to 
    rapidly prototype software or run a quick one-off experiment, we just need a quick and dirty solution 
    to some sub-problem we've encountered, and it's a better use of our time to implement a slow but 
    straightforward and easy-to-debug algorithm than one that is more complex, more difficult to implement, 
    and more likely to have bugs in obscure corner cases that we don't think to test.
*/