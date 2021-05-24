#include <iostream>
using namespace std;
struct array
{
    int A[10];
    int size;
    int length;
};
void display(struct array arr)
{
    cout <<"\nElements are: \n";
    for (int i = 0; i < arr.length; i++)
    {
        cout <<arr.A[i]<<" ";
    }
}

// The difference between append and insert is that append inserts at the element at the last index but with insert you can insert at any index and shift the array forward.
void Insert(struct array *arr, int index, int x)
{
    if (index >= 0 && index <= arr->length)
    {
        for (int i = arr->length; i > index; i--)
        {
            arr->A[i]=arr->A[i-1];// shifting the every element of the array forward
        }
             arr->A[index]=x;
            arr->length++;
    }
}
void Delete(struct array *arr, int index)
{
    
    if (index >= 0 && index < arr->length)
    {
        for (int i = index; i < arr->length-1; i++)
        {
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
    }
}
int main()
{
    struct array arr={{2,3,4,5,6},10,5};
    
    Insert(&arr,3,7);// index of the array starts from 0
    display(arr);
    Delete(&arr,3);
    display(arr);
    return 0;
}
