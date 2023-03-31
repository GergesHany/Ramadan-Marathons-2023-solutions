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
#define multi_ordered_set tree<ll, null_type, less_equal <ll>, rb_tree_tag,tree_order_statistics_node_update>

typedef long long ll;
typedef long double ld;
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

void Accepted(){

  ll n;
  cin >> n;
  vector < ll > vec(n * 2);
  cin >> vec;
  sort(all(vec));
  
  // the original value is x
  auto target = [](ll x) -> ll {
    return (x * 4) / 3;
  };


  // binary search to find the index of the target value
  auto BS = [&](ll left, ll value) -> ll {
    ll right = n * 2 - 1, Idx = -1;
    while (left <= right){
      ll mid = left + (right - left) / 2;
      // find the smallest index of the target value
      if (vec[mid] == target(value)) Idx = mid, right = mid - 1;
      else if (vec[mid] > target(value)) right = mid - 1;
      else left = mid + 1;
    }
    return Idx;
  };

  const int N = 2e6 + 5;
  bool vis[N] = {0};

  ll prev = 1;
  for (int i = 0; i < n * 2; i++){
    if (vis[i]) continue; // if the value is already used in the previous pair then skip it

    // find the index of the target value of the current value
    ll Idx = BS(prev, vec[i]);

    // if the index is found
    if (~Idx){
      // print the value
      cout << vec[i] << ' ';
      // mark the current value and the target value as used
      vis[i] = vis[Idx] = true;
      // update the previous index to be the current index + 1  
      // to search for the next target value from the next index
      // because if the prev value is smaller than or equal to the current value
      // then the target value of the current value will be greater than or equal the target value of the prev value
      // so we can search for the next target value from the next index
      prev = Idx + 1;
    }
  }
  
}

int main()
{

  Gerges_Hany();
  int testcaces = 1, T = 1;
   // cin >> testcaces;
  while (testcaces--){  
    // cout << "Scenario #" << T++ << ": \n";
    Accepted();
  }   
  Time; 
  return 0;
}
