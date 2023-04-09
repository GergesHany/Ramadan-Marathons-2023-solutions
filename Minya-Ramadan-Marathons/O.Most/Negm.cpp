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
ll n; cin>>n;
string s; cin>>s;
vector<vector<ll>> pre(n,vector<ll>(26)),suf(n,vector<ll>(26));

for(int i=0;i<n;i++){
    if(i==0){
        pre[i][s[i]-'a']++;
    }
    else{
        pre[i]=pre[i-1];
        pre[i][s[i]-'a']++;
    }
}

for(int i=n-1;i>=0;i--){
    if(i==n-1){
        suf[i][s[i]-'a']++;
    }
    else{
        suf[i]=suf[i+1];
        suf[i][s[i]-'a']++;
    }
}

string ans = "{{{";
ll maxi = 0;

unordered_map<string,ll>mp;

for(int i=1;i<n-1;i++){
    for(int j=0;j<26;j++){
        string tmp = "";
        
            char c = j+'a';
            tmp+= c;
            tmp+=s[i];
            tmp+=c;
            mp[tmp]+=pre[i-1][j]*suf[i+1][j];
        
    } 
}

for(auto&x:mp){
    if(x.second>maxi){
        maxi = x.second;
        ans = x.first;
    }else if(x.second==maxi and x.second!=0){
        ans = min(ans,x.first);
    }
}

if(ans == "{{{") ans = "-1";
cout<<ans<<nl;




}
 
int main(){
    Fast_IO();
int t =1; 
cin>>t;
while(t--){
solve();
}
return 0;
}  
