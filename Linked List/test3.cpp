#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t;
    cin >>t;
    while(t--)
    {
       ll n;
       cin >>n;
       ll m;
       cin >>m;
       ll count1=0, count2=0;
       for (int i = 0; i < m; i++)
       {
           ll a;
           cin >>a;
           if (a > 0)
           {
               count2++;// positive counts
           }
           else if (a <=0)
           {
               count1++;//negative counts
           }
       }
       ll sum =count1*count2;
       cout <<sum<<endl;
    }
    return 0;
}
