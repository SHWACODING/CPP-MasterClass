#include <iostream>
#include <queue>
#include <stack>
#define V 8 // Vertex in First Graph
#define I 32767 // Infinity
#define Vertex 7 // Vertex in Second Graph
#define E 9 // Edges in Second Graph

using namespace std;

// Breadth First Search (BFS) ??
void BFS (int vtx, int G[][8], int n)
{
    queue<int> Q;
    int visited[8] {0};

    // Initial
    cout << vtx << ", " << flush; // Visit Vertex
    visited[vtx] = 1;
    Q.emplace(vtx);

    // Explore
    while (!Q.empty())
    {
        int u = Q.front(); // Vertex u Of Exploring ?
        Q.pop();

        for (int v = 1; v <= n; ++v) // Adjacent Vertices of Vertex u ?
        {
            if (G[u][v] == 1 && visited[v] == 0) // Adjacent Vertex and Not Visited ?
            {
                cout << v << ", " << flush; // Visit Vertex ?
                visited[v] = 1;
                Q.emplace(v);
            }
        }
    }

    cout << endl;
}

// ***********************************************************************************

// Depth First Search (BFS) Recursively ??
void Recursive_DFS (int u, int G[][8], int n)
{
    static int visited[8] {0};

    if (visited[u] == 0)
    {
        cout << u << ", " << flush;
        visited[u] = 1;

        for (int v = 1; v <= n; ++v)
            if (G[u][v] == 1 && visited[v] == 0)
                Recursive_DFS(v, G, n);
    }
}

// ***************************************************************

// Depth First Search (BFS) Using STL_Stack_C++ ??
void STL_DFS (int u, int G[][8], int n)
{
    // Initialize Visited Tracking Array and Stack
    int visited[8] {0};
    stack<int> stk;
    stk.emplace(u);

    // Visit Start Vertex (u)
    cout << u << ", " << flush;
    visited[u] = 1; // Mark The Visited Vertex With 1 ?

    // Initial Adjacent Vertex ?
    int v = 0;

    while (!stk.empty())
    {
        while (v < n)
        {
            if (G[u][v] == 1 && visited[v] == 0)
            {
                stk.push(u); // Suspend Exploring Current Vertex ?
                u = v; // Update Current Vertex as The Next Adjacent Vertex

                // Visit Current Vertex u
                cout << u << ", " << flush;
                visited[u] = 1;
                v = -1; // Increment Will Make This 0
            }
            v++;
        }
        v = u;  // Can Set v = 0 But Setting v = u Is Better
        u = stk.top();  // Return To Previous Suspended Vertex ?
        stk.pop();
    }
}

// ************* OR *************

// Depth First Search (BFS) Using STL_Stack_C++ But Adds Elements To Stack From The End ??
void End_STL_DFS (int u, int G[][8], int n)
{
    int visited[8] {0};
    stack<int> stk;
    stk.emplace(u);

    while (!stk.empty())
    {
        u = stk.top();
        stk.pop();

        if (visited[u] != 1)
        {
            cout << u << ", " << flush;
            visited[u] = 1;

            for (int v = n-1; v >= 0; v--)
                if (G[u][v] == 1 && visited[v] == 0)
                    stk.emplace(v);
        }
    }
}

// ***********************************************************************************

// $$$$$$$$$$$$$$$$-> Minimum Spanning Tree Functions <-$$$$$$$$$$$$$$$


// 1 ==> Prim Minimum Spanning Tree Function

void PrimsPrintMCST (int T[][V-2], int G[V][V]){
    cout << "\nMinimum Spanning Tree Edges (With Printing cost)\n" << endl;
    int sum {0};
    for (int i {0}; i < V-2; i++){
        int c = G[T[0][i]][T[1][i]];
        cout << "[" << T[0][i] << "]---[" << T[1][i] << "]    ==>  Its cost: " << c << endl;
        sum += c;
    }
    cout << endl;
    cout << "Total cost of MST: " << sum << endl;
}

void PrimsMCST (int G[V][V], int n)
{
    int u;
    int v;
    int mn {I};
    int track[V]; // May Be Called near[V]; Instead ???
    int T[2][V - 2] {0};

    // Initial: Find Min Cost Edge ?
    for (int i {1}; i < V; i++)
    {
        track[i] = I;

        for (int j {i}; j < V; j++)
        {
            if (G[i][j] < mn)
            {
                mn = G[i][j];
                u = i;
                v = j;
            }
        }
    }
    T[0][0] = u;
    T[1][0] = v;
    track[u] = track[v] = 0;

    // Initialize Track Array To Track Min Cost Edge ?
    for (int i {1}; i <  V; i++)
    {
        if (track[i] != 0)
        {
            if (G[i][u] < G[i][v])
                track[i] = u;
            else
                track[i] = v;
        }
    }

    // Repeat ?
    for (int i {1}; i < n-1; i++)
    {
        int k;
        mn = I;

        for (int j {1}; j < V; j++)
        {
            if (track[j] != 0 && G[j][track[j]] < mn)
            {
                k = j;
                mn = G[j][track[j]];
            }
        }

        T[0][i] = k;
        T[1][i] = track[k];
        track[k] = 0;

        // Update Track Array To Track Min Cost Edges ?
        for (int j {1}; j < V; j++)
            if (track[j] != 0 && G[j][k] < G[j][track[j]])
                track[j] = k;
    }

    PrimsPrintMCST(T, G);

}

// ********************************************************************

// 2 ==> Kruskal Minimum Cost Spanning Tree Function ??

void KruskalsPrintMCST (int T[][Vertex - 1], int G[][E]){
    for (int i {0}; i < Vertex - 1; i++){
        cout << "[" << T[0][i] << "]---[" << T[1][i] << "]" << endl;
    }
    cout << endl;
}

// Set Operations :: Union And Find ??
void Union (int u, int v, int s[])
{
    if (s[u] < s[v])
    {
        s[u] += s[v];
        s[v] = u;
    }
    else
    {
        s[v] += s[u];
        s[u] = v;
    }
}

int Find (int u, int s[])
{
    int x = u;
    int v = 0;

    while (s[x] > 0)
        x = s[x];

    while (u != x)
    {
        v = s[u];
        s[u] = x;
        u = v;
    }

    return x;
}

void KruskalsMCST (int G[3][9])
{
    int T[2][Vertex - 1];
    int track[E] {0};
    int my_set[Vertex + 1] = {-1, -1, -1, -1, -1, -1, -1, -1}; // Array For Finding Cycle ?

    int i {0};
    while (i < Vertex - 1)
    {
        int mn = I;
        int u {0};
        int v {0};
        int k {0};

        // Find a Minimum Cost Edge ?
        for (int j {0}; j < E; j++)
        {
            if (track[j] == 0 && G[2][j] < mn)
            {
                mn = G[2][j];
                u = G[0][j];
                v = G[1][j];
                k = j;
            }
        }

        // Check if The Selected Min Cost Edge (u, v) Forming a Cycle or Not ??
        if (Find(u, my_set) != Find(v, my_set))
        {
            T[0][i] = u;
            T[1][i] = v;

            // Perform Union ??
            Union(Find(u, my_set), Find(v, my_set), my_set);
            i++;
        }

        track[k] = 1;
    }

    KruskalsPrintMCST(T, G);
}

// ***********************************************************************************


int main()
{
    int G[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};

// ***********************************************************************************

    cout << "BFS Traversal For (Vertex : 1) ->  " << flush;
    BFS(1, G, 8);

    cout << endl;

    cout << "BFS Traversal For (Vertex : 4) ->  " << flush;
    BFS(4, G, 8);

// ***********************************************************************************

    cout << endl << "###########################################################" << endl << endl;

// ***********************************************************************************

    cout << "Recursive DFS Traversal For (Vertex : 4) ->  " << flush;
    Recursive_DFS(4, G, 8);
    cout << endl << endl;

// ***********************************************************************************

    cout << "STL DFS Traversal For (Vertex : 5) ->  " << flush;
    STL_DFS(5, G, 8);
    cout << endl << endl;

// ***********************************************************************************

    cout << "End_STL_DFS Traversal For (Vertex : 5) ->  " << flush;
    End_STL_DFS(5, G, 8);
    cout << endl;

// ***********************************************************************************

    cout << endl << "###########################################################" << endl;

// ***********************************************************************************

// $$$$$$$$$$$$$$$$-> Minimum Spanning Tree Functions <-$$$$$$$$$$$$$$$

// 1 ==> Prim Minimum Spanning Tree Function

    int cost [V][V] {
            {I, I, I, I, I, I, I, I},
            {I, I, 25, I, I, I, 5, I},
            {I, 25, I, 12, I, I, I, 10},
            {I, I, 12, I, 8, I, I, I},
            {I, I, I, 8, I, 16, I, 14},
            {I, I, I, I, 16, I, 20, 18},
            {I, 5, I, I, I, 20, I, I},
            {I, I, 10, I, 14, 18, I, I},
    };

    int n = sizeof(cost[0]) / sizeof(cost[0][0]) - 1;

    PrimsMCST(cost, n);

// ********************************************************************

    cout << endl << "###########################################################" << endl;

// ********************************************************************

// 2 ==> Kruskal Minimum Cost Spanning Tree Function ??

int edges[3][9] = {{ 1, 1,  2,  2, 3,  4,  4,  5,  5},
                   { 2, 6,  3,  7, 4,  5,  7,  6,  7},
                   {25, 5, 12, 10, 8, 16, 14, 20, 18}};

    KruskalsMCST(edges);

// ***********************************************************************************


    return 0;
}
