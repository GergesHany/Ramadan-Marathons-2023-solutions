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
vector<ll> v(n);
for(auto &i:v)cin>>i;

stack<ll> st;

vector<ll> pre(n),suf(n);

for(int i=0;i<n;i++){
    while(!st.empty() && v[st.top()]<=v[i]){
        st.pop();
    }
    if(st.empty())pre[i]=-1;
    else pre[i]=st.top();
    st.push(i);
}

while(!st.empty())st.pop();

for(int i=n-1;i>=0;i--){
    while(!st.empty() && v[st.top()]<=v[i]){
        st.pop();
    }
    if(st.empty())suf[i]=-1;
    else suf[i]=st.top();
    st.push(i);
}

ll maxi = 0;


for(int i=0;i<n;i++){
    ll pos = i;
    ll cost = LONG_LONG_MAX;
    
    if(pre[i]==-1 and suf[i]==-1)continue;
    
    if(pre[i] != -1){
        cost = min(cost,abs(pos-pre[i]));
    }
    
    if(suf[i] != -1){
        cost = min(cost,abs(suf[i]-pos));
    }
    
    maxi = max(maxi,cost);
}

cout<<maxi<<nl;




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
