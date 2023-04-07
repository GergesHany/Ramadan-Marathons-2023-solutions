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
    vector<ll> v(n+1);
    
    for(int i=1;i<=n;i++) cin>>v[i];
    int maxi =0,cnt = 0,prev = 0;
    for(int i=1;i<=n;i++){
        if(v[i]==v[i-1]) cnt++;
        else{
            if(prev) maxi = max(maxi,2*min(prev,cnt));
            maxi = max(maxi,cnt-(cnt&1));
            prev = cnt;
            cnt = 1;
        }
    }
    if(prev) maxi = max(maxi,2*min(prev,cnt));
    maxi = max(maxi,cnt-(cnt&1));
    cout<<maxi<<nl;


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
