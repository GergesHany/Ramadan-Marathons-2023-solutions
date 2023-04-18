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
int n,m; cin>>n>>m;
vector<vector<ll>> grid(n,vector<ll>(n));
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>grid[i][j];
    }
}

for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(i==0 && j==0) continue;
        if(i==0) grid[i][j]+=grid[i][j-1];
        else if(j==0) grid[i][j]+=grid[i-1][j];
        else grid[i][j]+=grid[i-1][j]+grid[i][j-1]-grid[i-1][j-1];
    }
}


ll ans = -1e15;

for(int i=0;i+m-1<n;i++){
    for(int j=0;j+m-1<n;j++){
        ll sum = grid[i+m-1][j+m-1];
        if(i>0) sum-=grid[i-1][j+m-1];
        if(j>0) sum-=grid[i+m-1][j-1];
        if(i>0 && j>0) sum+=grid[i-1][j-1];
        ans = ans>sum?ans:sum;
    }
}

cout<<ans<<nl;




}
 
int main(){
    Fast_IO();
int t =1; 
cin>>t;
while(t--){
solve();
}
return 0;
}  
