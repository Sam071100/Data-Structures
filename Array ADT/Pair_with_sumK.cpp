#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Here n is the size of the array and k is the sum of pair of the elements in the array.
    int n, *m, k;
    cin >> n >> k; // Size of the array
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    m = max_element(arr, arr + n);
    int H[*m + 1] = {0}; // Array for hashing
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < k)
        {
            if (H[k - arr[i]] != 0)
            {
                cout << arr[i] << " + " << k - arr[i] << " = " << k << endl;
            }
            H[arr[i]]++;
        }
    }

    return 0;
}
