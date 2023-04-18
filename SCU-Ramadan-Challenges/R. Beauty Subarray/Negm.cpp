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


ll n,x;
vector<ll> a;
vector<vector<ll>>dp;


ll rec(ll idx,ll cnt){
    if(idx == n or cnt == 4) return 0;
    ll &ret = dp[idx][cnt];
    if(~ret) return ret;

    ll ans1 = 0;
    if(cnt == 0) ans1 = rec(idx+1,0);
    if(cnt == 1 or cnt == 3) ans1 = rec(idx+1,cnt)+a[idx];
    if(cnt == 2) ans1 = rec(idx+1,2)+a[idx]/x;

    ll ans2 = rec(idx,cnt+1);
    return ret = max(ans1,ans2);
}



void solve(){
    cin>>n>>x;
    a = vector<ll>(n);
    for(int i=0;i<n;i++) cin>>a[i];
    dp = vector<vector<ll>>(n,vector<ll>(5,-1));
    cout<<rec(0,0)<<nl;
  




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
