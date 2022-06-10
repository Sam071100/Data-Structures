#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fatafat                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

vector<vector<int>> graph;
vector<bool> vis;
vector<int> parent;
vector<int> disc;
vector<int> low;
vector<bool> ap;
int time1;

void edge(int a, int b)
{
    graph[a].push_back(b);
    graph[b].push_back(a);
}

void dfs(int u, vector<vector<int>> &graph)
{
    int count = 0;
    disc[u] = low[u] = time1;
    time1++;
    vis[u] = true;

    for (int i = 0; i < graph[u].size(); i++)
    {
        int v = graph[u][i];

        if (parent[u] == v)
        {
            continue;
        }
        else if (vis[v] == true)
        {
            low[u] = min(low[u], disc[v]);
        }
        else
        {
            parent[v] = u;
            count++;
            dfs(v, graph);
            low[u] = min(low[u], low[v]);
            if (parent[u] == -1)
            {
                if (count >= 2)
                {
                    ap[u] = true;
                }
            }
            else
            {
                if (low[v] >= disc[u])
                {
                    ap[u] = true;
                }
            }
        }
    }
}

int main()
{
    fatafat int t = 1;
    // cin >>t;
    while (t--)
    {
        int n, e;
        cin >> n >> e;
        vis.assign(n, false);
        graph.assign(n, vector<int>());
        parent.assign(n, -1);
        disc.assign(n, 0);
        low.assign(n, 0);
        ap.assign(n, false);
        time1 = 0;

        int a, b;
        for (int i = 0; i < e; i++)
        {
            cin >> a >> b;
            edge(a, b);
        }

        dfs(0, graph);

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (ap[i] == true)
            {
                ans++;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
