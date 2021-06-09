#include <bits/stdc++.h>
using namespace std;
#define fatafat ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define pb push_back

vector<bool> v; // visited array
vector<vector<int>> g; // adjacency list --> can be treated as Array of LinkedList

void edge(int a, int b)
{
    g[a].pb(b);
}

void dfs(int u)
{
    if (!v[u])
    {
        cout <<u<<" ";
        v[u] = true;

        for (auto it = g[u].begin(); it != g[u].end(); it++)
        {
            if (!v[*it])
            {
                dfs(*it);
            }
        }
    }
}

int main()
{
    fatafat
    int t;
    // cin >>t;
    t=1;
    while(t--)
    {
       int n, e;
       cin >>n>>e;

       // Size of the visited vector v and the adjacency list wil be n+1 as we don't want to store the nodes at index 0
       v.assign(n+1, false);
       g.assign(n+1, vector<int>());

       int a, b;
       // a is the current vertex and b is the vertex with which vertex a is having the edge.
       for (int i = 0; i < e; i++)
       {
           cin >>a>>b;
           edge(a,b);
       }
       
       for (int i = 1; i <= n; i++)
       {
           if (!v[i])
           {
               dfs(i);
           }
       }
    }
    return 0;
}
