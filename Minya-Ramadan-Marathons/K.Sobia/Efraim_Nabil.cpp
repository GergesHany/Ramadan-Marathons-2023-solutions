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

    TC{
        ll n, k;
    cin >> n >> k;
    vector <ll> v(n);
    ll sum = 0;
    for(int i=0; i<n; i++){
        cin >> v[i];
        sum += v[i];    
    }
    ll l = 0, r = sum;
    ll ans = -1;    
    while(l <= r){
        ll mid = (l + r) / 2;
        ll cnt = 1;
        ll cur = 0;
        for(int i = 0; i < n; i++){
            if(cur + v[i] > mid){
                cnt++;
                cur = v[i];
            }
            else cur += v[i];
        }
        if(cnt <= k && cur <= mid){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans << "\n";
    }

    return 0;
}
