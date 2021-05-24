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

struct array* UnionofSorted(struct array *arr1, struct array *arr2)
{
    int i = 0, j = 0, k = 0;
    struct array *arr3 = new struct array[sizeof(struct array)]; // dynamic array pointing the heap memory like the struct pointer.
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else if(arr2->A[j] < arr1->A[i])
        {
            arr3->A[k++] = arr2->A[j++];
        }
        else // Both are equal then copy one of the element and incrementing both i and j
        {
            arr3->A[k++]= arr1->A[i++];
            j++;
        }
    }
    for (; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for (; j < arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length =k;
    arr3->size = 10;

    return arr3; 
}

struct array* Intersection(struct array *arr1, struct array *arr2)
{
    int i = 0, j = 0, k = 0;
    struct array *arr3 = new struct array[sizeof(struct array)]; // dynamic array pointing the heap memory like the struct pointer.
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            i++;
        }
        else if(arr2->A[j] < arr1->A[i])
        {
            j++;
        }
        else // Both are equal then copy one of the element and incrementing both i and j
        {
            arr3->A[k++]= arr1->A[i++];
            j++;
        }
    }
    
    arr3->length =k;
    arr3->size = 10;

    return arr3; 
}

struct array* Difference(struct array *arr1, struct array *arr2)
{
    int i = 0, j = 0, k = 0;
    struct array *arr3 = new struct array[sizeof(struct array)]; // dynamic array pointing the heap memory like the struct pointer.
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else if(arr2->A[j] < arr1->A[i])
        {
            j++;
        }
        else // Both are equal then copy one of the element and incrementing both i and j
        {
            i++;
            j++;
        }
    }
    // Copy the remaining elements from the arr1
    for (; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    
    arr3->length =k;
    arr3->size = 10;

    return arr3; 
}

int main()
{
    struct array arr1 = {{2, 6, 10, 15, 25}, 10, 5};
    struct array arr2 = {{3, 6, 7, 15, 20}, 10, 5};
    struct array *arr3;
    // Union operation on the sorted array using the Merge function.
    arr3=UnionofSorted(&arr1, &arr2);// the output is union of arr1 and arr2 without repeating the duplicates.
    Display(*arr3);

    arr3=Intersection(&arr1, &arr2); // The output is the intersection of the arr1 and the arr2 so it prints only the common element in both the arrays
    Display(*arr3);

    arr3=Difference(&arr1, &arr2);// arr1 - arr2: The output will be only the elements of the arr1 leaving the intersection of both the arrays.
    Display(*arr3);
    
    // Set membership is nothing but searching an element in the array by linear search or binary search.
    return 0;
}
