#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long int ll;
#define MOD 1000000007
//#define MOD 998244353
#define N 100005
#define INF 1e18
#include <ctime>
#define rep(i, x, n) for (ll i = x; i < n; i++)
#define rev(i, n, x) for (ll i = n; i > x; i--)
#define all(c) (c).begin(), (c).end()
#define int long long int
#ifdef samrat
#define debug(x) cout << " >> " << #x << ": " << x << " ";
#define debugend() cout << endl;
#define print_time() cout << setprecision(6) << "time: " << 1000 * ((clock() - start) / (double)CLOCKS_PER_SEC) << " ms\n";
#else
#define endl "\n"
#define debug(x) ;
#define debugend() ;
#define print_time() ;
#endif
 
clock_t start;
void FAST(int argc)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    start = clock();
    if (argc == 2)
        freopen("std.in", "r", stdin);
}
 
 
/*vector<int> v;
void sieve()
{
    int lp[N + 1] = {}; //lowest prime factor
    for (int i = 2; i <= N; i++)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            v.pb(i);
        }
        for (int j = 0; j < v.size() && v[j] <= lp[i] && i * v[j] <= N; j++)
            lp[i * v[j]] = v[j];
    }
}
 
/*
void prime_factor(int x, vector<int> &r)
{
    int sqrt_x = sqrt(x);
 
    for (int i : v)
    {
        if (i > sqrt_x)
            break;
 
        if (x % i == 0)
            r.pb(i);
 
        while (x % i == 0)
        {
            x /= i;
        }
    }
 
    if (x >= 2)
        r.pb(x);
}
*/
/*
int power(int x, int y)
{
    int res = 1;
    x = x % MOD;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}
*/
/*
inline void dfs(int curr, int prev)
{
 
    for (auto i : a[curr])
        if (i != prev)
            dfs(i, curr);
}
*/
/*
inline int multi(int a, int b)
{
    return ((a * b) % MOD);
}
*/
//---------------------CODE STARTS HERE---------------------
string ny[2]={"NO","YES"};
 
signed main(char argc, char *argv[]) // on my IDE argc is always = 2
{
    FAST(argc);
 
    int testcase = 1;
    // cin >> testcase;
 
    while (testcase--)
    {
        int n;
        cin >> n;
        int a[100005]={};
        int dp[100005]={};
        for (int i = 0; i < n;i++)
        {
            int x;
            cin >> x;
            a[x]++;
        }
        dp[1] = a[1] * 1;
        for (int i = 2; i < N;i++)
            dp[i] = max(dp[i - 2] + a[i] * i,dp[i-1]);
        cout << dp[N - 1] << endl;
 
        //--------??--------CLEAR VECTORS--------??--------
        
    }
 
    //v.clear();
    print_time();
    return 0;
}