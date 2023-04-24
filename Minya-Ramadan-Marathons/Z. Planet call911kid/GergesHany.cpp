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
const ll mod = 1e9 + 7;
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

  ll n, m, p;
  cin >> n >> m >> p;

  vector < vector < ll > > pr(n + 2, vector < ll > (m + 2, 0));
  vector < vector < ll > > pc(n + 2, vector < ll > (m + 2, 0));
  vector < vector < ll > > vec(n + 2, vector < ll > (m + 2, 0));


  for (int i = 0; i < p; i++){
    ll r, c, k;
    cin >> r >> c >> k;
    pr[r][max(0LL, c - k)]++;
    pr[r][min(m + 1LL, c + k + 1)]--;

    pc[max(0LL, r - k)][c]++;
    pc[min(n + 1LL, r + k + 1)][c]--;
    vec[r][c]--;
  }

  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      pr[i][j] += pr[i][j - 1];
      pc[i][j] += pc[i - 1][j];
      vec[i][j] += pr[i][j] + pc[i][j];
    }
  }

  prefix_sum_2d < ll > ps;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
          cout << (vec[i][j] ? 1 : 0) << " \n"[j == m];
          vec[i][j] += vec[i][j - 1] + vec[i - 1][j] - vec[i - 1][j - 1];
        }
    }

  auto good = [&](int mid) -> bool {
    for (int i = 1; i <= n - mid + 1; i++)
      for (int j = 1; j <= m - mid + 1; j++){
        int x1 = i, y1 = j, x2 = i + mid - 1, y2 = j + mid - 1;
        int cnt = ps.query(vec, x1, y1, x2, y2);
        if (!cnt) return true;
      }
    return false;  
  };
 
  int ans = -1, l = 1, r = min(n, m);
  while (l <= r){
    int mid = l + (r - l) / 2;
    if (good(mid)) ans = mid, l = mid + 1;
    else r = mid - 1;
  }
  
  cout << (ans == -1 ? -1 : ans * ans) << "\n";


  
}

int main()
{

  Gerges_Hany();
  int testcaces = 1, T = 1;
  // cin >> testcaces;
  while (testcaces--){  
   // cout << "Case #" << T++ << ": ";
    Accepted();
  }   
  Time; 
  return 0;
}