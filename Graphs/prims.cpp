#include <iostream>
using namespace std;
#define I INT_MAX

int cost[8][8] = {{I, I, I, I, I, I, I, I}, {I, I, 25, I, I, I, 5, I}, {I, 25, I, 12, I, I, I, 10}, {I, I, 12, I, 8, I, I, I}, {I, I, I, 8, I, 16, I, 14}, {I, I, I, I, 16, I, 20, 18}, {I, 5, I, I, I, 20, I, I}, {I, I, 10, I, 14, 18, I, I}};
int near[8] = {I, I, I, I, I, I, I, I}; // finds nearer connected vertices
int t[2][6];                            // Stores the min spanning tree

// There can be many MST for a graph if the cost of the edegs are same as then we have the choice to choose the vertices so as to avoid the cycle.

// Prims and Kruskals dono greedy method hai but prims is used to find the MST of single connected component and the time taken is O(v-1 x e).
// Prims works by selecting the min cost edge from the given edges and then it repeats the steps by selecting the min cost edge from the already selected vertices.
//The above step is followed To avoid formation of cycle as MST is a tree and no cycles are allowed. 
// If there is disconnected component then prims algo cannot find the MST for the other component whereas Kruskals algo can find the MST for the other connected components too.
// Prims algo cannot be improved by using min heap as we are selecting the min cost edge originating from the already selected vertices and go on repeating this step until we select v-1 edges out of e edges.

int main()
{
    int i, j, k, u, v, n = 7, min = I;
    // Intial Steps

    for (i = 1; i <= n; i++)
    {
        for (j = i; j <= n; j++)
        {
            if (cost[i][j] < min)
            {
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
    }

    t[0][0] = u;
    t[1][0] = v;

    near[u] = 0;
    near[v] = 0;

    for (i = 1; i <= n; i++)
    {
        if (near[i] != 0)
        {
            if ((cost[i][u] < cost[i][v]))
            {
                near[i] = u;
            }
            else
            {
                near[i] = v;
            }
        }
    }

    // Repeating Steps

    for (i = 1; i < n - 1; i++) // Spanning the MST
    {
        min = I;
        for (j = 1; j <= n; j++)
        {
            if ((near[j] != 0) && (cost[j][near[j]] < min))
            {
                min = cost[j][near[j]];
                k = j;
            }
        }
        t[0][i] = k;
        t[1][i] = near[k];
        near[k] = 0;

        for (j = 1; j <= n; j++)
        {
            if ((near[j] != 0) && (cost[j][k] < cost[j][near[j]]))
            {
                near[j] = k;
            }
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        cout << "(" << t[0][i] << ", " << t[1][i] << ")" << endl;
    }
    return 0;
}
