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

// This function computes the Euler's totient function (phi) of a given integer n.
ll phi(int n) {
    // Initialize the result variable with n.
    int result = n;

    // Loop through all the possible factors i of n.
    for (int i = 2; i * i <= n; i++) {
        // If i is a factor of n, remove all the factors of i from n and subtract from result.
        if (n % i == 0) {   
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }

    // If n is still greater than 1, subtract the contribution of n from result.
    if (n > 1)
        result -= result / n;
    
    // Return the final result.
    return result;
}

void Solve(){
    // Take input.
    int n;
    cin >> n;

    // Print the output of phi(n).
    cout << phi(n) << '\n';
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
