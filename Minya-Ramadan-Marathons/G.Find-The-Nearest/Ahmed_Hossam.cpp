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
    // Declare x and z as long long integers
    ll x, z;
    // Input values for x and z
    cin >> x >> z;
    // If both x and z are equal to 0, output 1 and exit the function
    if(x == 0 && z == 0)
        return void(cout << 1 << '\n');
    // Declare l, r, and ans as long long integers and assign them values
    ll l = 1, r = 2 * x, ans = -1;
    // While l is less than or equal to r
    while(l <= r){
        // Calculate the midpoint of l and r and assign it to m
        ll m = l + (r - l) / 2;
        // If x divided by m is less than or equal to z
        if(x / m <= z){
            // Assign m to ans and subtract 1 from m, assign the result to r
            ans = m, r = m - 1;
        }
        // Otherwise, add 1 to m and assign the result to l
        else{
            l = m + 1;
        }
    }
    // If x divided by ans is equal to z, assign ans to ans. Otherwise, assign -1 to ans.
    ans = (x / ans == z ? ans : -1);
    // Output ans and a newline character
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
