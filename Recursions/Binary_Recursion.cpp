#include <bits/stdc++.h>
using namespace std;

int toDecimal(string binary, int i=0)
{ 
    int n= binary.length();
    if (i == n-1) // Base condition
    {
        cout <<binary[i]-'0'<<endl;
        return binary[i]-'0';
    }
    cout <<binary[i]-'0'<<(n-i-1); // Left shift operator for multiplication by the multiples of 2.
    return toDecimal(binary, i+1)+((binary[i]-'0')<<(n-i-1));
}

int main()
{
    string binary ="1111";
    cout << toDecimal(binary)<<endl;
    return 0;
}
