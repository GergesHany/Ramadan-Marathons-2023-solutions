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

constexpr int N = 1e6;
vector < ll > fact, inv;

ll fast_pow(ll b, ll e){
    ll ans = 1;
    while(e){
        if(e & 1) ans = mul_mod(ans, b, Mod);
        b = mul_mod(b, b, Mod);
        e >>= 1;
    }
    return ans;
}

void build(){
    fact = inv = vector < ll > (N + 5);
    fact[0] = inv[0] = 1;
    for(int i = 1; i <= N; i++) {
        fact[i] = mul_mod(fact[i - 1], i, Mod);
        inv[i] = fast_pow(fact[i], Mod - 2);
    }
}

ll nCr(int n, int r){
    if(r > n) return 0;
    return mul_mod(fact[n], mul_mod(inv[r], inv[n - r], Mod), Mod);
}

void Solve(){
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    for(int i = 1; i <= n; i++)
        ans = add_mod(ans, nCr(k, i), Mod);
    cout << ans << '\n';
}// Set a constant integer N to 10^6
constexpr int N = 1e6;
// Declare two vectors of long long integers for factorials and their inverses
vector < ll > fact, inv;
 
// Function to compute b^e modulo Mod using bit manipulation
ll fast_pow(ll b, ll e){
    // Initialize answer to 1
    ll ans = 1;
    // While exponent is non-zero
    while(e){
        // If exponent is odd, multiply answer by base modulo Mod
        if(e & 1) ans = mul_mod(ans, b, Mod);
        // Square base modulo Mod and divide exponent by 2
        b = mul_mod(b, b, Mod);
        e >>= 1;
    }
    // Return answer
    return ans;
}
 
// Function to build factorial and inverse factorial arrays up to N
void build(){
    // Resize fact and inv vectors to size N+5
    fact = inv = vector < ll > (N + 5);
    // Set 0th factorial and inverse factorial to 1
    fact[0] = inv[0] = 1;
    // Iterate over all integers from 1 to N
    for(int i = 1; i <= N; i++) {
        // Compute ith factorial modulo Mod using previous factorials
        fact[i] = mul_mod(fact[i - 1], i, Mod);
        // Compute inverse of ith factorial modulo Mod using Fermat's Little Theorem
        inv[i] = fast_pow(fact[i], Mod - 2);
    }
}
 
// Function to compute n choose r modulo Mod
ll nCr(int n, int r){
    // If r is greater than n, return 0
    if(r > n) return 0;
    // Compute n! * (r!)^-1 * ((n-r)!)^-1 modulo Mod using precomputed factorials and inverses
    return mul_mod(fact[n], mul_mod(inv[r], inv[n - r], Mod), Mod);
}
 
// Main function to solve the problem
void Solve(){
    // Read input values for n and k
    int n, k;
    cin >> n >> k;
    // Initialize answer to 0
    ll ans = 0;
    // Iterate over all integers from 1 to n and add n choose i modulo Mod to answer
    for(int i = 1; i <= n; i++)
        ans = add_mod(ans, nCr(k, i), Mod);
    // Print the answer and a newline character
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int test_cases = 1;
    cin >> test_cases;
    build();
    for(int tc = 1; tc <= test_cases; tc++){
        // cout << "Case #" << tc << ": ";
        Solve();
    }
    return 0;
}
