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

void Solve(){
    // Read the input integer n
    int n;
    cin >> n;
    // Initialize vector a with size n+5 to store the elements
    vector < int > a(n + 5);
    // Read the elements and store them in vector a
    for(int i = 1; i <= n; i++) 
        cin >> a[i];
    // Initialize vector dist with size n+5 to store the distances from node 1 to n
    vector < int > dist(n + 5, INF);
    // Set the distance from node 1 to 1 to be 0
    dist[1] = 0;
    // Initialize a queue bfs and push node 1 into it
    queue < int > bfs;
    bfs.push(1);
    // Use BFS to calculate the shortest path from node 1 to n
    while(!bfs.empty()){
        // Pop the front node u from the queue bfs
        int u = bfs.front();
        bfs.pop();
        // Update the distance from u+1 to 1 if it's shorter
        if(dist[u + 1] > dist[u] + 1 && u != n)
            dist[u + 1] = dist[u] + 1, bfs.push(u + 1);
        // Update the distance from a[u] to 1 if it's shorter
        if(dist[a[u]] > dist[u] + 1)
            dist[a[u]] = dist[u] + 1, bfs.push(a[u]);
    }
    // Output the distance from 1 to n
    cout << dist[n] << '\n';
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
