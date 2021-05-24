#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isSumAvailable(vector<ll> &set, ll n, ll sum) // passing the vector by reference
{

    bool subset[n + 1][sum + 1];

    for (ll i = 0; i <= n; i++)
        subset[i][0] = true;

    for (ll i = 1; i <= sum; i++)
        subset[0][i] = false;

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= sum; j++)
        {
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= set[i - 1])
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]];
        }
    }

    return subset[n][sum];
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll N, K;
        cin >> N >> K;
        ll arr[N];
        ll sum = 0, sum2 = 0, count = 0, sum3 = 0;
        for (ll i = 0; i < N; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        if (sum < 2 * K)
        {
            cout << "-1" << endl;
        }
        else if (sum >= 2 * K)
        {
            sort(arr, arr + N);
            ll i = N - 1, k;
            while (sum2 < 2 * K)
            {
                sum2 += arr[i];
                i--;
                count++;
            }
            k = i;
            i += 1;
            vector<ll> arr2;
            ll j = 0;
            for (j = 0; j < count; j++)
            {
                arr2.push_back(arr[i]);
                // sum3 += arr2[j];
                i++;
            }
            do
            {
                ll sum5=0;
                sum3 = sum2;
                ll sum4 = floor(sum3 / 2);
                while (sum4 <= sum3 - K)
                {
                    if (isSumAvailable(arr2, count, sum4))
                    {
                        cout << count << endl;
                        sum5++;
                        break;
                    }
                    else
                    {
                        sum4++;
                    }
                }
                if (sum5 >0)
                {
                    break;
                }
                else
                {
                    if (k < 0)
                    {
                        cout << "-1" << endl;
                        break;
                    }
                    else
                    {
                        arr2.push_back(arr[k]);
                        sum2 += arr[k];
                        count++;
                        k--;
                    }
                }

            } while (k >= -1);
        }
    }
    return 0;
}
