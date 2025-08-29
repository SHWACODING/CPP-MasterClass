#include <bits/stdc++.h>

#define dpp(arr, val) memset(arr, val, sizeof(arr))

typedef long long ll;

using namespace std;

const int OO = 0x3f3f3f3f;
const int sz = 1e3 + 10;
ll dp[sz];

// ------------------------------------------------------------------------------------

//// Fibonacci Problem Without Using DP ??
//ll Fib (int n)
//{
//    if (n == 0 || n == 1)
//        return n;
//
//    return fib(n - 1) + fib (n - 2);
//}

ll DP_Fib (int n)
{
    if (n == 0 || n == 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    // This Line For Saving The Values of Tree Of Recursion To Save From Repeating
    // And This is the Main Benefit of DP ??
    dp[n] = DP_Fib(n - 1) + DP_Fib(n - 2);

    return dp[n];
}

// ------------------------------------------------------------------------------------

//// https://www.spoj.com/problems/FARIDA/

ll arr[sz];
ll f;

ll PrincessFarida (int i)
{
    if (i >= f) { return 0; }

    if (dp[i] != -1) { return dp[i]; }

    dp[i] = max(PrincessFarida(i + 1), PrincessFarida(i + 2) + arr[i]);

    return dp[i];
}

// ------------------------------------------------------------------------------------

//// https://atcoder.jp/contests/dp/tasks/dp_a

vector<int> h1;
int fr1;
int dpfr1[sz];

int Frog1 (int i)
{
    if (i == fr1 - 1) { return 0; } // Reach The End ??

    if (dpfr1[i] != -1) { return dpfr1[i]; }

    dpfr1[i] = 1e9;

    dpfr1[i] = min(Frog1(i + 1) + abs(h1[i + 1] - h1[i]), dpfr1[i]);

    if (i + 2 <= fr1 - 1)
        dpfr1[i] = min(Frog1(i + 2) + abs(h1[i + 2] - h1[i]), dpfr1[i]);

    return dpfr1[i];
}

// ------------------------------------------------------------------------------------

//// https://atcoder.jp/contests/dp/tasks/dp_b

vector<int> h2;
int fr2;
int k;
int dpfr2[sz];

int Frog2 (int i)
{
    if (i == fr2 - 1) { return 0; }

    if (dpfr2[i] != -1) { return dpfr2[i]; }

    dpfr2[i] = 1e9;

    for (int j = 1; j <= k; ++j)
        if (i + j <= fr2 - 1)
            dpfr2[i] = min (dpfr2[i], Frog2(i + j) + abs(h2[i] - h2[i + j]));

    return dpfr2[i];
}

// ------------------------------------------------------------------------------------

//// https://atcoder.jp/contests/dp/tasks/dp_c

int vac;
ll dpvac[sz][3];
vector<ll> a, b, c;

int Vacation (int i, int j)
{
    if (i == vac) return 0;

    if (dpvac[i][j] != -1) return dpvac[i][j];

    if (j == 0)
        dpvac[i][j] = max(Vacation(i + 1, 1) + b[i], Vacation(i + 1, 2) + c[i]);

    if (j == 1)
        dpvac[i][j] = max(Vacation(i + 1, 0) + a[i], Vacation(i + 1, 2) + c[i]);

    if (j == 2)
        dpvac[i][j] = max(Vacation(i + 1, 0) + a[i], Vacation(i + 1, 1) + b[i]);

    return dpvac[i][j];
}

// ------------------------------------------------------------------------------------

//// https://atcoder.jp/contests/dp/tasks/dp_d

ll nap1, W1;
ll dpnap1[110][sz] ;
vector<ll> Value1, Weight1;

ll Knapsack1 (ll i, ll j)
{
    if (i == nap1 || j == W1)
        return 0;

    if (dpnap1[i][j] != -1) { return dpnap1[i][j]; }

    dpnap1[i][j] = max(dpnap1[i][j], Knapsack1(i + 1, j));

    if (j + Weight1[i] <= W1)
        dpnap1[i][j] = max(dpnap1[i][j], Knapsack1(i+1, j + Weight1[i]) + Value1[i]);

    return dpnap1[i][j];
}

// ------------------------------------------------------------------------------------

//// https://atcoder.jp/contests/dp/tasks/dp_e

ll nap2, W2;
vector<ll> Value2, Weight2;
ll dpnap2[101][sz];

ll Knapsack2 (int i, int V)
{
    if (i == nap2) {
        if (!V) { return 0; }
        else { return 1e9; }
    }

    ll &ret = dpnap2[i][V];

//    if(ret != -1){return ret;} // ====
    if (~ret) return ret;

    ret = OO;

    ret = Knapsack2(i + 1, V);

    if (V - Value2[i] >= 0)
        ret = min(ret, Knapsack2(i + 1, V - Value2[i]) + Weight2[i]);

    return ret;
}

// ------------------------------------------------------------------------------------

//// https://atcoder.jp/contests/dp/tasks/dp_f

int dplcs[3001][3001];

string s, t;
int ss, tt;

int LCS (int i, int j)
{
    if (i == ss || j == tt)
        return 0;

    int &ret = dplcs[i][j];

//    if(ret != -1){return ret;} // ====
    if (~ret) return ret;

    ret = -OO;

    if (s[i] == t[j])
        ret = max(ret, LCS(i + 1, j + 1) + 1);
    else {
        ret = max(ret, LCS(i, j + 1));
        ret = max(ret, LCS(i + 1, j));
    }

    return ret;
}

void PrintLCS(int i, int j)
{
    if (i == ss || j == tt){ return; }

    int ret = dplcs[i][j];

    if (s[i] == t[j]) {
        if (ret == LCS(i+1, j+1) + 1) {
            cout << s[i];
            PrintLCS(i+1, j+1); return;
        }
    }
    else {
        if(ret == LCS(i, j+1)) { PrintLCS(i, j+1); return; }
        if(ret == LCS(i+1, j)) { PrintLCS(i+1, j); return; }
    }

    return;
}

// ------------------------------------------------------------------------------------

//// https://atcoder.jp/contests/dp/tasks/dp_g

vector<int> adj[sz];
int dplp[sz];

int LongestPath(int node)
{
    if (adj[node].size() == 0) { return 0; } // Empty Graph ??

    int &ret = dplp[node];

//    if(ret != -1){return ret;} // ====
    if (~ret){return ret;}

    ret = -OO;

    for (int i = 0; i < adj[node].size(); i++)
        ret = max(ret, LongestPath(adj[node][i]) + 1);

    return ret;
}

// ------------------------------------------------------------------------------------

//// https://atcoder.jp/contests/dp/tasks/dp_h

int dpgrid[sz][sz];

char grid[sz][sz];

int u, r;

int add(int a, int b, int M)
{
    return (a % M + b % M) % M;
}

int Grid(int i, int j)
{
    if (i == u-1 && j == r-1)
        return 1;

    int &ret = dpgrid[i][j];

//    if(ret != -1){return ret;} // ====
    if(~ret) { return ret; }

    ret=0;

    if(i + 1 <= u-1 && grid[i+1][j] == '.')
        ret = add(ret, Grid(i+1, j), 1e9+7);

    if(j + 1 <= r-1 && grid[i][j+1] == '.')
        ret = add(ret, Grid(i, j+1), 1e9+7);

    return ret;
}

// ------------------------------------------------------------------------------------

//// https://atcoder.jp/contests/dp/tasks/dp_i

const int coins_sz = 3e3 + 1;

double dpcoins[coins_sz][coins_sz];

vector<double> coins;

int co;

double Coins(int i,int heads)
{
    if (i == co)
        return (heads > (co / 2));

    double &ret = dpcoins[i][heads];

    if(ret != -1){return ret;}

    ret = Coins(i+1, heads+1) * coins[i] + Coins(i+1, heads) * (1 - coins[i]);

    return ret;
}


// ------------------------------------------------------------------------------------


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//// Fibonacci Recursive DP ??

//    int n;
//    cin >> n;
//
//    dpp (dp, -1); // Initialize all dp[] values to -1 ??
//
//    cout << DP_Fib(n) << endl;

// -------------------------------------------------------

//    // Fibonacci Iterative DP ??
//    dpp(dp, -1);
//    dp[0] = 0; // Handle 0, 1 (Base Cases) ??
//    dp[1] = 1;
//
//    for (int i = 2; i <= n; ++i)
//        dp[i] = dp[i - 1] + dp[i - 2];
//
//    cout << dp[n] << endl;

// ------------------------------------------------------------------------------------

//// https://www.spoj.com/problems/FARIDA/

//    // DP Recursive Code ??
//    int T;
//    cin >> T;
//    int k = 1;
//
//    while (T--) {
//        dpp (dp, -1);
//
//        cin >> f;
//
//        for (int i = 0; i < f; ++i) {
//            cin >> arr[i];
//        }
//
//        cout << "Case " << k++ << ": " << PrincessFarida(0) << endl;
//    }

// -----------------------------------------------------

//    // DP Iterative Code ??
//    int T;
//    cin >> T;
//
//    int k = 1;
//
//    while (T--) {
//        cin >> f;
//        for (int i = 0; i< f; ++i)
//            cin >> arr[i];
//
//        dpp(dp, -1);
//        dp[f] = 0;
//
//        for (ll i = f - 1; i >= 0; --i) {
//            dp[i] = max(dp[i], dp[min(i + 1, f)]);
//            dp[i] = max(dp[i], dp[min(i + 2, f)] + arr[i]);
//        }
//
//        cout << "Case " << k++ << ": " << dp[0] << endl;
//    }

// ------------------------------------------------------------------------------------

//// https://atcoder.jp/contests/dp/tasks/dp_a

//    // DP Recursive Code ??
//    cin >> fr1;
//    for (int i = 0; i < fr1; ++i) {
//        cin >> h1[i];
//    }
//
//    dpp(dpfr1, -1);
//
//    cout << Frog1(0) << endl;

// -----------------------------------------

//    // DP Iterative Code ??
//    cin >> fr1;
//
//    for (int i = 0; i < fr1; ++i) {
//        int x;
//        cin >> x;
//        h1.push_back(x);
//    }
//
//    dpp(dpfr1, OO);
//
//    dpfr1[fr1 - 1] = 0;
//
//    for (int i = fr1 - 2; i >= 0; --i) {
//        dpfr1[i] = min(dpfr1[i], dpfr1[i + 1] + abs(h1[i + 1] - h1[i]));
//
//        if (i + 2 <= fr1)
//            dpfr1[i] = min(dpfr1[i], dpfr1[i + 2] + abs(h1[i + 2] - h1[i]));
//    }
//
//    cout << dpfr1[0] << endl;

// ------------------------------------------------------------------------------------

//// https://atcoder.jp/contests/dp/tasks/dp_b

//    // DP Recursive Code ??
//    cin >> fr2 >> k;
//    for (int i = 0; i < fr2; ++i) {
//        int x;
//        cin >> x;
//        h2.push_back(x);
//    }
//
//    dpp(dpfr2, -1);
//
//    cout << Frog2(0) << endl;

// -----------------------------------------

//    // DP Iterative Code ??
//    cin >> fr2 >> k;
//
//    for (int i = 0; i < fr2; ++i) {
//        int x;
//        cin >> x;
//        h2.push_back(x);
//    }
//
//    dpp(dpfr2, OO);
//
//    dpfr2[fr2 - 1] = 0;
//
//    for (int i = fr2 - 2; i >= 0; --i) {
//        dpfr2[i] = min(dpfr2[i], dpfr2[i + 1] + abs(h2[i + 1] - h2[i]));
//
//        for (int j = 1; j <= k; ++j)
//            if (i + j <= fr2)
//                dpfr2[i] = min(dpfr2[i], dpfr2[i + j] + abs(h2[i + j] - h2[i]));
//    }
//
//    cout << dpfr2[0] << endl;

// ------------------------------------------------------------------------------------

//// https://atcoder.jp/contests/dp/tasks/dp_c

//    // DP Recursive Code ??
//    cin >> vac;
//
//    for (int i = 0; i < vac; ++i) {
//        int x, y, z;
//        cin >> x >> y >> z;
//
//        a.push_back(x);
//        b.push_back(y);
//        c.push_back(z);
//    }
//
//    dpp(dpvac, -1);
//
//    cout << max(max(Vacation(0, 0), Vacation(0, 1)), Vacation(0, 2));

// -----------------------------------------

//    // DP Iterative Code ??
//    cin >> vac;
//
//    for (int i = 0; i < vac; ++i) {
//        ll x, y, z;
//        cin >> x >> y >> z;
//
//        a.push_back(x);
//        b.push_back(y);
//        c.push_back(z);
//    }
//
//    dpp(dpvac, 0);
//
//    for (int j = 0; j < 3; ++j)
//        dpvac[vac][j] = 0;
//
//    for (int i = vac - 1; i >= 0; --i) {
//        for (int j = 0; j < 3; ++j) {
//            if (j == 0) {
//                dpvac[i][j] = max(dpvac[i][j], dpvac[i + 1][1] + b[i]);
//                dpvac[i][j] = max(dpvac[i][j], dpvac[i + 1][2] + c[i]);
//            }
//
//            if (j == 1) {
//                dpvac[i][j] = max(dpvac[i][j], dpvac[i + 1][0] + a[i]);
//                dpvac[i][j] = max(dpvac[i][j], dpvac[i + 1][2] + c[i]);
//            }
//
//            if (j == 2) {
//                dpvac[i][j] = max(dpvac[i][j], dpvac[i + 1][0] + a[i]);
//                dpvac[i][j] = max(dpvac[i][j], dpvac[i + 1][1] + b[i]);
//            }
//        }
//    }
//
//    cout << max(max(dpvac[0][0], dpvac[0][1]), dpvac[0][2]) << endl;

// ------------------------------------------------------------------------------------

//// https://atcoder.jp/contests/dp/tasks/dp_d

//    // DP Recursive Code ??
//    cin >> nap1 >> W1;
//
//    for (int i = 0; i < nap1; ++i) {
//        ll wi, vi;
//        cin >> wi >> vi;
//
//        Weight1.push_back(wi);
//        Value1.push_back(vi);
//    }
//
//    dpp(dpnap1, -1);
//
//    cout << Knapsack1(0, 0) << endl;

// -----------------------------------------

//    // DP Iterative Code ??
//    cin >> nap1 >> W1;
//
//    for (int i = 0; i < nap1; ++i) {
//        ll wi, vi;
//        cin >> wi >> vi;
//
//        Weight1.push_back(wi);
//        Value1.push_back(vi);
//    }
//
//    ll dpnap11[nap1 + 10][W1 + 10];
//
//    dpp(dpnap11, 0);
//
//    for (int i = 0; i < nap1; i++) {
//        for (int j = 0; j <= W1; j++) {
//            if (i == nap1 || j == W1){
//                dpnap11[i][j] = 0;
//            }
//        }
//    }
//
//    for (int i = nap1 - 1; i >= 0; i--) {
//        for (int j = W1 - 1 ; j >= 0; j--) {
//           dpnap11[i][j] = max(dpnap11[i][j], dpnap11[i + 1][j]);
//
//           if (j + Weight1[i] <= W1)
//            dpnap11[i][j] = max(dpnap11[i][j], dpnap11[i + 1][j + Weight1[i]] + Value1[i]);
//        }
//    }
//
//    cout << dpnap11[0][0] << endl;

// ------------------------------------------------------------------------------------

//// https://atcoder.jp/contests/dp/tasks/dp_e

//    // DP Recursive Code ??
//    cin >> nap2 >> W2;
//
//    ll sum = 0;
//
//    for (int i = 0; i < nap2; ++i) {
//        ll wi, vi;
//        cin >> wi >> vi;
//
//        Weight2.push_back(wi);
//        Value2.push_back(vi);
//
//        sum += vi;
//    }
//
//    dpp(dpnap2, -1);
//
//    int ans = 0;
//    for (int i = sum; i >= 0; i--) {
//        if (Knapsack2(0, i) <= W2) {
//            ans = i;
//            break;
//        }
//    }
//
//    cout << ans << endl;

// -----------------------------------------

    // DP Iterative Code ??


// ------------------------------------------------------------------------------------

//// https://atcoder.jp/contests/dp/tasks/dp_f

//    // DP Recursive Code ??
//    cin >> s >> t;
//
//    ss = s.size();
//    tt = t.size();
//
//    dpp(dplcs, -1);
//
//    LCS(0, 0);
//
//    PrintLCS(0, 0);

// -----------------------------------------

    // DP Iterative Code ??

// ------------------------------------------------------------------------------------

//// https://atcoder.jp/contests/dp/tasks/dp_g

//    // DP Recursive Code ??
//    int n, m;
//    cin >> n >> m;
//
//    for (int i = 0; i < m; i++)
//    {
//        int x, y;
//        cin >> x >> y;
//        adj[x].push_back(y); // Directed Graph ??
//    }
//
//    dpp(dplp, -1);
//
//    int ans = 0;
//
//    for (int i = 1; i <= n; i++)
//       ans = max(ans, LongestPath(i));
//
//    cout << ans << endl;

// -----------------------------------------
    // DP Iterative Code ??


// ------------------------------------------------------------------------------------

//// https://atcoder.jp/contests/dp/tasks/dp_h

//    // DP Recursive Code ??
//    cin >> u >> r;
//
//    for (int i = 0; i < u; i++)
//        for (int j = 0; j < r; j++)
//            cin >> grid[i][j];
//
//    dpp(dpgrid, -1);
//
//    cout << Grid(0, 0);

// -----------------------------------------

    // DP Iterative Code ??

// ------------------------------------------------------------------------------------

//// https://atcoder.jp/contests/dp/tasks/dp_i

    // DP Recursive Code ??
    cin >> co;
    for (int i = 0; i < co; i++) {
        double x;
        cin >> x;
        coins.push_back(x);
    }

    for (int i = 0; i < co; i++)
        for (int j = 0; j < co; j++)
            dpcoins[i][j] = -1;

    cout << setprecision(10) << Coins(0,0);

// -----------------------------------------

    // DP Iterative Code ??


// ------------------------------------------------------------------------------------


    return 0;
}
