#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std; 
using namespace __gnu_pbds;
 
#define EPS 1e-8
#define sz(s) int(s.size())  
#define rall(s)  s.rbegin(), s.rend()
#define TC int t; cin >> t; while(t--)
#define getline(s) getline(cin >> ws, s)
#define all(vec)  vec.begin(),  vec.end()
#define updmin(a, b) a = min((ll)a, (ll)b)
#define updmax(a, b) a = max((ll)a, (ll)b)
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define endd(s) return void(cout << s << "\n")
#define fixed(n) cout << fixed << setprecision(n)
#define ceill(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define cin_2d(vec, n, m) for(int i=0;i<n;i++) for(int j=0;j<m&&cin>>vec[i][j];j++);
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
#define ordered_set tree<ll, null_type, less <ll>, rb_tree_tag,tree_order_statistics_node_update>
#define multi_ordered_set tree<ll, null_type, greater_equal <ll>, rb_tree_tag,tree_order_statistics_node_update>
 
typedef long long ll;
typedef long double ld;
const ll N = 1e5 + 5;
const ll mod = 1000000007;
const ll INF = 1LL << 60;
 
void Gerges_Hany(){
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  #ifndef ONLINE_JUDGE  
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
  #endif
}
 
template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x : v) in >> x; return in;
}
 
template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) { 
    for (const T &x : v) out << x << ' '; return out;
}
 
vector < ll > factor[5005]; 
vector < ll > prime_factor(ll n){
  vector < ll > ans;
  for (ll i = 2; i * i <= n; i++){
    if (n % i == 0){
      ans.push_back(i);
      while(n % i == 0) n /= i;
    }
  }
  
  if (n >= 2) ans.push_back(n);
  return ans;
}
 
ll n, ans;
vector < ll > vec, groups;
 
void rec(ll Idx, ll curr){

  if (curr > ans) return;
  if (Idx == n)
   return void(ans = min(ans, curr));
 
  for (auto x : factor[vec[Idx]]){
    if (groups[x] == 1){
      rec(Idx + 1, curr);
      return;
    }else{
      groups[x] = 1;
      rec(Idx + 1, curr + 1);
      groups[x] = 0;
    }
  }
 
}
 
void Accepted(){
   
  cin >> n;
  vec = vector < ll > (n);
  cin >> vec;
  groups = vector < ll > (5005);
  vec.erase(unique(all(vec)), vec.end());
  for (auto & i: vec)
    factor[i] = prime_factor(i);

  ll cnt = 0;
  bool add[5005] = {0};
  for (auto & i: vec){
    if (sz(factor[i]) == 1){
      ll fact = factor[i].front();
      groups[fact] = 1;      
      if (!add[fact]) cnt++, add[fact] = true;
    }
  }  

  n = sz(vec), ans = n;
  rec(0, 0);
  cout << ans + cnt;
 
}
 
int main()
{
 
  Gerges_Hany();
  int testcaces = 1, T = 1;
  //  cin >> testcaces;
  while (testcaces--){  
   // cout << "Case #" << T++ << ": ";
    Accepted();
  }   
  Time; 
  return 0;
}