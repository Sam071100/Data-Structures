#include <iostream>
#include <cmath>

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
// Key is the element you want to search
int BinarySearch(struct array arr, int l, int h, int key)
{
    while (l <= h)
    {
        int mid;
        mid= ceil((l+h)/2);
        if (key == arr.A[mid] )
        {
            return mid;
        }
        else if (key < arr.A[mid])
        {
            h= mid-1;
        }
        else if (key > arr.A[mid])
        {
            l= mid+1;
        }
    }
    return -1;
}

int BinarySearchR(struct array arr, int l, int h, int key)
{
    if (l <= h) // Base Case
    {
        int mid= ceil((l+h)/2);
        if (key == arr.A[mid])
        {
            return mid;
        }
        else if (key < arr.A[mid])
        {
            return BinarySearchR(arr, l, mid-1, key);
        }
        else if (key > arr.A[mid])
        {
            return BinarySearchR(arr, mid+1, h, key);
        }
    }
    return -1;
}
int main()
{
    struct array arr={{2,3,4,5,6},10,5};
    
   int found1 = BinarySearch(arr,0,5,4);
   cout <<found1<<endl;
   int found2 = BinarySearchR(arr,0,5,4);
   cout <<found2<<endl;

    return 0;
}
