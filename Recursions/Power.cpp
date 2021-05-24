#include <iostream>
using namespace std;
int power(int m, int n)
{
    if (n==0)
    {
        return 1;
    }
    else
    {
        return power(m, n-1)*m;
    }  
}
int power1(int m, int n)
{
    if (n==0)
    {
        return 1;
    }
    if (n % 2==0)
    {
        return power1(m*m ,n/2);
    }
    return m*power1(m*m, (n-1)/2);
}
int iterativePow(int m ,int n)
{
    int sum=1, count=1;
    if (n==0)
    {
        return 1;
    }
    else
    {
        while (n >= count)
        {
            sum=sum*m;
            count++;
        }
        return sum;
    }
    
}
int main()
{
    int r=power(2,9); // this functions take more time 
    cout <<r<<endl;
    int s=power1(2,9);
    cout <<s<<endl; // Time Complexity is O(n);
    int t=iterativePow(2,9);
    cout <<t; //time complexity is O(n)
    return 0;
}
