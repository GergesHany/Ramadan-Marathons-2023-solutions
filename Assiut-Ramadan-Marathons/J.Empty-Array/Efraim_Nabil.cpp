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

    ll n, q;
    cin >> n >> q;
    vector<ll> v(n, 0);
    ll first = 0;
    while(q--){
        ll op, x, i;
        cin >> op;
        if(op == 1){
            cin >> x >> i;
            v[i] += x;
            if(v[i] == 0) first = min(first, i);
        }
        else{
            cin >> x;
            while(first < n && v[first] != 0) first++;
            if(first < n && v[first] == 0) v[first] += x;
        }
    }
    for(auto x : v) cout << x << " ";
    
    



    return 0;
}


 
