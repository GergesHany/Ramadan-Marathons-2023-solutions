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



const int N = 1e6+5;
ll fact[N], invfact[N];
const ll mod = 1e9+7;
ll fast_pow(ll a, ll b){
    ll res = 1;
    while(b){
        if(b&1) res = (res*a)%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return res;
}
void pre(){
    fact[0] = 1;
    invfact[0] = 1;
    for(int i = 1; i < N; i++){
        fact[i] = (fact[i-1]*i)%mod;
        invfact[i] = fast_pow(fact[i], mod-2);
    }
}
ll nCr(int n, int r){
    if(r>n) return 0;
    ll res = fact[n];
    res = (res*invfact[r])%mod;
    res = (res*invfact[n-r])%mod;
    return res;
}


void solve(){
ll n,k; cin>>n>>k;

ll ans = 0;
for(int i=1;i<=n;i++){
    if(i>k) break;
    ans+=nCr(k,i);
    ans%=mod;
}
cout<<ans<<nl;



}
 
int main(){
    Fast_IO();
pre();
int t =1; 
cin>>t;
while(t--){
solve();
}
return 0;
}  
