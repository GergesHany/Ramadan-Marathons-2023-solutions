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
vector<vector<ll>>grid(n,vector<ll>(m));
for(auto&i:grid){
    for(auto&j:i)cin>>j;
}


ll pre_row[n][m],pre_col[m][n],suf_row[n][m],suf_col[m][n];





for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(j==0) pre_row[i][j] = grid[i][j];
        else pre_row[i][j] = lcm(pre_row[i][j-1],grid[i][j]);

        if(i==0) pre_col[j][i] = grid[i][j];
        else pre_col[j][i] = lcm(pre_col[j][i-1],grid[i][j]);
    }
}

for(int i=n-1;i>=0;i--){
    for(int j=m-1;j>=0;j--){
        if(j==m-1) suf_row[i][j] = grid[i][j];
        else suf_row[i][j] = lcm(suf_row[i][j+1],grid[i][j]);

        if(i==n-1) suf_col[j][i] = grid[i][j];
        else suf_col[j][i] = lcm(suf_col[j][i+1],grid[i][j]);
    }
}


ll ans = 0;

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        ll newrow,newcol;
        if(j==0) newrow = suf_row[i][j+1];
        else if(j==m-1) newrow = pre_row[i][j-1];
        else newrow = lcm(pre_row[i][j-1],suf_row[i][j+1]);

        if(i==0) newcol = suf_col[j][i+1];
        else if(i==n-1) newcol = pre_col[j][i-1];
        else newcol = lcm(pre_col[j][i-1],suf_col[j][i+1]);

        ll l = lcm(newrow,newcol);
        ll old = lcm(suf_row[i][0],suf_col[j][0]);
        if(l==old) ans++;    
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
