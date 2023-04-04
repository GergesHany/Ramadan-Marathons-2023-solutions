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

vector<ll> v;
ll n;


bool good(ll x){
    ll sum = 0;
    ll cnt = 0;
    for(auto&i:v){
        if(sum+i<=x) sum+=i;
        else{
            cnt++;
            sum = i;
        }
    }
    if(sum) cnt++;
    return cnt<=n;
}




void solve(){
cin>>n;
string s; getline(s);

ll cnt = 0;
for(auto&i:s){
    if(i==' ' or i=='.') {
        v.push_back(cnt);
        cnt = 0;
    }else cnt++;
}

v.push_back(cnt);

ll l = *max_element(all(v)),r = accumulate(all(v),0ll),ans = 0;
while(l<=r){
    ll mid = l+(r-l)/2;
    if(good(mid)){
        ans = mid;
        r = mid-1;
    }else l = mid+1;
}

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
