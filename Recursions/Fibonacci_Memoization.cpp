#include <iostream>
using namespace std;
int r[10]; // instead of this use vector
int fib(int n)
{
    if (n<=1)
    {
        r[n]=n;
        return n;
    }
    else
    {
        if (r[n-2]==-1)
        {
            r[n-2]=fib(n-2);
        }
        if (r[n-1]==-1)
        {
            r[n-1]=fib(n-1);
        }
        r[n]=r[n-2]+r[n-1];
        return r[n-2]+r[n-1];
    }
    
}
int main()
{

    for (int i = 0; i < 10; i++)
    {
        r[i]=-1;
    }
    cout <<fib(5);
    return 0;
}
