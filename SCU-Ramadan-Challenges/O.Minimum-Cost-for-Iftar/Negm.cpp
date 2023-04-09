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
  int n, m,a,b;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v, 0);
        adj[v].emplace_back(u, 1);
    }
    cin >> a >> b;


    vector<vector<int>> dist(n + 1, vector<int>(2, INT_MAX));
    queue<pair<int,int>> q;
    q.push({a, 0});
    q.push({a, 1});
    dist[a][0] = 0;
    dist[a][1] = 0;
    while(!q.empty()){
        auto [node,color] = q.front();
        q.pop();
        for(auto&[child,c]:adj[node]){
                if(dist[child][c] > dist[node][color] + (c != color)){
                    dist[child][c] = dist[node][color] + (c != color);
                    q.push({child,c});
                }
        } 
    }
    int ans = min(dist[b][0], dist[b][1]);
        cout<<ans<<nl;

   





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
