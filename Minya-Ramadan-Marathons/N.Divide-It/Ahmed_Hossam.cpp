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

void Solve() {
    // Read integer n from input.
    int n;
    cin >> n;

    // Initialize vector a with size n and read n integers from input into a.
    vector < int > a(n);
    cin >> a;

    // Initialize vector freq with size 1e6 + 5 to keep track of the frequency of each integer in a.
    vector < int > freq(1e6 + 5);

    // Initialize GCD to zero.
    int GCD = 0;

    // Count the frequency of each integer in a and update freq.
    for(int i = 0; i < n; i++) {
        freq[a[i]]++;
    }

    // Compute the GCD of the frequencies of integers in a and update GCD.
    for(int i = 0; i < n; i++) {
        GCD = __gcd(GCD, freq[a[i]]);
    }

    // Output "YES" if GCD is greater than one, otherwise output "NO".
    cout << RET[GCD > 1] << '\n';
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
