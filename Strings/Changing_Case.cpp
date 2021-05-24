//Changing the case of the string
#include <iostream>
using namespace std;
int main()
{
    char arr[25];
    // Converting from uperCase to LowerCase:
    cout <<"Only input the String in the Upper Case"<<endl;
    gets(arr);
    for (int i = 0; arr[i]!='\0'; i++)
    {
        if (arr[i]>=65 && arr[i] <=90)
        {
            arr[i]= arr[i]+32;
        }
    }
    cout <<"Printing the converted String"<<endl;
    puts(arr);
    cout <<"\n";
    cout <<"Converting back into the Upper Case\n";
    for (int i = 0; arr[i]!='\0'; i++)// Doubt why the 32 or the spacebar is being counted in the if condition and becoming the null character and hence terminating my string.
    {
        if (arr[i]>=97 && arr[i]<=122)
        {
           arr[i]=arr[i]-32;
        }
    }
    puts(arr);
    return 0;
}
