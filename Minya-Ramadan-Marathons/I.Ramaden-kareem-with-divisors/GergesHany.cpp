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

// any number can be represented as a product of prime factors
// for example 12 = (2^2) * (3^1)
// the number of divisors of 12 is (2 + 1) * (1 + 1) = 6 
// the number of divisors of n! is the (product of the number of divisors of each prime factor) + 1 from 1 to n

ll number_of_divisors(ll n){

  ll ans = 1;
  ll freq[1005] {};
  long double LOG = 0; // to check if the number of divisors is greater than 10^18
  
  // find the prime factors of n and count the number of times each prime factor appears
  for (ll i = n; i >= 1; i--){
    ll val = i; // val is the number that we will factorize
    for (ll j = 2; j <= val; j++)
       // if j is a prime factor of val then count the number of times it appears
       while(val % j == 0) freq[j]++, val /= j;
  }

  for (ll i = 1; i <= n; i++){
   // multiply the number of divisors of each prime factor by the number of divisors of n! 
    ans *= (freq[i] + 1);
   // calculate the logarithm of the number of divisors of n! 
    LOG += log10(freq[i] + 1);
  }

  // if the number of divisors is greater than 10^18 return -1 
  return (LOG > 18 ? -1 : ans);  
}

vector < ll > build(109);
void build_ans(){
  for (ll i = 1; i <= 108; i++)
    build[i] = number_of_divisors(i);
}

void Accepted(){
  
  ll n;
  cin >> n;
  for (ll i = 1; i <= 108; i++){
    if (build[i] == n)
     return void(cout << i << '\n');
  }

  cout << "Ramaden Kareem Ya Amoor" << '\n';
  
}

int main()
{
 
  build_ans();
  Gerges_Hany();
  int testcaces = 1, T = 1;
   cin >> testcaces;
  while (testcaces--){  
    // cout << "Scenario #" << T++ << ": \n";
    Accepted();
  }   
  Time; 
  return 0;
}