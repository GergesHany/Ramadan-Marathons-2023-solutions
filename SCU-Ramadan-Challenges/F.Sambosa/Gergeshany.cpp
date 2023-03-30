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

  ll n;
  cin >> n;
  vector < ll > target(3);
  vector < ll > vec(n), prefix(n);
  cin >> target;

  // prefix sum
  for (int i = 0; i < n && cin >> vec[i]; i++)
    prefix[i] = (i ? prefix[i - 1] : 0) + vec[i];

  ll L = 0, R = 0, sum = 0;
  while (R < n){
    sum += vec[R];
    // while the sum is greater than the target, we will remove the left element
    while (sum > target[0]) sum -= vec[L++]; 

    // if the sum is equal to the target
    // we will check if the next subarray is equal to the target[1]
    // and the next subarray is equal to the target[2]
    
    if (sum == target[0]){
      // we will use binary search to find the next subarray that is equal to the target[1] 
      ll Idx = lower_bound(all(prefix), prefix[R] + target[1]) - prefix.begin();
      if (~Idx && Idx != n && prefix[Idx] == prefix[R] + target[1]){
        // we will use binary search to find the next subarray that is equal to the target[2]
        ll Idx1 = lower_bound(all(prefix), prefix[Idx] + target[2]) - prefix.begin();
        // if the next subarray is equal to the target[2] we will print YES
        if (~Idx1 && Idx1 != n && prefix[Idx1] == prefix[Idx] + target[2])
          return void(cout << "YES\n");
      }      
      // if the next subarray is not equal to the target[1] or target[2] 
      // we will remove the left element and add the right element to the sum to check again 
      sum -= vec[L++];
    }
    // move the right pointer to the next element to add it to the sum and check again
    R++;
  }

  cout << "NO\n";


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