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

// Define a struct to represent a vertex in the graph
struct Vertex {
    int v, type, cost;
    Vertex(int V = 0, int Type = 0, int Cost = 0) {
        v = V, type = Type, cost = Cost;
    }
    // Overload the < operator to enable priority queue operations
    bool operator < (const Vertex &other) const {
        return cost > other.cost;
    }
};

void Solve(){
    // Read input values for number of vertices and edges
    int n, m;
    cin >> n >> m;

    // Define an adjacency list to represent the graph
    vector < vector < Pair < int > > > adj(n + 5);

    // Read input values for edges and build the adjacency list
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, 0});
        adj[v].push_back({u, 1});
    }

    // Read input values for source and destination vertices
    int x, y;
    cin >> x >> y;

    // Define a priority queue to implement Dijkstra's algorithm
    priority_queue < Vertex > dij;

    // Insert the source vertex into the priority queue twice, once for each type
    dij.emplace(x, 0, 0);
    dij.emplace(x, 1, 0);

    // Define a matrix to store distances from the source vertex to other vertices
    vector < vector < int > > dist(n + 5, vector < int > (2, INF));

    // Initialize the distances from the source vertex to itself as 0 for both types
    dist[x][0] = dist[x][1] = 0;

    // Implement Dijkstra's algorithm to find the shortest path from source to destination vertex
    while(!dij.empty()){
        auto [u, t, cost] = dij.top();
        dij.pop();
        for(auto& [v, tt] : adj[u]){
            if(dist[v][tt] > dist[u][t] + (t != tt)){
                dist[v][tt] = dist[u][t] + (t != tt);
                dij.emplace(v, tt, dist[v][tt]);
            }
        }
    }

    // Output the minimum distance from source to destination vertex
    cout << min(dist[y][0], dist[y][1]) << '\n';
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
