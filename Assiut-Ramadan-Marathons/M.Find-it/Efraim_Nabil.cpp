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
       //freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
    #endif
}   


int main(){
    Fero();

    ll l = 1, r = 1e15 + 1, ans = 0;
    while (l < r){
        ll mid = l + (r - l) / 2;
        cout << "? " << mid << endl;
        cout.flush();
        ll x;
        cin >> x;
        if(x) ans += mid;
        r = mid;
    }
    cout << "! " << ans << endl;
    cout.flush();
    

    return 0;
}
