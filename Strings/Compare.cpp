#include <iostream>
using namespace std;
int main()
{
    char a[]="painter";
    char b[]="painter";// Compared on the value of ASCII key of the Alphabets.
    int i=0,j=0;
    for ( i = 0, j=0 ;(a[i]!='\0')&&(b[i]!='\0'); i++,j++)
    {
        if (a[i]!=b[j])
        {
            break;
        }
    }
    if (a[i]==b[j])
    {
        cout <<"EQUAL"<<endl;
    }
    else if (a[i] < b[j])
    {
        cout <<"The first string is smaller\n";
    }
    else
    {
        cout <<"The second string is smaller\n";
    }
    
    
    return 0;
}
