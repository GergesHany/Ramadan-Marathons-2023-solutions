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
typedef unsigned long long ull;
const ll mod = 1e9 + 7, INF = 1LL << 60, N = 2e5 + 9;


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

ll n, m, k;
int group = 1;
vector < ll > adj1[N], adj2[N];
vector < ll > group_1, group_2;


void dfs1(ll u){
  group_1[u] = group;
  for (auto v : adj1[u]){
    if (!group_1[v]){
      dfs1(v);
    }
  }
}

void dfs2(ll u){
  group_2[u] = group;
  for (auto v : adj2[u]){
    if (!group_2[v]){
      dfs2(v);
    }
  }
}

void Accepted(){  
 
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++){
    ll u, v; 
    cin >> u >> v;
    adj1[u].push_back(v);
    adj1[v].push_back(u);
  }

  for (int i = 0; i < k; i++){
    ll u, v; 
    cin >> u >> v;
    adj2[u].push_back(v);
    adj2[v].push_back(u);
  }
  
  group_1.resize(n + 1);
  group_2.resize(n + 1);

  for (int i = 1; i <= n; i++){
    if (!group_1[i]){
      dfs1(i);
      group++;
    }
  }

  group = 1;
  map < pair < int, int >, int > mp;
  
  for (int i = 1; i <= n; i++){
    if (!group_2[i]){
      dfs2(i);
      group++;
    }
    mp[{group_1[i], group_2[i]}]++;
  }

  for (int i = 1; i <= n; i++)
    cout << mp[{group_1[i], group_2[i]}] << " ";

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