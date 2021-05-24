#include <iostream>
using namespace std;
int main()
{
    // Counting the number of vowels and consonants
    string s;
    getline(cin ,s);
    int length=s.length();
    int count=0;
    int word=1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
        {
            count++;
        }
        
        else if (s[i]==32) // Removing the count of the spacebar
        {
            length-=1;

            if (s[i-1]!=32)
            {
               word++;// it will let us know the number of word in the given sentence and there should be no whitespaces.
            }
        }
    }
    // counting the number of words in the sentences
    cout <<"The number of the vowels in the string is "<<count<<endl;
    cout <<"The number of consonants in the string is "<<length-count<<endl;
    cout <<"The number of words in the string is "<<word<<endl;
    return 0;
}
