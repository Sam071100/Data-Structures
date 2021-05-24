#include <iostream>
using namespace std;

struct array 
{
    int *A;
    int size;
    int length;
};
void input(struct array *arr);// Just Declaring the function.

void DefaultConstructor(struct array *arr)// This is a default Constructor
{
    arr->size=10;
    input(arr);
}

void ParameterizedConstructor(struct array *arr,int sz)// This is parameterized Constructor
{
    arr->size = sz;
    arr->A = new int[arr->size];
    cout << "\nEnter the Length of the Array\n";
    cin >> arr->length;
    for (int i = 0; i < arr->length; i++)
    {
        cin >> arr->A[i];
    }
}

void Destructor(struct array *arr)// This will acts as a destructor.
{
    delete []arr;
}

void display(struct array arr)
{
    cout <<"\nElements are: \n";
    for (int i = 0; i < arr.length; i++)
    {
        cout <<arr.A[i]<<" ";
    }
}

 void input(struct array *arr)
{
    cout <<"Enter the Size of the Array\n";
    cin >>arr->size;

    arr->A= new int[arr->size];
    cout <<"\nEnter the Length of the Array\n";
    cin >>arr->length;
    cout <<"Enter the Elements of the Array\n";
    for (int i = 0; i < arr->length; i++)
    {
        cin >>arr->A[i];
    }
}

void insert(struct array *arr, int index, int x)// This is only possible if you have size > length.
{
    if (index >= 0 && index <= arr->length)
    {
        for (int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1]; // shifting the every element of the array forward
        }
        arr->A[index] = x;
        arr->length++;
    }
}
int main()
{
    struct array arr; // Here arr is the element of this structure

    input(&arr);
    display(arr);

    DefaultConstructor(&arr);
    display(arr);

    ParameterizedConstructor(&arr, 10);
    display(arr);

    insert(&arr, 4, 8);// Inserting the element 8 at the index 4.
    display(arr);

    Destructor(&arr);

    return 0;
}
