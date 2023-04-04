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
ll n,p,q,r;
cin>>n>>p>>q>>r;
vector<ll>arr(n);
for(int i=0;i<n;i++)cin>>arr[i];

vector<pair<int,int>>f,s,t;
ll sum = 0;
ll le = 0,ri = 0;
for(;ri<n;ri++){
    sum+=arr[ri];
    while(sum>p) sum-=arr[le++];
    if(sum == p) f.emplace_back(le,ri);
}

sum = le = ri = 0;

for(;ri<n;ri++){
    sum+=arr[ri];
    while(sum>q) sum-=arr[le++];
    if(sum == q) s.emplace_back(le,ri);
}

sum = le = ri = 0;

for(;ri<n;ri++){
    sum+=arr[ri];
    while(sum>r) sum-=arr[le++];
    if(sum == r) t.emplace_back(le,ri);
}


for(auto&[x,y]:f){
    auto it = lower_bound(all(s),make_pair(y+1,0));
    if(it == s.end() or it->first > y+1) continue;

    auto it2 = lower_bound(all(t),make_pair(it->second+1,0));
    if(it2 == t.end() or it2->first > it->second+1) continue;

    return cout<<"YES"<<nl,void();
}
cout<<"NO"<<nl;




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
