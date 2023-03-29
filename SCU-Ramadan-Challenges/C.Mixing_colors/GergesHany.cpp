#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std; 
using namespace __gnu_pbds;

#define EPS 1e-8
#define sz(s) (ll)(s.size())  
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
#define multi_ordered_set tree<ll, null_type, less_equal <ll>, rb_tree_tag,tree_order_statistics_node_update>

typedef long long ll;
typedef long double ld;
const ll mod = 999983;
const ll INF = 1LL << 60;
typedef unsigned long long ull;


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

ll n, ra, rb;
ll dp[41][105][105];
vector < ll > a, b, c;

ll solve(ll Idx, ll sum_a, ll sum_b){
  
  if (sum_a > 100 || sum_b > 100) return INF;
  
  if (Idx == n)
    return ((!sum_a || !sum_b) ? INF : (sum_a * rb == sum_b * ra ? 0 : INF));

  ll &ret = dp[Idx][sum_a][sum_b];
  if (~ret) return ret; 
  ret = INF;
  updmin(ret, solve(Idx + 1, sum_a, sum_b));
  updmin(ret, solve(Idx + 1, sum_a + a[Idx], sum_b + b[Idx]) + c[Idx]);
  return ret;
}

void Accepted(){  
 
  cin >> n >> ra >> rb;
  a = b = c = vector < ll > (n);
  
  for (int i = 0; i < n; i++)
    cin >> a[i] >> b[i] >> c[i];
  memset(dp, -1, sizeof dp); 
  
  ll ans = solve(0, 0, 0);
  cout << (ans == INF ? -1 : ans);  

}

int main()
{ 
  
  Gerges_Hany();
  int testcaces = 1;
  // cin >> testcaces;
  while (testcaces--){  
    // cout << "Case #" << T++ << ": ";
    Accepted();
  }   
  Time;
  return 0;
}