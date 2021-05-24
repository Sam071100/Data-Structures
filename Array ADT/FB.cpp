// Interview question
// Moving all the zeros to the extreme right
#include <iostream>
using namespace std;
int main()
{
    int length, size,j=1;
    cin >>size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >>arr[i];
    }
    length=size;
    cout <<"Printing the Array before transformation\n";
    for (int i = 0; i < size; i++)
    {
        cout <<arr[i]<<" ";
    }
    for (int i = length-1; i >=0; i--)
    {
        if (arr[i]==0)
        {
            swap(arr[i], arr[length-j]);
            j++;
        }
    }
    cout <<"Printing the array after transformation\n";
    for (int i = 0; i < length; i++)
    {
        cout <<arr[i]<<" ";
    }
    
    return 0;
}
