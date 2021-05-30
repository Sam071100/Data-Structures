#include <bits/stdc++.h>
using namespace std;

void InsertA(int A[], int n)
{
    int i = n;
    int temp = A[n];
    while (i > 0 && temp > A[i % 2 == 0 ? (i/2)-1 : i/2])
    {
        A[i] = A[i % 2 == 0 ? (i/2)-1 : i/2];
        i = i%2==0?(i/2)-1:i/2; // This much condition is required bcoz we are dealing with index 0 also but in the notes the array started with index 1
    }
    A[i]= temp;
}

void Insert(vector<int>&vec, int key)
{
    auto i = vec.size();
    vec.emplace_back(key);
    while (i > 0 && key > vec[i%2 ==0 ?(i/2)-1:i/2])
    {
        vec[i] = vec[i%2==0?(i/2-1):i/2];
        i = i/2;
    }
    vec[i] = key;
}

template <class T>
void Print(T vec, int n)
{
    cout <<"Max Heap: [";
    for (int i = 0; i < n; i++)
    {
        cout <<vec[i]<<", ";
    }
    
    cout <<"]"<<endl;
}

int main()
{
    int A[] = {45, 35, 15, 30, 10, 12, 6, 5, 20, 50};
    // I am inserting 50 into the heap 50 into the heap
    // passing the array A and the index of the element to be inserted into the array
    InsertA(A,9);
    Print(A, sizeof(A)/sizeof(A[0]));

    vector<int> v ={45,35,15,30,10,12,6,5,20};
    v.reserve(15); // Reserve space for 15 elements
    Insert(v,50);
    Print(v, v.size());
    
    return 0;
}
