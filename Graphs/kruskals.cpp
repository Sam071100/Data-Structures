#include <iostream>
using namespace std;
#define I INT_MAX

int set[8] = {-1,-1,-1,-1,-1,-1,-1,-1};

// Kruskals and prims both are greedy algorithm for finding the Minimum spanning tree of the graph.
// Kruskals works by selecting the min cost edge among all the edges and cycle is avoided by using the disjoint set union method.
// So the time complexity of this algo is O(v-1 x e) as we are selecting v-1 edges out of e edges.
// This can be further improved by using min heap as in every iteration we are selecting the min cost edge among all the edges.
// So if we use min heap to find the next min cost edge then the time complexity can be reduced to O(v-1 * log e)
// While selecting the min cost edge we use the concept of weighted union and collapsing find to detect the formation of cycle and avoid the selection of that particular edge.
// In prim’s algorithm, graph must be a connected graph while the Kruskal’s can function on disconnected graphs too and can find the MST for that respective graph.
// The main difference between Prims and Kruskals is of time complexity that is 
// IN prims algo -->It traverses one node more than one time to get the minimum distance. IN kruskal algo --->	It traverses one node only once.
// Prim’s algorithm runs faster in dense graphs.     Kruskal’s algorithm runs faster in sparse graphs.
// Prim’s algorithm uses List Data Structure.	Kruskal’s algorithm uses Heap Data Structure.

void myunion(int u, int v)
{
    if (set[u] < set[v])
    {
        set[u] = set[u] + set[v];
        set[v] = u;
    }
    else
    {
        set[v] = set[u] + set[v];
        set[u] = v;
    }
}

// Collapsing find for directly connecting the vertices to the parent node
int find(int u)
{
    int x=u, v=0;
    while (set[x] > 0)   
    {
        x =  set[x];
    }
    while (u!=x)
    {
        v = set[u];
        set[u]=x;
        u=v;
    }
    return x;
}

int edges[3][9] = {{1,1,2,2,3,4,4,5,5}, {2,6,3,7,4,5,7,6,7}, {25,5,12,10,8,16,14,20,18}};

int included[9] = {0};
int t[2][6]; // Stores the MST


int main()
{
    int i = 0, j, k, u, v, min = I, n = 7, e = 9;
    while (i < n-1)
    {
        min = I;
        for ( j = 0; j < e; j++)
        {
            if ((included[j]==0) && (edges[2][j] < min))
            {
                min = edges[2][j];
                u = edges[0][j];
                v = edges[1][j];
                k = j;
            }
        }
        if (find(u) != find(v))
        {
            t[0][i] = u;
            t[1][i] = v;
            myunion(find(u), find(v));
            i++;
        }
        included[k] = 1;
    }
    
     for (int i = 0; i < n - 1; i++)
    {
        cout << "(" << t[0][i] << ", " << t[1][i] << ")" << endl;
    }
    return 0;
}
