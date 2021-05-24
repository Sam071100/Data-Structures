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

void Reverse1(struct array *arr)
{
    // By Auxillary Method
    int *B=NULL;
    B= new int[arr->length]; // Dynamic memory allocation
    for (int i = arr->length-1, j=0; i>=0; i--, j++)// In these types of for loop always the condition should be one.
    {
        B[j]=arr->A[i];
    }
    for (int i = 0; i < arr->length; i++)
    {
        arr->A[i]=B[i];
    }
    delete []B; // Freeing the dynamic memory
}
void Reverse2(struct array *arr)
{
    // By Swapping Method
    for (int i = 0, j=arr->length-1; i<j ;i++, j-- )
    {
        swap(arr->A[i],arr->A[j]);
    }
    
}
int main()
{
    struct array arr={{2,3,4,5,6},10,5};
    Display(arr);

    Reverse1(&arr);
    Display(arr);

    Reverse2(&arr);
    Display(arr);
    return 0;
}
