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
const ll N = 5e5 + 100;
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


void Accepted(){

  int n;
  cin >> n;
  // the size of the freq is 2 * (max range of v[i]) because we can have negative numbers
  ll mp[2 * N + 10] = {0};
  vector < int > vec(n);
  set < tuple < int, int, int > > ans;
  for(auto &x : vec) cin >> x, mp[x + N]++;

  for (int i = 0; i < n; i++){
    for (int j = i + 1; j < n; j++){
      ll sum = vec[i] + vec[j]; // the third number should be -sum
      // remove the two numbers from the freq array because maybe they are repeated in the array and we don't want to count them twice 
      mp[vec[i] + N]--, mp[vec[j] + N]--; 
      if (mp[-sum + N] > 0){ // if the third number is in the array
        vector < ll > I = {vec[i], vec[j], -sum};
        sort(all(I));
        ans.insert({I[0], I[1], I[2]});
      }
      // add the two numbers again to the freq array because we will use them in the next iteration
      mp[vec[i] + N]++, mp[vec[j] + N]++;
    }
  }

  // if the answer is empty print -1
  if (!sz(ans)) endd("-1");

  // print the answer
  cout << sz(ans) << '\n';
  for (auto [a, b, c] : ans) 
    cout << a << " " << b << " " << c << "\n";

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
