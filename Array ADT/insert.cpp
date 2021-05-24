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
void Append(struct array *arr,int x) // Add a new element at the end of the array
{
    if ((*arr).length < arr->size) // pass by address.
    {
        arr->A[arr->length++]=x;// Last position mai X ki value store karke length ki value ko increment by 1 kardiya
        cout <<"By pass by Address\n";
    }
}
void  Append2(struct array &arr, int x)// pass by reference
{
    if (arr.length < arr.size)
    {
        arr.A[arr.length++]=x;
        cout <<"\nBy pass by refernce\n";
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
int main()
{
    struct array arr={{2,3,4,5,6},10,5};
    Append(&arr,10);// At the last I am entering the element 10.
    display(arr);
    Append2(arr,20);
    display(arr);
    Insert(&arr,3,7);// index of the array starts from 0
    display(arr);
    return 0;
}
