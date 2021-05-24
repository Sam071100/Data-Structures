#include <bits/stdc++.h>
using namespace std;

int cutRod(int *p, int n)
{
    if (n <=0)
    {
        return 0;
    }
    int max_val= INT_MIN;
    for (int i = 0; i < n; i++)
    {
         max_val= max(max_val, p[i]+cutRod(p, n-i-1));
    }
    return max_val;
}
int main()
{
    int n; // n is the size of the array
    cout <<"Enter the length of the Rod\n";
    cin >>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >>arr[i];
    }
    cout <<"The Max Price after cutting the Rod is "<<cutRod(arr,n);
    return 0;
}
