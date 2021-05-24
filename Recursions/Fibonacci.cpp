#include <iostream>
using namespace std;
int fib(int n)
{
    int t0=0,t1=1,s=0;
    if (n<=1)
    {
        return n;
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            s=t0+t1;
            t0=t1;
            t1=s;
        }
        return s;
    }
}
int rfib(int n)
{
    if (n<=1)
    {
        return n;
    }
    else
    {
        return rfib(n-2)+ rfib(n-1);
    }
}
int main()
{
    cout <<fib(10)<<endl;
    cout <<rfib(10);
    return 0;
}
