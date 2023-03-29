#include <bits/stdc++.h>
#define ll long long
#define OO 1e9
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.ren()
#define TC int t; cin >> t; while(t--)
using namespace std;
void Fero(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
    #endif
}
ll Mod = 998244353;
ll pow(ll a, ll b, ll mod = Mod){
    ll res = 1;
    while(b){
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}


int main(){
    Fero();

    TC{
        ll n;
        cin >> n;
        long double mx = 0;
        ll v = 0;
        if(n == 1){
            cout << 1 << '\n';
            continue;
        }
        for(ll i = 1; i * i <= n; i++){
            if(n % i == 0){
                long double x = log(i) * (n / i);
                if(x > mx){
                    mx = x;
                    v = i;
                }
                x = log(n / i) * i;
                if(x > mx){
                    mx = x;
                    v = n / i;
                }
            }
        }
        ll ans = 0;
        ans = pow(v, n / v);
        cout << (ans + Mod) % Mod << '\n';
    }

    return 0;
}
