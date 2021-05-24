#include <iostream>
using namespace std;
// In LeftShift the first element of the array is deleted and each element is shifted one index by the left and the last index is set to 0.
int main()
{
    int n;
    cout << "Enter the size of the String\n";
    cin >> n;
    int arr[n];
    cout << "Enter your string\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
        arr[n-1]=0;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
