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
const ll mod = 1e9 + 7;
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


void Accepted(){

  ll n;
  cin >> n;
  vector < ll > vec(n);
  cin >> vec;

  // if the number can divide the number then it can be a divisor of the number 
  // then we can store all the divisors of all numbers in a vector 
  // then we can sort the vector and iterate over it and for each number we can iterate over its divisors
  // and if the number is found in the vector then we can update max length of the subsequence

  // store all the divisors of all numbers
  vector < ll > divisors[N];
  for (int i = 1; i < N; i++)
    for (int j = i; j < N; j += i)
      divisors[j].push_back(i);
  
  sort(all(vec));
  vector < ll > dp(N, 1), ans(N, 0);
  
  // iterate over all numbers
  for (int i = 0; i < n; i++){
    for (auto &x : divisors[vec[i]])
      if (ans[x]) dp[i] = max(dp[i], ans[x] + 1);
    ans[vec[i]] = max(ans[vec[i]], dp[i]);
  }

  // iterate over all numbers and find the max length of the subsequence
  cout << *max_element(all(dp)) << "\n";

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