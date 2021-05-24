#include <iostream>
using namespace std;

void Method1(char *s)
{
    char b[25];
    int i=0,j=0;
    for ( i = 0; s[i] !='\0'; i++)
    {
    }
    i-=1;
    
    for ( j = 0; i >=0; j++,i--)
    {
        b[j]=s[i];
    }
    b[j]='\0';
    puts(b);
}

void Method2(char *s)
{
    int j=0;
    for ( j = 0; s[j]!='\0'; j++)
    {
    }
    j=j-1;// It will point to the last character of the String
     for (int i = 0; i < j; i++, j--)
     {
        swap(s[i],s[j]);
     }
    puts(s);
}
int main()
{
    int count=0;
    char s[25];
    gets(s);
    Method1(s);
    Method2(s);
    return 0;
}
