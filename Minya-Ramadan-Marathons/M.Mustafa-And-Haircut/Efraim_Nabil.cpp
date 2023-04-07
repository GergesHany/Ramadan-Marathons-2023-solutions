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

int main(){
    Fero();

    TC{
        ll n, ans = OO;
        cin >> n;
        vector < ll > v(n + 1);
        for(int i = 1; i <= n; i++) cin >> v[i];

        for(int i = 1 ; i <= n; i++){
            for(int j = 1; j <= n; j++){
                ll x = (v[j] / i + ((v[j] % i) != 0)) * i;
                ans = min(ans, x - v[j] + x / i + i + abs(i - j));
            }
        }
        cout << ans << '\n';
    }

    

    return 0;
}
