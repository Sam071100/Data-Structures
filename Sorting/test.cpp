#include <bits/stdc++.h>
using namespace std;

int Max(int *A, int n)
{
    int max_ele = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max_ele < A[i])
        {
            max_ele = A[i];
        }
    }
    return max_ele;
}

int main()
{
    int A[] = {3, 7, 9, 6, 6, 5, 12, 4, 11, 2}, n = 10;
    int max_ele = Max(A, n);
    int count[max_ele+1];

    memset(count, 0, sizeof(count)); // Intialize the count array with 0

    for (int i = 0; i < n; i++)
    {
        count[A[i]]++;
    }
    
    int i=0, j=0;
    while (i < max_ele+1)
    {
        if (count[i] > 0)
        {
            A[j++] = i;
            count[i]--;
        }
        else
        {
            i++;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
