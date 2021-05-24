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
    cout <<"\nElements are: \n";
    for (int i = 0; i < arr.length; i++)
    {
        cout <<arr.A[i]<<" ";
    }
}

void InsertSort(struct array *arr, int x)// Inserts the element in the Sorted position.
{
    int i= arr->length-1;
    if (arr->length == arr->size)
    {
        return;
    }
    while (arr->A[i] > x && i>=0)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++; // incrementing the length as the new element is added.
}

int IsSorted(struct array arr)// Sorted means arranged in the ascending order.
{
    for (int i = 0; i < arr.length-1; i++)
    {
        if (arr.A[i] > arr.A[i+1] )
        {
            return 0; // If the output is 0 that means the array is not sorted.
        }
    }
    return 1; // if the output is 1 that means the array is sorted
}
void Rearrange(struct array *arr) //-ve on the lefthand side and the +ve on the right hand side.
{
    int i=0, j=arr->length-1; 
    while (i<j)
    {
        while (arr ->A[i] < 0)
        {
            i++;
        }
        while (arr->A[j] >= 0)
        {
            j--;
        }
        if (i < j)  
        {
            swap(arr->A[i],arr->A[j]);
        }
    }
    
}
int main()
{
    struct array arr={{2,3,4,-5,6},10,5};
     Display(arr);

     InsertSort(&arr,1);
     Display(arr);

     cout <<"\n"<<IsSorted(arr);

    Rearrange(&arr);
    Display(arr);

    return 0;
}
