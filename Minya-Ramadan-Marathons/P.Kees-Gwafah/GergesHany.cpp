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


void Accepted(){  

  ll n, m;
  cin >> n >> m;
  ll vec[n][m];
  cin_2d(vec, n, m);

  ll prefix_lcm_row[n][m], prefix_lcm_col[m][n];
  ll suffix_lcm_row[n][m], suffix_lcm_col[m][n];

  // build prefix lcm row and col 
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (j == 0) prefix_lcm_row[i][j] = vec[i][j];
      else prefix_lcm_row[i][j] = lcm(prefix_lcm_row[i][j - 1], vec[i][j]);
      if (i == 0) prefix_lcm_col[j][i] = vec[i][j];
      else prefix_lcm_col[j][i] = lcm(prefix_lcm_col[j][i - 1], vec[i][j]);
    }
  }  

  // build suffix lcm row and col
  for (int i = n - 1; i >= 0; i--){
    for (int j = m - 1; j >= 0; j--){
      if (j == m - 1) suffix_lcm_row[i][j] = vec[i][j];
      else suffix_lcm_row[i][j] = lcm(suffix_lcm_row[i][j + 1], vec[i][j]);
      if (i == n - 1) suffix_lcm_col[j][i] = vec[i][j];
      else suffix_lcm_col[j][i] = lcm(suffix_lcm_col[j][i + 1], vec[i][j]);
    }
  }

  // build answer
  ll ans = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      ll row = 0, col = 0;
      if (!j) row = suffix_lcm_row[i][j + 1];
      else if (j == m - 1) row = prefix_lcm_row[i][j - 1];
      else row = lcm(prefix_lcm_row[i][j - 1], suffix_lcm_row[i][j + 1]);

      if (!i) col = suffix_lcm_col[j][i + 1];
      else if (i == n - 1) col = prefix_lcm_col[j][i - 1];
      else col = lcm(prefix_lcm_col[j][i - 1], suffix_lcm_col[j][i + 1]);
      
      ll new_lcm = lcm(row, col);
      ll old = lcm(suffix_lcm_row[i][0], suffix_lcm_col[j][0]);
      ans += (new_lcm == old);
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