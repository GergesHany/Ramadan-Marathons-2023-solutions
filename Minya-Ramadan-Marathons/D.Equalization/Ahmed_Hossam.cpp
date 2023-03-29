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
// Set the maximum value of N and the value of MOD constant
constexpr int N = 1e6;
const int MOD = 998244353;

// Implement a function to compute the fast exponentiation of two integers
ll fast_pow(ll b, ll e){
    // Initialize the answer to 1
    ll ans = 1;
    // While the exponent is not zero
    while(e){
        // If the least significant bit of the exponent is set
        if(e & 1)
            // Multiply the answer by the base modulo the modulus
            ans = mul_mod(ans, b, MOD);
        // Square the base modulo the modulus
        b = mul_mod(b, b, MOD);
        // Divide the exponent by 2 (equivalent to a right shift)
        e >>= 1;
    }
    // Return the answer
    return ans;
}

// Implement the main solving function
void Solve(){
    // Read in the input number
    ll n;
    cin >> n;
    // Initialize x to 1
    ll x = 1;
    // Iterate from 1 to the square root of n
    for(int i = 1; i <= sqrt(n); i++){
        // If i is a factor of n
        if(n % i == 0){
            // Compute the other factor of n
            ll F = i, S = n / i;
            // Compute the logarithm-based score for each factor
            double a = n / F * log(F);
            double b = n / S * log(S);
            double c = n / x * log(x);
            // If a is the largest score, set x to F
            if(a == max({a, b, c}))
                x = F;
            // If b is the largest score, set x to S
            if(b == max({a, b, c}))
                x = S;
        }
    }
    // Output the fast exponentiation of x to the power of n divided by x
    cout << fast_pow(x, n / x) << "\n";
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
