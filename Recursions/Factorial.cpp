#include <iostream>
using namespace std;
int fact(int n)
{
    if (n==0)
    {
        return 1;
    }
    else
    {
        return fact(n-1)*n;
    }
    
}
int iterativefact(int n)
{
    if (n<=0)
    {
        return 1;
    }
    else
    {
        int s=1;
        for (int i = 1; i <=n; i++)
        {
            s=s*i;
        }
        return s;
    }
    
}
int main()
{
    int r=fact(5);
    int s=iterativefact(5);
    cout <<s<<"\n"<<r;
    return 0;
}
