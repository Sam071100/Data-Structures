#include <iostream>
using namespace std;
int main()
{
    // The second method is comparing within the own array by using the swap.
    char a[]="liril";
    char b[25];
    int i,j;
    for ( i = 0; a[i]!='\0'; i++)
    {
    }
    i-=1;// Here i points the last character of the string
    for ( j = 0; i >=0 ; j++,i--)
    {
        b[j]=a[i];
    }
    b[j]='\0';// Here this is very important.
    // Now we have to compare both of the strings for the palindrome.
    for (i = 0,j=0; (a[i]!='\0')&&(b[j]!='\0') ; i++,j++)// Don't write the int in the for loop if the value of its variable like i is going to be used after the termination of the for loop.
    {
        if (a[i]!=b[j])
        {
            cout <<"NOT A PALINDROME\n";
            break;
        }
    }
    if (a[i]==b[j])
    {
        cout <<"PALINDROME\n";
    }
    
    return 0;
}
