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
  unordered_map<string,int>mp {{"Saturday",0},{"Sunday",1},{"Monday",2},{"Tuesday",3},{"Wednesday",4},{"Thursday",5},{"Friday",6}};
  vector<ll>ans(7);
    for(int i=0;i<7;i++){
        string s;
        int h,m,se;
        char c;
        cin>>s>>h>>c>>m>>c>>se;
        ans[mp[s]] = h*3600 + m*60 + se;
    }
    int n; cin>>n;
    for(int i=0;i<n;i++){
        string s;
        int h,m,se;
        char c;
        cin>>s>>h>>c>>m>>c>>se;
        int t = h*3600 + m*60 + se;
        ll pos = mp[s];
        ll x = ans[pos];
        bool f = 0;
        if(t>=x){
            x = ans[(pos+1)%7];
            f = 1;
        }
        ll res = x-t;
        if(f) res+=24*3600;
        cout<<res<<nl;
    }





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
