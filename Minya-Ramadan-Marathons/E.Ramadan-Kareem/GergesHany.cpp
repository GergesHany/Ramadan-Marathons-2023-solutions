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


void Accepted(){

  ll n;
  cin >> n;
  vector < vector < ll > > vec;
  for (int i = 0; i < n; i++){
    vector < ll > v(5);
    cin >> v;
    vec.push_back(v);
  }

  // rotete the vector
  ll rotate[5][n];
  for (int i = 0; i < n; i++){
    for (int j = 0; j < 5; j++){
      rotate[j][i] = vec[i][j];
    }
  }


  for (int i = 0; i < 5; i++){
    for (int j = 0; j < n; j++){
      string bin = bitset < 32 > (rotate[i][j]).to_string();
      bin = bin.substr(32 - 5, 5);
      for (int i = 0; i < 5; i++){
        if (bin[i] == '1') cout << "*";
        else cout << " ";
      }
      if (j != n - 1)  
       cout << " ";
    }
    cout << " \n";
  }

}

int main()
{

  //Gerges_Hany();
  int testcaces = 1;
  // cin >> testcaces;
  while (testcaces--){
    // cout << "Case #" << T++ << ": ";
    Accepted();
  }
  Time;
  return 0;
}