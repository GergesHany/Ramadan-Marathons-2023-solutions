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

ll ans1(ll n1, ll n2, ll n3){
    ll ans = 0;
    ll mn = min(n1, n3);
    ans += mn;
    n1 -= mn;
    n3 -= mn;
    ans += n2 / 2;
    n2 %= 2;
    if(n2 == 1){
        if(n1 >= 2){
            ans++;
            n1 -= 2;
        }
    }
    ans += n1 / 4;
    return ans;
}


int main(){
    Fero();

    ll n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    cout << ans1(n1, n2, n3);
    
    return 0;
}
