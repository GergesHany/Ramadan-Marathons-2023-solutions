#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define OO 2'000'000'000
#define ull unsigned long long
#define nl '\n'
#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define rall(s)  s.rbegin(), s.rend()
#define getline(s) getline(cin>>ws,s)
#define ceill(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define pi  3.141592653589793
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define multi_ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

 
void Fast_IO(){
ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
// freopen("filename.in", "r", stdin);
// freopen("filename.txt", "w", stdout);
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#endif
}




int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

ll n,k;
vector<vector<ll>>adj;

ll dp[100005][4];
vector<ll>paint;
const ll mod = 1e9 + 7;
void dfs(ll u,ll p){
    if(paint[u]) dp[u][paint[u]] = 1;
    else{
        dp[u][1] = dp[u][2] = dp[u][3] = 1;
    }
    if(paint[p]) dp[u][paint[p]] = 0;

  for(auto &v:adj[u]){
    if(v==p)continue;
    
    if(paint[v] && paint[v] == paint[u]){
        cout<<0<<nl;
        exit(0);
    }
    
    dfs(v,u);
    if(paint[u]){
        dp[u][paint[u]] *= (dp[v][1] + dp[v][2] + dp[v][3] - dp[v][paint[u]]);
        dp[u][paint[u]] %= mod;
        continue;
    }

    if(paint[u] == 0){
        dp[u][1] = (dp[u][1] * (dp[v][2] + dp[v][3])) % mod;
        dp[u][2] = (dp[u][2] * (dp[v][1] + dp[v][3])) % mod;
        dp[u][3] = (dp[u][3] * (dp[v][1] + dp[v][2])) % mod;
    }
  }
}



void solve(){
  cin>>n>>k;
  paint = vector<ll>(n+1);
  adj = vector<vector<ll>>(n+1);
  for(int i=1;i<n;i++){
    ll u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i=0;i<k;i++){
    ll x,c; cin>>x>>c;
    paint[x] = c;
  }
    
    dfs(1,0);

    cout<<(dp[1][1] + dp[1][2] + dp[1][3]) % mod;




}
 
int main(){
    Fast_IO();
int t =1; 
//cin>>t;
while(t--){
solve();
}
return 0;
}  
