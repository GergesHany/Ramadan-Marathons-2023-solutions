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

int main(){
    Fero();

    ll n;
    cin >> n;
    ll sum = 0;
    ll ans = 0;
    for(ll i = 1; i <= n; i++){
        sum += i;
        if(sum > n) break;
        if((n - sum) % i == 0) ans = i;
    }
    cout << ans << "\n";

    return 0;
}
