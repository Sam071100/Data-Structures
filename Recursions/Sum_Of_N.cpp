#include <iostream>
using namespace std;
int sum(int n)
{
    if (n==0)
    {
        return 0;
    }
    return sum(n-1)+n;
}
int iterativeSum(int n)
{
    int s=0;
    for (int i = 1; i <= n; i++)
    {
        s=s+i;
    }
    return s;
}
int main()
{
    int r=sum(5);
    int s=iterativeSum(5);
    cout <<r<<"\n"<<s;
    return 0;
}
