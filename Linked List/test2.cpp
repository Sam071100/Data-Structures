#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll dynamicp[4020][4020];
ll preff[4020];

ll Dfn(ll idx, ll taken, ll n, ll k, vector<ll> &arr)
{
    if (taken >= k and (preff[idx] - taken >= k))
    {
        return 0;
    }
    else if (idx >= n)
    {
        return 1e10;
    }
    else if (dynamicp[idx][taken] != -1)
    {
        return dynamicp[idx][taken];
    }

    ll x1 = Dfn(idx + 1, min(taken + arr[idx], preff[idx] - taken), n, k, arr);
    ll x2 = Dfn(idx + 1, min(preff[idx] - taken + arr[idx], taken), n, k, arr);

    return dynamicp[idx][taken] = 1 + min(x1, x2);
}

ll givemedp(vector<ll> &arr, ll n, ll k)
{
    for (ll i = 0; i < n / 2; i++)
    {
        swap(arr[i], arr[n - i - 1]);
    }
    for (ll i = 0; i <= n + 10; i++)
    {
        preff[i] = 0;
        for (ll j = 0; j <= k + 10; j++)
        {
            dynamicp[i][j] = -1;
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        preff[i] = preff[i - 1] + arr[i - 1];
    }
    ll ans = Dfn(0, 0, n, k, arr);
    return ans > 1e9 ? -1 : ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        ll n, k;
        scanf("%lld %lld", &n, &k);
        vector<ll> arr(n, 0);
        for (ll i = 0; i < n; i++)
        {
            scanf("%lld", &arr[i]);
        }
        sort(arr.begin(), arr.end());
        if (n == 1)
        {
            printf("-1\n");
        }
        else
        {
            printf("%lld\n", givemedp(arr, n, k));
        }
    }
    return 0;
}
