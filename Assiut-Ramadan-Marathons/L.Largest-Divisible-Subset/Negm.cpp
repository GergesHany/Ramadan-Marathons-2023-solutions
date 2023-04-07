#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define OO 2'000'000'000
#define ull unsigned long long
#define nl '\n'
#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define rall(s)  s.rbegin(), s.rend()
#define getline(s) getline(cin>>ws,s)
#define ceill(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define pi  3.141592653589793
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define multi_ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

 
void Fast_IO(){
ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
// freopen("filename.in", "r", stdin);
// freopen("filename.txt", "w", stdout);
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#endif
}




int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };




void solve(){
  int n; cin>>n;
  vector<int>v(n);
  vector<int>freq(1e6+1);

    for(auto&i:v){
        cin>>i;
        freq[i]++;
    }

    sort(all(v));
    v.erase(unique(all(v)),v.end());
    n = sz(v);
    
    vector<bool>vis(v.back()+1);
    for(int i=0;i<n;i++){
        vis[v[i]] = 1;
    }
    
    vector<int>divs[v.back()+1];
    
    for(ll i=1;i<=v.back();i++){
        for(ll j=i;j<=v.back();j+=i){
            if(vis[j] and vis[i] and i!=j)
                divs[j].emplace_back(i);
        }
    }

    vector<int>dp(n);
    for(int i=0;i<n;i++){
        dp[i] = freq[v[i]];
    }


    for(int i=0;i<n;i++){
        int mx = 0;
        for(auto&j:divs[v[i]]){
            auto it = lower_bound(all(v),j);
            int idx = it-v.begin();
            mx = max(mx,dp[idx]);
        }
        dp[i] += mx;
    }
    
    cout<<*max_element(all(dp))<<nl;


}
 
int main(){
    Fast_IO();
int t =1; 
//cin>>t;
while(t--){
solve();
}
return 0;
}  
