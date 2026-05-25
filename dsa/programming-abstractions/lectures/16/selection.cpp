/*
Selection Sort
Overview: Each pass "selects" the smallest elements and then swaps it down 
          into the first position of the unsorted portion of the vector.

Worst-case runtime: O(n2). The first pass examines n elements, then performs a single swap, 
the next examines (n - 1) elements before performing a single swap, and so on. The number 
of comparisons is represented with the Gauss sum we keep seeing: 1 + 2 + ... + n = n * (n + 1) / 2, which is O(n2).

Best-case runtime: O(n2). Every call to selection sort follows the pattern described above for the worst-case runtime.

Operations: Heavy on comparisons, light on swaps. It spends a lot of time comparing elements in each pass before 
settling on which one to swap into the next target position.
*/

void swap(Vector<int>& v, int i, int j);

void selectionSort(Vector<int>& v)
{
    for (int start = 0; start < v.size(); start++)
    {
        int indexOfMin = start;

        for (int j = start + 1; j < v.size(); j++)
        {
            if (v[j] < v[indexOfMin])
            {
                indexOfMin = j;
            }
        }

        swap(v, start, indexOfMin);
    }
}

void swap(Vector<int>& v, int i, int j)
{
    int temp = v[i];
    v[i] = v[j];
    v[j] = v[i];
}

