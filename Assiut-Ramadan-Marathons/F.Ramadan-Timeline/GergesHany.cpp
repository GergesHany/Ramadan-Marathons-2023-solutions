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
const ll mod = 1e9 + 7;
const ll INF = 1LL << 60;
const int N = 1e5 + 5;
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


  vector < ll > vec(7);
  map < string, ll > Idx;
  Idx["Saturday"] = 0, Idx["Sunday"] = 1, Idx["Monday"] = 2;
  Idx["Tuesday"] = 3, Idx["Wednesday"] = 4, Idx["Thursday"] = 5, Idx["Friday"] = 6;

  for (int i = 0; i < 7; i++){
    string day, time;
    cin >> day >> time;
    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));
    int second = stoi(time.substr(6, 2));
    vec[Idx[day]] = hour * 3600 + minute * 60 + second;
  }

  int q;
  cin >> q;
  while (q--){
    string day, time;
    cin >> day >> time;
    ll hour = stoi(time.substr(0, 2));
    ll minute = stoi(time.substr(3, 2));
    ll second = stoi(time.substr(6, 2));    
    ll total = hour * 3600 + minute * 60 + second;

    ll ans = 0, next_time = vec[Idx[day]];
    if (total >= next_time){
      next_time = vec[(Idx[day] + 1) % 7];
      ans += next_time - total;
      ans += 24 * 3600;
    }else{
      ans += next_time - total;
    }
    cout << ans << "\n";
  }

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