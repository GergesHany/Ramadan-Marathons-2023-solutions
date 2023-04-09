#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std; 
using namespace __gnu_pbds;
 
#define EPS 1e-8
#define sz(s) int(s.size())  
#define rall(s)  s.rbegin(), s.rend()
#define TC int t; cin >> t; while(t--)
#define getline(s) getline(cin >> ws, s)
#define all(vec)  vec.begin(),  vec.end()
#define updmin(a, b) a = min((ll)a, (ll)b)
#define updmax(a, b) a = max((ll)a, (ll)b)
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define endd(s) return void(cout << s << "\n")
#define fixed(n) cout << fixed << setprecision(n)
#define ceill(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define cin_2d(vec, n, m) for(int i=0;i<n;i++) for(int j=0;j<m&&cin>>vec[i][j];j++);
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
#define ordered_set tree<ll, null_type, less <ll>, rb_tree_tag,tree_order_statistics_node_update>
#define multi_ordered_set tree<ll, null_type, less_equal <ll>, rb_tree_tag,tree_order_statistics_node_update>
 
typedef long long ll;
typedef long double ld;
const ll N = 5e5 + 100;
const ll mod = 1000000007;
const ll INF = 1LL << 60;
typedef unsigned long long ull;
 
void Gerges_Hany(){
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  #ifndef ONLINE_JUDGE  
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
  #endif
}
 
template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
  for (auto &x : v) in >> x; return in;
}
 
template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v){ 
  for (const T &x : v) out << x << ' '; return out;
}

 
void Accepted(){
 
  ll n, m;
  cin >> n >> m;
  vector < vector < pair < ll, ll > > > adj1(n + 1), adj2(n + 1);
  for (int i = 0; i < m; i++){
    ll u, v;
    cin >> u >> v;
    adj1[u].push_back({v, 1});
    adj1[v].push_back({u, 0});
    adj2[u].push_back({v, 0});
    adj2[v].push_back({u, 1});
  }

  
  ll from, to;
  cin >> from >> to; 
  auto BFS = [&](vector < vector < pair < ll, ll > > > &adj){
    vector < vector < ll > > dist(n + 1, vector < ll > (2, INF));
    dist[from][0] = dist[from][1] = 0;
    queue < pair < ll, ll > > q;
    q.push({from, 0});
    q.push({from, 1});
    while (!q.empty()){
      ll u = q.front().first;
      ll c = q.front().second;
      q.pop();
      for (auto v : adj[u]){
        if (dist[v.first][v.second] > dist[u][c] + 1){
          dist[v.first][v.second] = dist[u][c] + (v.second != c);
          q.push({v.first, v.second});
        }
      }
    }
    return min(dist[to][0], dist[to][1]);
  };

  ll ans = BFS(adj1);
  ans = min(ans, BFS(adj2));
  cout << ans << '\n';

}
 
int main()
{
 
  Gerges_Hany();
  int testcaces = 1, T = 1;
  // cin >> testcaces;
  while (testcaces--){  
    // cout << "Scenario #" << T++ << ": \n";
    Accepted();
  }   
  Time; 
  return 0;
}