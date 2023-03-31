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
        ll x, z;
        cin >> x >> z;
        ll l = 1, r = 1e18, ans = -1;
        while(l <= r){
            ll mid = (l + r) / 2;
            if(x / mid == z){
                ans = mid;
                r = mid - 1;
            }
            else if(x / mid > z)
                l = mid + 1;
            else
                r = mid - 1;
        }
        cout << ans << endl;
    }
    


    return 0;
}
