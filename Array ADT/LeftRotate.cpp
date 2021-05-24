#include <iostream>
using namespace std;

void LeftRotate(int arr[], int n)
{
    int temp=arr[0],i;
    for ( i = 0; i < n-1; i++)
    {
        arr[i]=arr[i+1];
    }
        arr[i]=temp;
}
void LeftRotatebyd(int *p, int d, int n)// Here d is the number by which we are going to rotate the array
{
    for (int i = 0; i < d; i++)
    {
        LeftRotate(p,n);
    }
    
}
void Print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout <<arr[i]<<" ";
    }
}

int main()
{
    int n;
    cout << "Enter the size of the Array\n";
    cin >> n;
    int arr[n];
    cout << "Enter your Elements\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    LeftRotatebyd(arr,2, n);
    Print(arr,n);
    return 0;
}
