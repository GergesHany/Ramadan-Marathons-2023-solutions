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


vector<ll>primes;
vector<bool>isprime(150);
void sieve(){
    isprime[0] = isprime[1] = 1;
    for(ll i = 2; i < 150; i++){
        if(!isprime[i]){
            primes.push_back(i);
            for(ll j = i*i; j < 150; j += i){
                isprime[j] = 1;
            }
        }
    }
}


ll power_of_prime(ll n, ll p){
    ll ans = 0;
    while(n){
        ans += n/p;
        n /= p;
    }
    return ans;
}

vector<ll>divs(120);


void init(){
    for(ll i=1;i<=110;i++){
        ll ans = 1;
        for(auto&p:primes){
        ll x = power_of_prime(i,p);
        if(!x)break;
        ans *= (x+1);
        }
        divs[i] = ans;
    }
}



void solve(){

 ll n; cin>>n;

ll l = 1, r = 110,ans = -1;
while(l<=r){
    ll mid = l+(r-l)/2;
    if(divs[mid] >= n){
        if(divs[mid]==n) ans = mid;
        r = mid-1;
    }
    else l = mid+1;
}

if(ans == -1) cout<<"Ramaden Kareem Ya Amoor"<<nl;
else cout<<ans<<nl;


}
 
int main(){
    Fast_IO();
    sieve();
    init();
int t =1; 
cin>>t;
while(t--){
solve();
}
return 0;
}  
