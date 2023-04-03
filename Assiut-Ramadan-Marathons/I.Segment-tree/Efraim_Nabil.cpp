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

    ll n, k;
    cin >> n >> k;
    map < ll, ll> mp; 
    for(int i = 1; i <= k; i++){
        ll l, r, val;
        cin >> l >> r >> val;
        mp[l] += val;
        mp[r + 1] -= val;
    }
    ll mx = 0, idx = 0, sum = 0; 
    for(auto it : mp){
        sum += it.second;
        if(sum >= mx){
            mx = sum;
            //idx = max(idx, it.first);
            //cout << idx << endl;
        }
    }
    cout << mx << " ";
    sum = 0;
    vector < pair < ll, ll > > v;
    for(auto it : mp){
        sum += it.second;
        v.push_back({it.first, sum});
        if(sum == mx){
            idx = max(idx, it.first);
        }
    }
    for(int i = 0; i < sz(v) - 1; i++){
        if(v[i].second == mx){
            idx = max(idx, v[i + 1].first - 1);
        }
    }
    cout << idx << endl;


    return 0;
}
