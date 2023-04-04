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

string s;
ll dp[100050][2][4];
ll rec(ll idx, ll last, ll cnt){
    if(cnt == 3) return 1;
    if(idx == sz(s)) return 0;
    ll &ret = dp[idx][last][cnt];
    if(~ret) return ret;
    ret = 0;
    if(s[idx] == last + '0') ret = rec(idx + 1, last, cnt);
    else ret = rec(idx + 1, s[idx] - 48, cnt + 1) + rec(idx + 1, last, cnt);
    return ret;
}

int main(){
    Fero();

    cin >> s;
    memset(dp, -1, sizeof dp);
    cout << rec(0, 2, 0) << endl;

    return 0;
}
