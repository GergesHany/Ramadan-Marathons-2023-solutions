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
int n; cin>>n;
vector<int> v(n+1);
for(int i=1;i<=n;i++) cin>>v[i];

vector<vector<int>>adj(n+1);
for(int i=1;i<=n;i++){
    if(i != v[i] and v[i] != 1)
        adj[i].push_back(v[i]);
    if(i+1<=n)
        adj[i].push_back(i+1);
}


ll cnt = 1;
queue<int>q;
q.push(1);
vector<bool>vis(n+1);
vis[1] = 1;
while(!q.empty()){
    int sz = q.size();
    while(sz--){
        int node = q.front();
        q.pop();
        for(auto child:adj[node]){
            if(child == n){
                cout<<cnt<<nl;
                return;
            }
            if(!vis[child]){
                vis[child] = 1;
                q.push(child);
            }
        }
    }
    cnt++;
}


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
