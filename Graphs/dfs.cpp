#include <bits/stdc++.h>
using namespace std;

int n = 7; //no of vertices + 1
int visited[7] ={0};


void DFS(int G[][7], int u, int n)
{
    if (visited[u] == 0)
    {
        cout <<u<<" ";
        visited[u] = 1;

        for (int v = 1; v < n; v++)
        {
            if ((G[u][v] == 1) && visited[v] == 0)
            {
                DFS(G, v, n);
            }
        }
    }
}

int main()
{
    // Adjacency matrix
    // Graph with 6 vertices but the size of the matrix is 7*7 bcoz not using the vertex 0
    int G[7][7] = {{0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 0, 0, 0}, {0, 1, 0, 0, 1, 0, 0}, {0, 1, 0, 0, 1, 0, 0}, {0, 0, 1, 1, 0, 1, 1}, {0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0, 0}};

    DFS(G, 4, n);

    return 0;
}
