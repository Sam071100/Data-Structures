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
// Key is the element you want to search
int LinearSearch(struct array arr,int key)  // Iterative Way
{
     for (int i = 0; i < arr.length; i++)
     {
         if (key == arr.A[i])
         {
             return i;
         }
     }
     return -1;
}

int LinearSearchTransposition(struct array arr, int key) // By Transposition
{
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i]== key)
        {
            swap(arr.A[i],arr.A[i-1]);
            return i-1;
        }
    }
    return -1;
}

int LinearSearch2(struct array arr, int key) // By moving to Head or front
{
     for (int i = 0; i < arr.length; i++)
     {
         if (arr.A[i]== key)
         {
             swap(arr.A[i], arr.A[0]);
             return 0;
         }
     }
     return -1;
}
int LinearSearchR(struct array arr, int l, int r, int key) // Recursive way 
{
    if (l > r)
    {
        return -1;
    }
    if (arr.A[l]== key)
    {
        return l;
    }
    if (arr.A[r]== key)
    {
        return r;
    }
    return LinearSearchR(arr,l+1,r-1,key);
}
int main()
{
    struct array arr={{2,3,4,5,6},10,5};
    
   int found= LinearSearch(arr,4);
   cout <<found<<endl;
   int found2=LinearSearchR(arr,0,(arr.length)-1,4);
   cout <<found2<<endl;
   int found3=LinearSearchTransposition(arr,4);
   cout <<found3<<endl;
   int found4=LinearSearch2(arr,4);
   cout <<found4;
    return 0;
}
