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

vector < ll > next_greater_element(vector < ll > &v){
    int n = sz(v);
    vector < ll > ans(n);
    stack < pair < int, int > > st;
    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && st.top().first <= v[i]) st.pop();
        ans[i] = (st.empty() ? -1 : st.top().second);
        st.push({v[i], i});
    }
    return ans;
}

vector < ll > prev_greater_element(vector < ll > &v){
    int n = sz(v);
    vector < ll > ans(n);
    stack < pair < int, int > > st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && st.top().first <= v[i]) st.pop();
        ans[i] = (st.empty() ? -1 : st.top().second);
        st.push({v[i], i});
    }
    return ans;
}

int main(){
    Fero();

    TC{
        ll n;
        cin >> n;
        vector < ll > v(n);
        for(auto &x : v) cin >> x;
        vector < ll > nextg = next_greater_element(v);
        vector < ll > prevg = prev_greater_element(v);
        ll ans = 0;
        for(int i = 0; i < n; i++){
            if(nextg[i] != -1) ans = max(ans, abs(i - nextg[i]));
        }
        for(int i = 0; i < n; i++){
            if(prevg[i] != -1) ans = max(ans, abs(i - prevg[i]));
        }
        cout << ans << endl;
    }

    return 0;
}