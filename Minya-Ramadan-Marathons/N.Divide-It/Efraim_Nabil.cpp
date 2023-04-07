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

vector < ll > getDivisors(ll n){
    vector < ll > v;
    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0){
            v.push_back(i);
            if(i * i != n) v.push_back(n / i);
        }
    }
    return v;
}

int main(){
    Fero();

    ll n;
    cin >> n;
    vector < ll > v(n);
    for(auto &x : v) cin >> x;
    map < ll, ll > mp;
    for(auto &x : v) mp[x]++;

    ll mn = OO;
    for(auto &x : mp) mn = min(mn, x.second);
    vector < ll > div = getDivisors(mn);
    sort(all(div));
    div.erase(div.begin());
    for(auto &x : div){
        bool ok = 1;
        for(auto &y : mp){
            if(y.second % x != 0){
                ok = 0;
                break;
            }
        }
        if(ok){
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    

    return 0;
}
