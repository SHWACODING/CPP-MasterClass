#include <bits/stdc++.h>

// dpp(arr, val): This defines a macro named dpp && memset(arr, val, size): This is a standard C library function (declared in <cstring>) used to fill a block of memory with a specific value.
#define dpp(arr, val) memset(arr, val, sizeof(arr))
#define ll long long

using namespace std;

const int sz = 1e3 + 1;
const int OO = 0x3f3f3f3f;
const int MAX = 1e6 + 5;

int dis[sz];
bool vis[sz];
vector<int> adj[sz];

int id[MAX], nodes, edges;
pair<ll, pair<int, int> > p[MAX];

bool visited[MAX];
vector<pair<ll, int>> adjac[MAX];

vector<pair<ll, ll>> adjacen[MAX];
ll dist[MAX];
ll parent[MAX];

int dista[1000][1000];

//// ----------------------------------------------------------------------------------------

//// Breadth First Search (BFS) ??

void BFS (int node)
{
    dpp(dis, OO);

    queue<int> q;

    q.push(node);
    dis[node] = 1;

    while (!q.empty()) {
        int p = q.front();
        cout << p << " ";
        q.pop();

        for (int i = 0; i < adj[p].size(); ++i) {
            int ch = adj[p][i];

            if (dis[ch] == OO) {
                dis[ch] = dis[p] + 1;
                q.push(ch);
            }
        }
    }
    cout << endl;
}

//// ----------------------------------------------------------------------------------------

//// https://www.hackerrank.com/challenges/bfsshortreach/problem

void BFS_ShortestReach (int root)
{
    dpp(dis, OO);

    queue<int> q;

    q.push(root);
    dis[root] = 0;

    while (!q.empty()) {
        int p = q.front();
        q.pop();

        for (int i = 0; i < adj[p].size(); ++i) {
            int ch = adj[p][i];

            if (dis[ch] == OO) {
                dis[ch] = dis[p] + 6;
                q.push(ch);
            }
        }
    }
}

//// ----------------------------------------------------------------------------------------

//// Depth First Search (DFS) ??

void DFS (int root)
{
    stack<int> st;

    st.push(root);
    vis[root] = 1;

    while (!st.empty()) {
        int p = st.top();
        cout << p << " ";
        st.pop();

        for (int i = 0; i < adj[p].size(); ++i) {
            int ch = adj[p][i];

            if (!vis[ch]) {
                vis[ch] = 1;
                st.push(ch);
            }
        }
    }

    cout << endl;
}

void R_DFS (int root)
{
    vis[root] = 1;

//    cout << root << " ";

    for (int i = 0; i < adj[root].size(); i++) {
        int ch = adj[root][i];

        if (!vis[ch])
            R_DFS(ch);
    }
}

//// ----------------------------------------------------------------------------------------

//// Minimum Spanning Tree (MST) ??

//// ----- Kruskal's Method -----

void Initialize ()
{
    for (int i = 0; i < MAX; ++i)
        id[i] = i;
}

int Root (int x)
{
    while (id[x] != x) {
        id[x] = id[id[x]]; // Only For Optimization ??
        x = id[x];
    }
    return x;
}

void Union (int x, int y)
{
    int p = Root(x);
    int q = Root(y);

    id[p] = id[q];
}

bool Find_Cycle (int x, int y)
{
    if (Root(x) == Root(y))
        return true;
    return false;
}

ll Kruskal (pair<ll, pair<int, int>> p[])
{
    int x, y;
    ll cost, minimumCost;

    for (int i = 0; i < edges; ++i) {
        // Selecting Edges One By One in an Increasing Order Form The Beginning ??
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first; // cost Here is The => Weight

        // Check If the Selected Edge is Creating a Cycle Or Not ??
        if (!Find_Cycle(x, y)) { // Means That Root(x) != Root(y) ?????
            minimumCost += cost;
            Union(x, y);
        }
    }
    return minimumCost;
}

//// ----- Prim's Method -----

ll Prim (int root)
{
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    ll min_cost = 0;
    pq.push({0, root});

    while (pq.size()) {
        pair<ll, int> p = pq.top();

        int w = p.first;
        int x = p.second;

        pq.pop();

        if (visited[x]) { continue; } // Check Loop ??

        visited[x] = 1;
        min_cost += w;

        for (int i = 0; i < adjac[x].size(); ++i) {
            int y = adjac[x][i].second;

            if (visited[y] == false)
                pq.push(adjac[x][i]);
        }
    }

    return min_cost;
}

//// ----------------------------------------------------------------------------------------

//// Shortest Path Algorithms ??

//// ----- Dijkstra Algorithm -----

void PrintPath (ll node)
{
    if (parent[node] == -1) {
        cout << node + 1 << " ";
        return;
    } else {
        PrintPath(parent[node]);
        cout << node + 1 << " ";
    }
}

void Init ()
{
    for (int i = 0; i < MAX; i++) {
        parent[i] = -1;
        dist[i] = LLONG_MAX;
    }
}

//// ----------------------------------------------------------------------------------------


//// ----------------------------------------------------------------------------------------


//// ----------------------------------------------------------------------------------------


//// ----------------------------------------------------------------------------------------

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

////    Graph Representation ??

//    int n, e; // Number of Nodes && Edges ??
//    cin >> n >> e;
//
//    bool adj_matrix[sz][sz];
//    vector<vector<int>> adj_list(n + 1);
//
//    for (int i = 0; i < e; ++i) {
//        int x, y;
//        cin >> x >> y;
//
//        // Representation of  Undirected Graph ??
//        adj_matrix[x][y] = adj_matrix[y][x] = 1;
//
//        adj_list[x].push_back(y);
//        adj_list[y].push_back(x);
//
////        // Representation of  Directed Graph ??
////        adj_matrix[x][y] = 1;
////        adj_list[x].push_back(y);
//    }
//
//    cout << "Adjacency Matrix : \n";
//    for (int i = 1; i <= n; ++i) {
//
//        for (int j = 1; j <= n; ++j) {
//            cout << adj_matrix[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//    cout << "Adjacency List : \n";
//    for (int i = 1; i < adj_list.size(); ++i) {
//
//        cout << i << " => { ";
//
//        for (int j = 0; j < adj_list[i].size(); ++j) {
//            cout << adj_list[i][j] << " ";
//        }
//        cout << "}\n";
//    }

//// ----------------------------------------------------------------------------------------

//// Breadth First Search (BFS) ??

//    int n, m;
//    cin >> n >> m;
//
//    for (int i = 0; i < m; ++i) {
//        int x, y;
//        cin >> x >> y;
//
//        adj[x].push_back(y);
//        adj[y].push_back(x);
//    }
//
//    int root;
//    cin >> root;
//
//    BFS(root);

//// ----------------------------------------------------------------------------------------

//// https://www.hackerrank.com/challenges/bfsshortreach/problem

//    int q;
//    cin >> q;
//
//    while (q--) {
//        int n, e;
//        cin >> n >> e;
//
//        for (int i = 1; i <= n; ++i) {
//            adj[i].clear();
//        }
//
//        for (int i = 0; i < e; ++i) {
//            int x, y;
//            cin >> x >> y;
//
//            adj[x].push_back(y);
//            adj[y].push_back(x);
//        }
//
//        int root;
//        cin >> root;
//
//        BFS_ShortestReach(root);
//
//        for (int i = 1; i <= n; ++i) {
//            if (i != root) {
//                if (dis[i] == OO)
//                    dis[i] = -1;
//
//                cout << dis[i] << " ";
//            }
//        }
//        cout << endl;
//    }

//// ----------------------------------------------------------------------------------------

//// Depth First Search (DFS) ??

//    int q;
//    cin >> q;
//
//    while (q--)
//    {
//        int n, e;
//        cin >> n >> e;
//
//        for (int i = 0; i < e; ++i)
//            adj[i].clear();
//
//        for (int i = 0; i < e; ++i) {
//            int x, y;
//            cin >> x >> y;
//
//            adj[x].push_back(y);
//            adj[y].push_back(x);
//        }
//
//        int root;
//        cin >> root;
//
////        DFS(root);
//
//        R_DFS(root);
//        cout << endl;
//    }

//// ----------------------------------------------------------------------------------------

//// https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/ ??

//    int n, e;
//    cin >> n >> e;
//
//    for (int i = 0; i < e; ++i)
//        adj[i].clear();
//
//    for (int i = 0; i < e; ++i) {
//        int x, y;
//        cin >> x >> y;
//
//        adj[x].push_back(y);
//        adj[y].push_back(x);
//    }
//
//    int cnt = 0;
//
//    for (int i = 1; i <= n; ++i) {
//        if (!vis[i]) {
//            cnt++;
//            R_DFS(i);
//        }
//    }
//
//    cout << cnt << endl;

//// ----------------------------------------------------------------------------------------

//// Minimum Spanning Tree (MST) ??

//// ----- Kruskal's Method -----

//    ll cost, minimumCost;
//
//    Initialize();
//
//    cin >> nodes >> edges;
//
//    for (int i = 0; i < edges; ++i) {
//        int x, y;
//        ll weight;
//        cin >> x >> y >> weight;
//
//        p[i] = make_pair(weight, make_pair(x, y));
//    }
//
//    // Sort The Edges In The Ascending Order ??
//    sort(p, p + edges);
//    minimumCost = Kruskal(p);
//    cout << minimumCost << endl;

// -------------------------------------------------------

//// ----- Prim's Method -----

//    int nodes, edges;
//    cin >> nodes >> edges;
//
//    for (int i = 0; i < edges; ++i) {
//        int x, y, w;
//        cin >> x >> y >> w;
//
//        adjac[x].push_back({w, y});
//        adjac[y].push_back({w, x});
//    }
//
//    cout << Prim(1);

//// ----------------------------------------------------------------------------------------

//// Shortest Path Algorithms ??

//// ----- Bellman Ford Algorithm -----

//    int n, m;
//    cin >> n >> m;
//
//    for (int i = 0; i < m; ++i) {
//        int from, to, weight;
//        cin >> from >> to >> weight;
//
//        from--, to--;
//
//        adj[i].push_back(from);
//        adj[i].push_back(to);
//        adj[i].push_back(weight);
//    }
//
//    dpp(dis, OO);
//    dis[0] = 0;
//
//    for (int i = 0; i < n - 1; i++) {
//        int j = 0;
//        while (adj[j].size()) {
//            int from = adj[j][0];
//            int to = adj[j][1];
//            int weight = adj[j][2];
//            if ((dis[from] + weight) < dis[to])
//                dis[to] = (dis[from] + weight);
//            j++;
//        }
//    }
//
//    for (int i = 0; i < n; i++)
//        cout << dis[i] << endl;

// --------------------------------------------------------

//// ----- Dijkstra Algorithm -----

//    int n, m;
//    cin >> n >> m;
//
//    for (int i = 0; i < m; i++) {
//        ll x, y, w;
//        cin >> x >> y >> w;
//
//        x--, y--;
//
//        adjacen[x].push_back({y, w});
//        adjacen[y].push_back({x, w});
//    }
//
//    Init();
//
//    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
//
//    ll src = 0;
//    pq.push({0, src});
//    dist[src] = 0;
//
//    while (!pq.empty()) {
//        ll p = pq.top().second;
//        pq.pop();
//
//        if (visited[p]) { continue; }
//
//        visited[p] = 1;
//
//        for (int i = 0; i < adjacen[p].size(); i++) {
//            int ch = adjacen[p][i].first;
//            int w = adjacen[p][i].second;
//
//            if (dist[ch] > (dist[p] + w)) {
//                parent[ch] = p;
//                dist[ch] = dist[p] + w;
//                pq.push({dist[ch], ch});
//            }
//        }
//    }
//
//    if (dist[n - 1] == LLONG_MAX) {
//        cout << -1;
//        return 0;
//    }
//    PrintPath(n - 1);

//// ----- Floyd Warshall Algorithm -----

    int n, m;
    cin >> n >> m;
    dpp(dista, OO);

    for (int i = 0; i < m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;

        dista[x][y] = dista[y][x] = w;
    }

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dista[i][j] = min(dista[i][j], dista[i][k] + dista[k][j]);

    for (int i = 2; i <= n; ++i)
        cout << dista[1][i] << " ";

//// ----------------------------------------------------------------------------------------


//// ----------------------------------------------------------------------------------------


//// ----------------------------------------------------------------------------------------


//// ----------------------------------------------------------------------------------------


//// ----------------------------------------------------------------------------------------


    return 0;
}
