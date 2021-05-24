#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin >>n;
    int arr1[n];
    int arr2[n];
    for (int i = 0; i < n; i++)
    {
        cin >>arr1[i];
    }
    for (int j = 0; j < n; j++)
    {
        cin >>arr2[j];
    }
    cin >>k;
    sort(arr1, arr1+n);
    sort(arr2, arr2+n);
    string s1, s2, s3;
    int count=0, x, i=0;
    while (i < n)
    {
        s1.push_back(arr1[i]);
        s2.push_back(arr2[n-i-1]);
        s3= s1+ s2;
        x =stoi(s3);
        if (x < k)
        {
            count++;
        }
        s1 ="\0";
        s2 ="\0";
        i++;
    }
    cout <<count<<endl;
    return 0;
}
