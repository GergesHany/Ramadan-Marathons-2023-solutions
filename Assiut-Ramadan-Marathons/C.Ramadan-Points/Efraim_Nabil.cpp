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
    vector<ll> v(n), ans;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    sort(all(v));
    for(int i = 1; i < n; i++)
        ans.push_back(v[i] - v[i - 1]);
    for (int i = 2; i < n; i++)
        ans.push_back(v[i] - v[i - 2]);
    sort(all(ans));
    cout << ans[2] << endl;
  return 0;
}
