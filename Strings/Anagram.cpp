#include <iostream>
using namespace std;
int main()
{
    int i=0;
    char A[25],B[25];
    cout <<"Input the String A\n";
    gets(A);
    cout <<"Input the string B\n";
    gets(B);
    int H[26]={0};// For hashing
    for (int i = 0; A[i]!='\0'; i++)
    {
        H[A[i]-97]++;
    }
    for ( i = 0; B[i]!='\0'; i++)
    {
        H[B[i]-97]--;
        if (H[B[i]-97] < 0)// Modifications, pleasae remember this types of modificaton
        {
            cout <<"It is not an ANAGRAM\n";
            break;
        }
    }
    if (B[i]=='\0')
    {
        cout <<"It is ANAGRAM\n";
    }
    
    return 0;
}
