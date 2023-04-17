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




void solve(){
  ll n,m; cin>>n>>m;
    vector<ll>adj[n+1];
    for(int i=0;i<m;i++){
        ll u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll>dist(n+1,INT_MAX);
    vector<ll>paths(n+1);
    vector<bool>vis(n+1);
    
    dist[1]=0;
    paths[1]=1;

    queue<ll>q;
    q.push(1);
    vis[1]=1;
    
    
    while(!q.empty()){
        ll u=q.front();
        q.pop();
        for(auto&v:adj[u]){
            if(!vis[v]){
                q.push(v);
                vis[v]=1;
            }
            if(dist[v] > dist[u]+1){
                dist[v] = dist[u]+1;
                paths[v] = paths[u];
            }else if(dist[v] == dist[u]+1){
                paths[v] += paths[u];
                paths[v] %= 1000000007;
            }
        }
    }
    cout<<paths[n]<<nl;


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
