⁡⁣⁢⁣/*
Problem 1: Intermediate OOP implementation

Create a ‘Set’ ADT, which will implement the basic operations of Set concept 
in mathematics. The data members and operations needed for this ADT are given below.

Data Members:
    int * data
    int noOfElements
    int capacity

1. Set (int cap = 0); 
Default parameterized constructor. Sets ‘cap’ to ‘capacity’ and initializes rest of the 
data members accordingly. If user sends any invalid value then sets the cap to default value.

2. Set(const Set & ref); 
overloaded copy constructor to implement deep copy.

3. ~Set()
Free the dynamically allocated memory.

4. void insert (int element); 
Stores the element in the Set. Remember! Set is a collection of distinct elements. 
If the array is full, then resize the capacity of Set by double.

5. void remove (int element); 
remove the element from the Set. If the noOfElements in the Set are equal to or less than 
50% of capacity then shrink the Set by 25% i.e., if the capacity was 12 and noOfElements 
are less than equals to 6 then the new Set should be of the capacity equals to 9.

6. int getCardinality() const; returns the number of elements in the set.

7. Set calcUnion (const Set & s2 ) const; returns a new Set object which 
contains the union of ‘s2’ set and calling object set.

8. Set calcSymmetricDifference (const Set & s2); 
returns a new Set object which contains the symmetric Difference of ‘s2’ set 
and calling object set. Where symmetric difference is: AΔB= AB−A∩B

9. Set calcDifference (const Set & s2 ) const; 
returns a new Set object which contains the intersection of ‘s2’ set and calling object set.

10. int isMember (int val ) const; 
returns 1 if ‘val’ is member of the set otherwise return 0.

11. int isSubSet (const Set & s2) const; 
returns 1 if s2 is proper subset of calling object set, return 2 if improper 
subset otherwise returns 0.

12. void reSize (int newcapacity); 
resize the set to new capacity. Make sure that elements in old set should be 
preserved in the new set if possible.

13. void update(int prVal, int curVal);
This function should replace the previous value(prVal) with current value (curVal). 
Make sure the property of set should not be violated (distinct elements). If the prVal is 
not present in the array, then display a message “Target value not found”. In-case of 
successful modification then display a message “Record update successfully”. If prVal 
is present in the set but curVal is also already available, then display a message 
“Violation set property. Can’t Modify the data”.

14. void show() const; 
This function should display the contents of Set for calling object.
*/⁡

/*
Task Description
This C++ program defines a 'Set' class that represents a set 
of integers and provides various set operations.

  1. The 'Set' class has private data members 'data', 'noOfElements', and 'capacity' to 
     store the set elements, the number of elements in the set, and the 
     apacity of the set, respectively.

  2. The class has constructors to create a set object and initialize its properties.
     The destructor is provided to free the dynamically allocated memory for the set.

  3. The 'insert' function inserts a new element into the set.

  4. The 'remove' function removes an element from the set.

  5. The 'getCardinality' function returns the number of elements in the set.

  6. The 'calcUnion', 'calcSymmetricDifference', and 'calcDifference' functions perform set 
     operations Union, Symmetric Difference, and Difference, respectively, and return a 
     new set object with the result.

  7. The 'isMember' function checks if an element is present in the set.

  8. The 'isSubSet' function checks if the current set is a proper or improper subset of another set.

  9. The 'reSize' function resizes the set to the specified new capacity.

  10. The 'update' function updates the value of an element in the set with a new value.

  11. The 'show' function displays the elements of the set.

  Note: The program demonstrates the implementation of a set using dynamic memory allocation.
  It showcases various set operations and how elements can be inserted, removed, and updated in the set.
*/

#include <iostream>
using namespace std;

class Set {
    private:
        int* data;
        int numOfElements;
        int capacity;
    
    public:
        Set(int cap = 0);
        Set(const Set& ref); // overloaded copy constructor to implement deep copy.
        ~Set(); // free the dynamically allocated memory
        void insert(int element);
        void remove(int element);
        int getCardinality() const;
        Set calcUnion(const Set& s2) const;
        Set calcSymmetricDifference(const Set& s2) const;
        Set calcDifference(const Set& s2) const;
        int isMember(int val) const;
        int isSubSet(const Set& s2) const;
        void resize (int newCapacity);
        void update(int prVal, int curVal);
        void show() const;
};

Set::Set(int cap) {
    if (cap < 0) cap = 0; // Ensure capacity is not negative

    this->data = new int[cap];
    this->capacity = cap;
    this->numOfElements = 0;
}

// overloaded copy constructor to implement deep copy
Set::Set(const Set& ref) {
    numOfElements = ref.numOfElements;
    data = new int[ref.capacity];
    for (int i = 0; i < numOfElements; i++) {
        data[i] = ref.data[i];
    }
}

Set::~Set() {
    delete[] data;
}

void Set::insert(int element) {
    int* ptr = new int[this->numOfElements + 1];
    for (int i = 0; i < numOfElements; i++) {
        ptr[i] = data[i];
    }
    ptr[numOfElements] = element;
    delete[] data;
    data = ptr;
    numOfElements++;
}

void Set::remove(int element) {
    int* ptr = new int[this->numOfElements - 1];
    int j = 0;
    for (int i = 0; i < numOfElements; i++) {
        if (data[i] != element) ptr[j] = data[i];
        j++;
    }
    delete[] data;
    data = ptr;
    numOfElements--;

    // Check if the Set needs to be resized
    if (numOfElements <= capacity / 2) {
        resize(capacity - capacity / 4);
    }
}

int Set::getCardinality() const {
    return numOfElements;
}

Set Set::calcUnion(const Set& s2) const {
    Set result(this->capacity + s2.capacity)

    for (int i = 0; i < this->numOfElements; i++) {
        result.insert(this->data[i])
    }

    for (int i = 0; i < s2.numOfElements; i++) {
        if (!this->isMember(s2.data[i])) result.insert(s2.data[i]);
    }

    return result;
}

Set Set::calcSymmetricDifference(const Set& s2) const {
    Set result(this->capacity + s2.capacity);

    for (int i = 0; i < this->noOfElements; i++) {
        if (!s2.isMember(this->data[i])) {
            result.insert(this->data[i]);
        }
    }
    for (int i = 0; i < s2.noOfElements; i++) {
        if (!this->isMember(s2.data[i])) {
            result.insert(s2.data[i]);
        }
    }
    return result;
}

Set Set::calcDifference(const Set& s2) const {
    Set result(this->capacity + s2.capacity);
    for (int i = 0; i < this->noOfElements; i++) {
        if (s2.isMember(this->data[i])) {
            result.insert(this->data[i]);
        }
    }
    return result;
}

int Set::isMember(int val) const {
    for (int i = 0; i < this->numOfElements; i++) {
        if(this->data[i] == val) return 1;
    }
    return 0;
}

int Set::isSubSet(const Set& s2) const {
    int count = 0;
    for (int i = 0; i < s2.noOfElements; i++) {
        if (this->isMember(s2.data[i])) {
            count++;
        }
    }

    if (count == this->noOfElements && count < s2.noOfElements) {
        return 1; // Proper Subset
    } else if (count == this->noOfElements && count == s2.noOfElements) {
        return 2; // Improper Subset
    } else {
        return 0; // Not a Subset
    }
}

void Set::resize(int newCapacity) {
    if (newCapacity < 0) newCapacity = 0;

    if (newCapacity >= this->numOfElements) {
        int* newData = new int[newCapacity];
        for (int i = 0; i < this->noOfElements; i++) {
            newdata[i] = data[i];
        }

    delete[] data;
    data = newdata;
    capacity = newcapacity;
    }
}

void Set::update(int prVal, int curVal) {
     if (!isMember(prVal)) {
        cout << "Target value not found." << endl;
        return;
    }

    if (isMember(curVal)) {
        cout << "Violation set property. Can't Modify the data." << endl;
        return;
    }

    for (int i = 0; i < numOfElements; i++) {
        if (data[i] == prVal) data[i] = curVal;
    }
     cout << "Record update successfully." << endl;
}

void Set::show() const {
    for (int i = 0; i < noOfElements; i++) {
        cout << data[i] << " ";
    }
}

int main() {
    Set s(10);

    s.insert(5);
    s.insert(10);
    s.insert(15);

    Set s2 = s;
    s2.insert(20);

    Set s3 = s.calcUnion(s2);
    Set s4 = s.calcSymmetricDifference(s2);
    Set s5 = s.calcDifference(s2);

    s.show(); // Output: 5 10 15
    cout << endl;

    s2.show(); // Output: 5 10 15 20
    cout << endl;

    s3.show(); // Output: 5 10 15 20
    cout << endl;

    s4.show(); // Output: 20
    cout << endl;

    s5.show(); // Output: 5 10 15
    cout << endl;

    s.update(5, 25); // Record update successfully.

    s.show(); // Output: 25 10 15
    cout << endl;

    return 0;

}