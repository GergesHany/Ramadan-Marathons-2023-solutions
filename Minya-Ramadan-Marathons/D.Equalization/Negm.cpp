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

const ll mod = 998244353;

vector<ll> divs(ll n){
    vector<ll> v;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            v.push_back(i);
            if(i*i!=n)v.push_back(n/i);
        }
    }
    return v;
}


ll fastpow(ll a, ll b){
    ll res = 1;
    while(b){
        if(b&1)res = (res*a)%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return res;
}



void solve(){
  
  ll n; cin>>n;
  if(n==1){
        cout<<1<<nl;
        return;
  }
    vector<ll>d = divs(n);
    double maxi =0;
    ll ans = 0;
    for(auto&x:d){
        double l = ((double)n/x)*log(x);
        if(l>maxi){
            maxi = l;
            ans = x;
        }
    }
    cout<<fastpow(ans,n/ans)<<nl;

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
