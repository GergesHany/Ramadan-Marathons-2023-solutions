#include <bits/stdc++.h>
#define ll long long
#define OO 1e18
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
        ll n;
        string s;
        cin >> n >> s;
        ll pref[26][n + 1], suf[26][n + 1];
        memset(pref, 0, sizeof(pref));
        memset(suf, 0, sizeof(suf));
        for(int i = 0; i < 26; i++){
            for(int j = 1; j <= n; j++){
                pref[i][j] = pref[i][j - 1] + (s[j - 1] == char('a' + i));
            }
        }
        for(int i = 0; i < 26; i++){
            for(int j = n - 1; j >= 0; j--){
                suf[i][j] = suf[i][j + 1] + (s[j] == char('a' + i));
            }
        }
        map < string, ll > mp;
        for(int i = 1; i < n - 1; i++){
            for(int j = 0; j < 26; j++){
                string tmp = "";
                tmp += char(j + 'a');
                tmp += s[i];
                tmp += char(j + 'a');
                mp[tmp] += pref[j][i] * suf[j][i + 1];
            }
        }
        ll mx = 0;
        string ans = "";
        for(auto x : mp){
            if(x.second > mx){
                mx = x.second;
                ans = x.first;
            }
            else if(x.second == mx){
                ans = min(ans, x.first);
            }
        }
        cout << (!mx ? "-1" : ans) << endl;
    }



    return 0;
}
