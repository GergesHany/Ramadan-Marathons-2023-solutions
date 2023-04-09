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

void minimum_rotation(string &s){
  int n = sz(s);
  s += s;
  char m = *min_element(all(s));
  string mini = string(n,'z');
  for(int i=0;i<n;i++){
    if(s[i] == m){
      mini = min(mini,s.substr(i,n));
    }
  }
  s = mini;
}


void solve(){

int n,k; cin>>n>>k;
vector<string> v(n);
for(int i=0;i<n;i++){
  string s; cin>>s;
  minimum_rotation(s);
  v[i] = s;
}

sort(all(v));

ll ans = 0,cnt = 1;
for(int i=1;i<n;i++){
  if(v[i] == v[i-1]){
    cnt++;
  }else{
    ans += (cnt*(cnt-1))/2;
    cnt = 1;
  }
}
ans += (cnt*(cnt-1))/2;
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
