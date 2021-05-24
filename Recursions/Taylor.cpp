#include <iostream>
using namespace std;
double e(int x, int n)
{
    static double p=1, f=1;
    double r;
    if (n==0)
    {
        return 1;
    }
    else
    {
        r=e(x, n-1); // Head Recursion
        p=p*x;
        f=f*n;
        return r+p/f;
    }
}
double iterativetaylor(int x, int n)
{
    double s=1;
    double num=1;
    double den=1;

    for (int i = 1; i <= n; i++)
    {
        num*=x;
        den*=i;
        s+=num/den;
    }
    return s;
}
int main()
{
    cout <<e(1,10)<<endl;
    cout <<iterativetaylor(1, 10);
    return 0;
}
