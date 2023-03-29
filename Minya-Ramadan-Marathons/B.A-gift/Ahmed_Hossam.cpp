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

// Define the function to solve the problem
void Solve(){
    // Define an integer variable n and read its value from input
    ll n;
    cin >> n;

    // Define three integer variables l, r, and ans and initialize l and r to 1 and ans to -1
    ll l = 1, r = 1, ans = -1;

    // Define a lambda function is_good which takes an integer argument x and returns a boolean value
    // The function checks if x plus x divided by 3 is greater than or equal to n
    auto is_good = [&](ll x){
        return x + (x / 3) >= n;
    };

    // Find the first power of 2 that is greater than or equal to the value of n
    while(!is_good(r)) r *= 2;

    // Use binary search to find the smallest value of m such that is_good(m) is true
    while(l <= r){
        ll m = l + (r - l) / 2;
        (is_good(m) ? r = m - 1, ans = m : l = m + 1);
    }

    // Output the value of ans followed by a newline character
    cout << ans << '\n';
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
