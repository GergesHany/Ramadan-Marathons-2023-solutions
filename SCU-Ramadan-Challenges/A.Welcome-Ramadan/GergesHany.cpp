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
const ll N = 2 * 1e5 + 5;
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



template < typename T = int > struct monotonic_stack{
  
  T n;
  vector < T > v;
  vector < T > ans;
  stack < pair < T, T > > st;
 
  monotonic_stack(vector < T > &v) : v(v) {
    n = sz(v);
    ans = vector < T > (n);
  }
  
  // function to get the next greater if no greater element return -1
  vector < T > next_greater_element(){
    for(int i = n - 1; i >= 0; i--){
      while(!st.empty() && st.top().first <= v[i]) st.pop();
      ans[i] = (st.empty() ? -1 : st.top().second);
      st.push({v[i], i});
    }
    return ans;
  }
 
  // function to get the previous greater if no greater element return -1
  vector < T > prev_greater_element(){
    for(int i = 0; i < n; i++){
      while(!st.empty() && st.top().first <= v[i]) st.pop();
      ans[i] = (st.empty() ? -1 : st.top().second);
      st.push({v[i], i});
    }
    return ans;
  }
 
  // function to get the next smaller if no smaller element return n
  vector < T > next_smaller_element(){
    for(int i = n - 1; i >= 0; i--){
      while(!st.empty() && st.top().first >= v[i]) st.pop();
      ans[i] = (st.empty() ? n : st.top().second);
      st.push({v[i], i});
    }
    return ans;
  }
 
  // funtion to get the previous smaller if no smaller element return -1
  vector < T > prev_smaller_element(){
    for(int i = 0; i < n; i++){
      while(!st.empty() && st.top().first >= v[i]) st.pop();
      ans[i] = (st.empty() ? -1 : st.top().second);
      st.push({v[i], i});
    }
    return ans;
  }
 
 
};

void Accepted(){
  
  ll n;
  cin >> n;
  vector < ll > v(n);
  cin >> v;

  ll ans = 0;
  vector < ll > next_greater = monotonic_stack(v).next_greater_element();
  vector < ll > prev_greater = monotonic_stack(v).prev_greater_element();

  for (int i = 0; i < n; i++){
    if (next_greater[i] != -1){
      ans = max(ans, abs(i - next_greater[i]));
    } 
  }

  for (int i = 0; i < n; i++){
    if (prev_greater[i] != -1){
      ans = max(ans, abs(i - prev_greater[i]));
    } 
  }

  cout << ans << "\n";

 
}

int main()
{

  Gerges_Hany();
  int testcaces = 1, T = 1;
    cin >> testcaces;
  while (testcaces--){  
    // cout << "Case #" << T++ << ": ";
    Accepted();
  }   
  Time; 
  return 0;
}