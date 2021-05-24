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

int Get(struct array arr, int index) // Brings the element present at that index
{
    if (index >=0 && index < arr.length)
    {
        return arr.A[index];
    }
    return -1;
}

void Set(struct array *arr, int index, int x) // Fetches the element present at that index and changes it's value to the new element 
{
    if (index >=0 && index < arr->length)
    {
        arr->A[index]=x;
    }
}

int Max(struct array arr)
{
    int max= arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    return max;
}

int Min(struct array arr)
{
    int min=arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }
    return min;
}

int Sum(struct array arr)
{
    int sum=0;
    for (int i = 0; i < arr.length; i++)
    {
        sum=sum+arr.A[i];
    }
    return sum;
}

float Avg(struct array arr)
{
    return (float)Sum(arr)/arr.length;
}
int main()
{
    struct array arr={{2,3,4,5,25},10,5};

    cout <<Get(arr,3)<<endl;
    Set(&arr, 0, 15);
    cout <<Max(arr)<<endl;
    cout <<Min(arr)<<endl;
    cout <<Sum(arr)<<endl;
    cout <<Avg(arr)<<endl;
    Display(arr);
    return 0;
}
