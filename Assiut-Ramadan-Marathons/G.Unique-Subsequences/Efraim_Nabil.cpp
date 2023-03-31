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
    vector < ll > v(n);
    for(auto &i : v) cin >> i;
    map < ll , ll > mp;
    for(auto i : v) mp[i]++;
    ll mx = 0;
    for(auto i : mp) mx = max(mx, i.second);
    cout << mx << " " << n ;
    


    return 0;
}
