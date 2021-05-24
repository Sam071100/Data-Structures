#include <iostream>
using namespace std;

// Only for the lowercase alphabets
//https://en.cppreference.com/w/c/language/operator_precedence  Operator precedence
void Method1(char *s)
{
    int H[26]={0}, sum=0;// For hashing
    for (int i = 0; s[i]!='\0' ; i++)
    {
        H[s[i]-97]++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (H[i] > 1)
        {
            sum =i+97;
            cout <<(char)sum<<" Is Repeated "<<H[i]<<" Times"<<endl;// Please refer as here we cout the alphabets using the ASCII value.
            sum=0;
        }
    }
    
}

void Method2(char *s)// Using Bitwise Operations.....Merging and Masking (for clarity refer the notes)
{
    int H=0, x=0,times;// Here H is the 32 bit int variable.
    for (int i = 0; s[i]!='\0'; i++)
    {
        x=1;
        x=x<<(s[i]-97); 

        if ((x & H) >0)// Masking // Remember to enclose the the & binary operator in the brackets due to operator precedence.
        {
            cout <<s[i]<<" is duplicate\n";
        }
        else
        {
            H=x|H;// Merging
        }
    }
}

int main()
{
    char s[25];
    cout <<"Enter your string"<<endl;
    gets(s);
    Method1(s);
    Method2(s);
    return 0;
}
