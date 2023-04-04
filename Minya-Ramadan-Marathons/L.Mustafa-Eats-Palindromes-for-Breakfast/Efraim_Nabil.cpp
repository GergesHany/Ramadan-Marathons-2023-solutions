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
        string s;
        cin >> s;
        ll n = s.size(), ans = -1;
        map<char, ll> mp;
        for(auto i : s) mp[i]++;
        for(auto i : mp){
            if(i.second >= 2) ans = max(ans, i.second);
        }
        cout << ans << endl;
    }


    return 0;
}
