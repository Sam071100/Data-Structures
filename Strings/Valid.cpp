#include <iostream>
using namespace std;

int valid(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (!(s[i] >= 65 && s[i] <= 90) || !(s[i] >= 97 && s[i] <= 112) || !(s[i] >= 48 && s[i] <= 57))
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    string s;
    getline(cin, s);
    if (valid(s))
    {
        cout << "The String is valid\n";
    }
    else
    {
        cout << "The String is not valid\n";
    }

    return 0;
}
