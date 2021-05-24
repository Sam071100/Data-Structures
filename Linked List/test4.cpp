#include <bits/stdc++.h>
using namespace std;
// Coded BY SHUBHAM SAMRAT
int main()
{
    int t;
    cin >>t;
    while(t--)
    {
       int n,m;
       cin >>n>>m;
       set<int> h1;
       stack<int> s1;
       h1.insert(0);
       s1.push(0);
       int a[n];
       int b[m];
       for (int i = 0; i < n; i++)
       {
           cin >>a[i];
       }
       for (int i = 0; i < m; i++)
       {
           cin >>b[i];
       }
       while (!s1.empty())
       {
           int x = (s1.top());
           s1.pop();
           for (int i = 0; i < n; i++)
           {
               int y=a[i];
               if (!h1.count(x|y))//
               {
                   h1.insert(x|y);
                   s1.push(x|y);
               }
           }
           for (int i = 0; i < m; i++)
           {
               int y=b[i];
               if (!h1.count(x&y))
               {
                   h1.insert(x&y);
                   s1.push(x&y);
               }
           }
       }
       cout <<h1.size()<<endl;
    }
    return 0;
}
