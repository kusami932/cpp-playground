/*
Insertion Sort

Overview: Each pass takes the first element from the unsorted portion of the vector and 
"inserts" it into the sorted portion by dragging it down until it either encounters a 
smaller value smaller to its left or reaches the beginning of the vector.


Worst-case runtime: O(n2). The first pass could move an element down one position, 
the second could move an element down two positions, the third could move an element 
down three positions, and so on. It's that Gauss sum once again. The last pass of 
insertion sort will only move an element down by (n - 1) positions at most, so the 
sum is slightly modified, but the big-oh result is the same: 
1 + 2 + ... + (n - 1) = (n - 1) * n / 2, which is O(n2).

Best-case runtime: O(n). This is a vast improvement over selection sort's best-case runtime! 
Insertion sort encounters this runtime if it receives an already-sorted vector. In that case, 
each pass stops after a single comparison without having to do any swaps.

Operations: Heavy on swaps, potentially light on comparisons. It picks up an element at the 
beginning of each pass and drags it down through the vector, performing a swap at each index 
it passes. (*swap!* *swap!* *swap!* *swap!*) A pass of insertion sort stops as soon as it 
encounters an element smaller than the one it's dragging down, though, meaning that it could 
potentially stop each pass early and end up doing fewer comparisons than selection sort. Neat.
*/

void insertionSort(Vector<int>& v)
{
    for (int start = 1; start < v.size(); start++)
    {
        int peach = v[start];
        int gap;

        for (gap = start; gap > 0 && peach < v[gap - 1]; gap--)
        {
            v[gap] = v[gap - 1];
        }

        v[gap] = peach;
    }
}