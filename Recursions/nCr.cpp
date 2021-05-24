#include <iostream>
using namespace std;
int fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return fact(n-1)*n;
    }
}
int nCr(int n, int r)
{
    int num, den;

    num=fact(n);
    den=fact(r)*fact(n-r);
    return num/den;
}
int nCr1(int n, int r)
{
    if (n==r || r==0)
    {
        return 1;
    }
    
    return nCr1(n-1, r-1)+nCr1(n-1, r);
}
int main()
{
    cout <<nCr(10,3)<<endl;
    cout <<nCr1(10,3)<<endl;
    return 0;
}
