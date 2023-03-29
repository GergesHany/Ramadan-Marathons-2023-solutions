#include <bits/stdc++.h>

using namespace std;

#define fixed(n) fixed << setprecision(n)
#define ceil(n, m) (((n) + (m) - 1) / (m))
#define add_mod(a, b, m) (((a % m) + (b % m)) % m)
#define sub_mod(a, b, m) (((a % m) - (b % m) + m) % m)
#define mul_mod(a, b, m) (((a % m) * (b % m)) % m)
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << (x) << "\n";
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define EPS 1e-9
constexpr int INF = 1 << 30, Mod = 1e9 + 7;
constexpr ll LINF = 1LL << 62;
#define PI acos(-1)
template < typename T = int > using Pair = pair < T, T >;
vector < string > RET = {"NO", "YES"};

template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x : v) in >> x;
    return in;
}

template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) { 
    for (const T &x : v) out << x << ' '; 
    return out;
}

// This program solves a problem using dynamic programming and DFS.
// It takes inputs n and k, and the colors of the nodes.
// It outputs the result of the computation mod Mod.

int n, k;  // n is the number of nodes in the tree, k is the number of colored nodes
vector < int > col;  // vector to store the color of each node
vector < vector < ll > > dp, adj;  // 2D vector for dynamic programming and adjacency list for graph
 
void dfs(int u, int p){
    // Depth-first search to compute dynamic programming values
    for(auto& v : adj[u]){
        if(v == p) continue;  // skip parent node
        dfs(v, u);
        // compute dynamic programming values for each node
        dp[u][1] = (dp[u][1] * (dp[v][2] + dp[v][3])) % Mod;
        dp[u][2] = (dp[u][2] * (dp[v][1] + dp[v][3])) % Mod;
        dp[u][3] = (dp[u][3] * (dp[v][1] + dp[v][2])) % Mod;
    }        
}
 
void Solve(){
    // main function to solve the problem
    cin >> n >> k;
    // initialize vectors for colors, dynamic programming, and adjacency list
    col = vector < int > (n + 5);
    dp = vector < vector < ll > > (n + 5, vector < ll > (4));
    adj = vector < vector < ll > > (n + 5);
    // read input for edges
    for(int i = 0, u, v; i < n - 1 && cin >> u >> v; i++)
        adj[u].push_back(v), adj[v].push_back(u);
    // read input for colors
    for(int i = 0, x, c; i < k && cin >> x >> c; i++)
        col[x] = c;
    // initialize dynamic programming values for each node
    for(int i = 1; i <= n; i++){
        if(col[i]) dp[i][col[i]] = 1;
        else dp[i] = vector < ll > (4, 1);
    }
    // compute dynamic programming values for the tree
    dfs(1, -1);
    // output the result mod Mod
    cout << (dp[1][1] + dp[1][2] + dp[1][3]) % Mod << '\n';
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int test_cases = 1;
    // cin >> test_cases;
    for(int tc = 1; tc <= test_cases; tc++){
        // cout << "Case #" << tc << ": ";
        Solve();
    }
    return 0;
}
