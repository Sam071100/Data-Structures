#include <iostream>
using namespace std;

struct array
{
    int A[10];
    int size;
    int length;
};

void Display(struct array arr)
{
    cout << "\nElements are: \n";
    for (int i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
}

struct array* Merge(struct array *arr1, struct array *arr2)// the return type of the function is struct pointer.
{
    int i = 0, j = 0, k = 0;
    struct array *arr3 = new struct array[sizeof(struct array)]; // dynamic array pointing the heap memory like the struct pointer.
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else
        {
            arr3->A[k++] = arr2->A[j++];
        }
    }
    // Code for copying the remaining Elements.
    for (; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for (; j < arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;

    return arr3; // as it is created in heap so it can be returned to the main function.
}

int main()
{
    struct array arr1 = {{2, 6, 10, 15, 25}, 10, 5};
    struct array arr2 = {{3, 4, 7, 18, 20}, 10, 5};
    struct array *arr3;

    arr3=Merge(&arr1, &arr2);
    Display(*arr3);
    return 0;
}
