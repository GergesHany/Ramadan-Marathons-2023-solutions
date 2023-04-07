#include <bits/stdc++.h>
#define ll long long
#define OO 1e9
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define TC int t; cin >> t; while(t--)
using namespace std;
void Fero(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
    #endif
}

ll n;
vector <ll> v, dp;
vector < vector < int > > divisors;
void sieve(int n){
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j += i){
            divisors[j].push_back(i);
        }
    }
}
vector < ll > best;
ll bu(){
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(auto j : divisors[v[i]]){
            if(best[j] != 0)
                dp[i] = max(dp[i], best[j] + 1);
        }
        best[v[i]] = max(best[v[i]], dp[i]);
    }
    return *max_element(all(dp));
}

int main(){
    Fero();

    cin >> n;
    v.assign(n, 0);
    divisors.resize(1e6 + 5);
    sieve(1e6 + 5);
    for(auto &i : v) cin >> i;
    sort(all(v));
    dp.assign(n + 5, 1);
    best.assign(1e6 + 5, 0);
    ll ans = bu();
    cout << ans << endl;

    return 0;
}
