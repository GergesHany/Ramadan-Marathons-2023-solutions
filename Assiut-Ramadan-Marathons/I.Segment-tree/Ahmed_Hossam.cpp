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

// Each update specifies a range of indices [l, r] and an increment x to be added to each element in that range.
void Solve(){
    // read input values
    int n, m;
    cin >> n >> m;
    // create a map to keep track of partial sums
    map < ll, ll > partial;
    // loop through each update and update the partial sums accordingly
    for(int i = 0; i < m; i++){
        ll l, r, x;
        cin >> l >> r >> x;
        partial[l] += x, partial[r + 1] -= x;
    }
    // compute the maximum element and its index by iterating through the partial sums
    ll maxBall = -1, maxIdx = -1, sum = 0;
    for(auto& [idx, cnt] : partial){
        sum += cnt;
        if(sum >= maxBall)
            maxBall = sum, maxIdx = partial.upper_bound(idx) -> first - 1;
    }
    // output the maximum element and its index
    cout << maxBall << " " << maxIdx << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int test_cases = 1;
    // cin >> test_cases;
    for(int tc = 1; tc <= test_cases; tc++){
        // cout << "Case #" << tc << ": ";
        Solve();
    }
    return 0;
}
