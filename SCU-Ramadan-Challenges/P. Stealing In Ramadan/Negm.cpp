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


ll n, m, k;
vector<ll> v;


ll DAC(){
    vector<vector<ll>> left(41), right(41);
    int mid = n/2;
    vector<ll> l(v.begin(), v.begin()+mid), r(v.begin()+mid, v.end());
    for(int i = 0; i < (1<<mid); i++){
        ll sum = 0;
        for(int j = 0; j < mid; j++){
            if(i & (1<<j)){
                sum += l[j];
            }
        }
        if(sum<=k and __builtin_popcount(i)<=m)
            left[__builtin_popcount(i)].emplace_back(sum);
    }

    for(int i = 0; i < (1<<(n-mid)); i++){
        ll sum = 0;
        for(int j = 0; j < (n-mid); j++){
            if(i & (1<<j)){
                sum += r[j];
            }
        }
        if(sum<=k and __builtin_popcount(i)<=m)
            right[__builtin_popcount(i)].emplace_back(sum);
    }

    for(int i = 0; i <= 40; i++){
        sort(all(left[i]));
        sort(all(right[i]));
    }

    ll ans = 0;

    for(int i=0;i<=m;i++){
        for(int j=0;j<=m;j++){
            if(i+j>m)continue;
            for(auto &x : left[i]){
                ll rem = k-x;
                if(rem<0)continue;
                auto it = upper_bound(all(right[j]), rem);
                ans += it - right[j].begin();
            }
        }
    }


    return ans;
}



void solve(){
cin>>n>>m>>k;
v = vector<ll>(n);
for(auto &i : v)cin>>i;

sort(all(v));
ll ans = DAC();
cout<<ans<<nl; 




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
