#include <iostream>
using namespace std;
struct Array
{
    int *A;
    int size;
    int length;
};
void display(struct Array arr)
{
    cout <<"Elements are\n";
    for (int i = 0; i < arr.length; i++)
    {
        cout <<arr.A[i]<<" ";
    }
    
}
int main()
{
    int n;
    struct Array arr;
    cout <<"Enter the size of the Array\n";
    cin >>arr.size;
    arr.A= new int [arr.size]; // Dynamic Array
    arr.length=0;

    cout <<"Enter how many elements you want to enter into the array\n";
    cin >>n;

    cout <<"Enter all the Elements\n";
    for (int i = 0; i < n; i++)
    {
        cin >>arr.A[i];
    }
    arr.length=n;

    display(arr);
    return 0;
}
