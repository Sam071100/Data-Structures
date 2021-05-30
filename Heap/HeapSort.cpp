#include <iostream>
using namespace std;

void Insert(int *H, int n)
{
    int i = n, temp;
    temp = H[i];

    while (i > 1 && temp > H[i/2])
    {
        H[i] = H[i/2]; // parent ke value niche wale child mai dal di
        i =i/2;
    }
    H[i] = temp;
}

void Print(int *H)
{
    for (int i=1; i <= 7; i++)
        {
            cout <<H[i]<<" ";
        }
        cout <<"\n";
}

int Delete(int *H, int n)
{
    // n is the size of the heap
    int i, j, val;
    val = H[1];
    H[1] = H[n];
    i =1, j = i*2;
    
    while (j+1 < n) // right child should be less
    {
        if (H[j+1] > H[j])
        {
            j++;
        }
        if (H[i] < H[j])
        {
            swap(H[i], H[j]);
            i = j;
            j = 2*j;
        }
        else
        {
            break;
        }
    }
    H[n]=val;
    return val; // returning the deleted value
 }

int main()
{
    int H[] = {0, 10, 20, 30, 25, 5, 40, 35}; // 0 is ignorable as we are not going to use that location
    for (int i = 2; i <= 7; i++)
    {
        Insert(H,i);
    }
    Print(H);
    // Delete(H,7);
    // Delete(H,6);// heap size reduced by deleting the element above so passing 6
    // Print(H);

    // Heap Sort --> Time = O(N LogN) for the max Heap
    for (int i = 7; i > 1; i--)
    {
        Delete(H,i);
    }
    Print(H); // returns the array in the ascending order
    // IF done for min Heap it will return the element in descending order
    return 0;
}
