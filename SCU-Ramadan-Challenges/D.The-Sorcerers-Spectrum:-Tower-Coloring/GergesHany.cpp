#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std; 
using namespace __gnu_pbds;

#define EPS 1e-8
#define sz(s) (ll)(s.size())  
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
const ll mod = 1e9 + 7;
const ll INF = 1LL << 60;
const int N = 1e5 + 5;
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
 
template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) { 
  for (const T &x : v) out << x << ' '; return out;
}

int n, k;
ll dp[N][4];
vector < int > adj[N];
vector < int > colored(N, -1);

ll dfs(int node, int parent, int color){
  ll &ret = dp[node][color];
  if (ret != -1) return ret;
  ret = 0;
 
  for (ll i = 1; i <= 3; i++){
    if ((~colored[node] && i != colored[node]) || i == color) continue;
    ll mul = 1;
    for (auto child : adj[node]){
      if (child == parent) continue;
      mul *= dfs(child, node, i);
      mul %= mod;
    }
    ret += mul;
    ret %= mod;
  }  

  return ret;
}


void Accepted(){  
 
  cin >> n >> k;
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < n - 1; i++){
    ll u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  while (k--){
    ll node, color;
    cin >> node >> color;
    colored[node] = color;
  }
  
  ll ans = dfs(1, -1, 0);
  cout << ans << "\n";

}

int main()
{ 
  
  Gerges_Hany();
  int testcaces = 1;
  // cin >> testcaces;
  while (testcaces--){  
    // cout << "Case #" << T++ << ": ";
    Accepted();
  }   
  Time;
  return 0;
}