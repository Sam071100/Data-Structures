#include <iostream>
using namespace std;

class array
{

private:    
    int *A;// Yeh bas ek pointer hai
    int size;
    int length;

public:
    array() // Default Constructor
    {
        size = 10;
        length = 0;
        A = new int[size];
    }
    array(int sz) // Parameterized Constructor
    {
        size = sz;
        length = 0;
        A = new int[size];
    }
    ~array() // Destructor to free the dynamic memory
    {
        delete[] A;
    }
    
    int Delete(int index);
    void Display();
    void Append(int x);
    void Insert(int index, int x);
    int LinearSearch(int key);
    int BinarySearch(int key);
    int RBinarySearch(int a[], int l, int h, int key);
    int Get(array arr, int index);
    void Set(array *arr, int index, int x);
    int Max(array arr);
    int Min(array arr);
    int Sum(array arr);
    float Avg(array arr);
    void Reverse(array arr);
    void Reverse2(array arr);
    void InsertSort(array arr, int x);
    int IsSorted(array arr);
    void Rearrange(array arr);
    array *Merge(array arr2);
    array *Union(array arr2);
    array *Intersection(array arr2);
    array *Difference(array arr2);
    void Input(array arr1);
};

void array::Display()
{
    cout << "Elements are\n";
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
}
void array::Append(int x) // Add a new element at the end of the array
{
    if (length < size) // pass by address.
    {
        A[length++] = x; // Last position mai X ki value store karke length ki value ko increment by 1 kardiya
        cout << "By pass by Address\n";
    }
}
void array::Insert(int index, int x)
{
    if (index >= 0 && index <= length)
    {
        for (int i = length; i > index; i--)
        {
            A[i] = A[i - 1]; // shifting the every element of the array forward
        }
        A[index] = x;
        length++;
    }
}
 array* array:: Merge(array arr2)// Return type of this function is pointer
{
    int i = 0, j = 0, k = 0;
    struct array *arr3 = new struct array[length+ arr2.length]; // dynamic array pointing the heap memory like the struct pointer.
    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j])
        {
            arr3->A[k++] = A[i++];
        }
        else
        {
            arr3->A[k++] = arr2.A[j++];
        }
    }
    // Code for copying the remaining Elements.
    for (; i < length; i++)
    {
        arr3->A[k++] = A[i];
    }
    for (; j < arr2.length; j++)
    {
        arr3->A[k++] = arr2.A[j];
    }
    arr3->length = length + arr2.length;

    return arr3; // as it is created in heap so it can be returned to the main function.
}

// Similarly modify the other Functions
int main()
{
    int ch,sz;
    cout <<"Enter the size of the array 2\n";
    cin >>sz;

    array arr1;// its your choice you want the default array or want to enter the size of the array yourself.
    array arr2(sz); // Here we have created the object by entering the size myself.

    do
    {
        cout << "\nMenu\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Sum\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";

        cout << "Enter your Choice\n";
        cin >> ch;
        int x, index;

        switch (ch)
        {
        case 1:
            cout << "Enter an element and index\n";
            cin >> x >> index;
            arr2.Insert(index, x);
            break;
        // case 2:
        //     cout << "Enter index\n";
        //     cin >> index;
        //     x = arr1.Delete(index);
        //     cout << "Deleted Element is " << x << endl;
        //     break;
        // case 3:
        //     cout << "Enter the Element to Search\n";
        //     cin >> x;
        //     index = arr1.LinearSearch(x);
        //     cout << "Element index: " << index << endl;
        //     break;
        // case 4:
        //     cout << "Sum is " << arr1.Sum(arr1) << endl;
        //     break;
        case 5:
            arr2.Display();
            break;
        }
    } while (ch < 6);

    return 0;
    
}
