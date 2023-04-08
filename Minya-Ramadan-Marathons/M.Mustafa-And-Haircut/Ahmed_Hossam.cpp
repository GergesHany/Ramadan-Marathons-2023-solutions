#include <bits/stdc++.h>

using namespace std;

#define fixed(n) fixed << setprecision(n)
#define ceil(n, m) (((n) + (m) - 1) / (m))
#define add_mod(a, b, m) (((a % m) + (b % m)) % m)
#define sub_mod(a, b, m) (((a % m) - (b % m) + m) % m)
#define mul_mod(a, b, m) (((a % m) * (b % m)) % m)
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << (x) << "\n";
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define EPS 1e-9
constexpr int INF = 1 << 30, Mod = 1e9 + 7;
constexpr ll LINF = 1LL << 62;
#define PI acos(-1)
template < typename T = int > using Pair = pair < T, T >;
vector < string > RET = {"NO", "YES"};

template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x : v) in >> x;
    return in;
}

template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) { 
    for (const T &x : v) out << x << ' '; 
    return out;
}

void Solve(){
    int n;
    cin >> n;
    
    // create a vector with size n+5 that stores the input values
    vector < ll > a(n + 5);
    
    // fill the vector with input values
    for(int i = 1; i <= n; i++)
        cin >> a[i];
        
    // set a large value as the initial minimum cost
    ll minCost = LINF;
    
    // lambda function that calculates the cost of a specific operation
    auto calc_cost = [&](int i, int j){
        ll cost = (a[j] % i == 0 ? 0 : i - (a[j] % i)) + abs(j - i);
        ll x = a[j] + (a[j] % i == 0 ? 0 : i - (a[j] % i));
        cost += (x / i) + i;
        return cost;
    };
    
    // nested loop that iterates over all possible i and j values and finds the minimum cost
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            minCost = min(minCost, calc_cost(i, j));
    
    // output the minimum cost
    cout << minCost << '\n';
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int test_cases = 1;
    cin >> test_cases;
    for(int tc = 1; tc <= test_cases; tc++){
        // cout << "Case #" << tc << ": ";
        Solve();
    }
    return 0;
}
