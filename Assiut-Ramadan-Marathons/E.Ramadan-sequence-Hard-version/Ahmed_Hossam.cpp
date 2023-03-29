#include <bits/stdc++.h>

using namespace std;

#define fixed(n) fixed << setprecision(n)
// #define ceil(n, m) (((n) + (m) - 1) / (m))
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

// Define function to check if a given number n can be represented as a sum of consecutive positive integers starting from 1
ll canBreakN(ll n){
    // Start checking from 2
    for (ll i = 2;; i++) {
        // Calculate sum of consecutive positive integers up to i
        ll m = i * (i + 1) / 2;
        // If the sum is greater than n, stop checking
        if (m > n) break;
        // Calculate the remaining number after subtracting the sum from n
        ll k = n - m;
        // If the remaining number cannot be divided by i, move to the next iteration
        if (k % i)
            continue;
        // If the remaining number can be divided by i, return i
        return i;
    }
    // If no such i is found, return 1
    return 1;
}
 
void Solve(){
    ll n;
    // Read input value n
    cin >> n;
    // Define lambda function to check if a given number can be represented as a sum of consecutive positive integers starting from 1
    auto is_summation = [&](ll x){
        // Calculate the positive integer S such that the sum of consecutive positive integers up to S is equal to x
        ll S = (sqrt(1 + 8 * x) - 1) / 2;
        // If the sum is correct, return true, otherwise return false
        return S * (S + 1) / 2 == x;
    };
    // Define lambda function to get the positive integer S such that the sum of consecutive positive integers up to S is equal to x
    auto get_x = [&](ll x){
        // Calculate the positive integer S such that the sum of consecutive positive integers up to S is equal to x
        ll S = (sqrt(1 + 8 * x) - 1) / 2;
        return S;
    };
    // If n can be represented as a sum of consecutive positive integers starting from 1, print the positive integer S such that the sum of consecutive positive integers up to S is equal to n
    if(is_summation(n))
        return cout << get_x(n) << '\n', void();
    // Otherwise, find the maximum length of consecutive positive integers that can sum up to n
    ll MaxLen = 1;
    // Start checking from 1
    for(ll i = 1; i * (i + 1) <= 2 * n; i++){
        // Calculate the sum of consecutive positive integers up to i
        ll S = i * (i + 1) / 2;
        // Calculate the remaining number after subtracting the sum from n
        ll x = n - S;
        // Calculate the length of consecutive positive integers that can sum up to x
        ll C = x / i;
        // If the length times i is equal to x and C is positive, update the maximum length
        if(C * i == x && C > 0)
            MaxLen = max(MaxLen, i);
    }
    // Print the maximum length
    cout << MaxLen << '\n';
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
