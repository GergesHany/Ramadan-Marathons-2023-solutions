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
const ll mod = 1000000007;
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

template < typename T = long long > struct  prefix_sum_2d{
  
  // build prefix sum 2d
  vector < vector < T > > prefix_sum(vector < vector < T > > &v){
    int n = sz(v), m = sz(v[0]);
    vector < vector < T > > ps(n + 1, vector < T > (m + 1, 0));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            ps[i][j] = v[i - 1][j - 1] + ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
        }
    }
    return ps;
  }

  // query in prefix sum 2d
  T query(vector < vector < T > > &ps, T x1, T y1, T x2, T y2){
    return ps[x2][y2] - ps[x1 - 1][y2] - ps[x2][y1 - 1] + ps[x1 - 1][y1 - 1];
  }
  
  // print prefix sum 2d
  void print(vector < vector < ll > > &ps){
    for (int i = 1; i < sz(ps); i++)
        for (int j = 1; j < sz(ps[0]); j++)
            cout << ps[i][j] << " \n"[j == sz(ps[0]) - 1];
  }

};

void Accepted(){  

  ll n, m;
  cin >> n >> m;
  vector < vector < ll > > vec(n, vector < ll > (n, 0));
  cin_2d(vec, n, n);
  prefix_sum_2d < ll > ps;
  vector < vector < ll > > ps2d = ps.prefix_sum(vec);

  ll ans = -INF;
  for (int i = 1; i <= n - m + 1; i++){
      for (int j = 1; j <= n - m + 1; j++){
          updmax(ans, ps.query(ps2d, i, j, i + m - 1, j + m - 1));
      }
  }

  cout << ans << "\n";


}

int main()
{ 
  
  Gerges_Hany();
  int testcaces = 1;
   cin >> testcaces;
  while (testcaces--){  
    // cout << "Case #" << T++ << ": ";
    Accepted();
  }   
  Time;
  return 0;
}