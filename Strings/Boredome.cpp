#include <bits/stdc++.h>
using namespace std;
#define N 100500

int main()
{
    int arr[100500]={0};
    int t;
    cin >>t;
    while(t--)
    {
       int sum=0,sum1=0,diff=0;
       string str;
       cin >>str;
       
       for (int i = 0; i < str.length(); i++)
       {
           if (i % 2 == 0)
           {
              sum1=sum1+str[i];    
           }
           else
           {
               diff= diff-str[i];
           }
       }
       sum= sum1+diff;// Here we are having the segmentation error as the whole sum is coming to be negative and the array is accessed for the negative element
       if (sum < 0)
       {
           sum+=N;
       }
       arr[sum]++;
       if (arr[sum]==1)
       {
           cout <<"OK"<<endl;
       }
       else
       {
           cout <<str<<arr[sum]-1<<endl;
       }

    }
    return 0;
}
