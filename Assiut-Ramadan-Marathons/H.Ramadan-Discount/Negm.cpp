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

ll n; cin>>n;

vector<ll>v(n*2),vis(2*n);

for(int i=0;i<2*n;i++){
    cin>>v[i];
}


sort(all(v));

ll last = 0,cnt=0;

for(int i=0;i<2*n;i++){
    if(vis[i]) continue;
    if(cnt == n) break;
    ll x = v[i]*4/3;
    ll l=last,r=2*n-1,ans = -1;
    
    while(l<=r){
        ll mid = l+(r-l)/2;
        if(v[mid]>=x){
            if(v[mid] == x) ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    
    if(ans == -1) continue;
    
    vis[ans] = 1;
    last = ans+1;
    cnt++;
}

for(int i=0;i<2*n;i++){
    if(vis[i]) continue;
        cout<<v[i]<<" ";
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
