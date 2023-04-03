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
const ll N = 1e6 + 5;
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
 
template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v){ 
  for (const T &x : v) out << x << ' '; return out;
}


// kmp algorithm
template < typename T = int > struct KMP{
  
  string s;
  vector < T > pi;
  
  KMP() = default;

  KMP(string s): s(s){
    pi = vector < T > (sz(s));
    for(int i = 1, j = 0; i < sz(s); i++){
      while(j > 0 && s[i] != s[j]) j = pi[j - 1];
      if(s[i] == s[j]) j++;
      pi[i] = j;
    }
  }

  vector < T > match(string t){
    vector < T > ans(sz(t));
    for(int i = 0, j = 0; i < sz(t); i++){
      while(j > 0 && t[i] != s[j]) j = pi[j - 1];
      if(t[i] == s[j]) j++;
      ans[i] = j;
    }
    return ans;
  }
  
  string get_lps(){
    string ans;
    for(int i = 0; i < sz(s); i++){
      if(pi[i] == 0) continue;
      if(pi[i] == pi[pi[i] - 1]) continue;
      ans += s[i];
    }
    return ans;
  }

};

void Accepted(){
  
  string s; cin >> s;
  KMP < ll > kmp(s);  
  ll ans = sz(s) - kmp.pi.back(); 
  cout << (sz(s) % ans || ans == sz(s) ? -1 : ans);

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
