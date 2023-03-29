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

// Declare the required variables
int n, ra, rb;
vector < int > a, b, c;
// The three vectors a, b, and c will be used to store the values for each item. 

// Declare a 3D array dp to store the minimum cost at each index, given the remaining red and blue items.
int dp[45][405][405];

// Define a function to calculate the minimum cost required to reach the target configuration.
int min_cost(int idx, int R, int B){
    // Base case: if all items have been processed and at least one item of each color is present.
    if(idx == n) {
        if(R == 0 || B == 0) return INF; // Return infinity if one of the colors has no items left.
        int g = __gcd(R, B); // Calculate the gcd of remaining red and blue items.
        R /= g, B /= g; // Divide remaining red and blue items by gcd.
        // If the remaining configuration is the target configuration, return 0, otherwise return infinity.
        return (R == ra && B == rb) ? 0 : INF;
    }
    // If the minimum cost at this index has already been calculated, return the value.
    int &ret = dp[idx][R][B];
    if(~ret) return ret;
    // Otherwise, recursively calculate the minimum cost by either skipping this item or choosing it and updating the remaining red and blue items.
    ret = min_cost(idx + 1, R, B);
    ret = min(ret, min_cost(idx + 1, R + a[idx], B + b[idx]) + c[idx]);
    return ret;
}

// Define the main function to read inputs, initialize variables, and call the min_cost function to obtain the answer.
void Solve(){
    cin >> n >> ra >> rb; // Read the number of items and the target configuration.
    a = b = c = vector < int > (n); // Initialize the three vectors to size n.
    int gg = __gcd(ra, rb); // Calculate the gcd of the target configuration.
    ra /= gg, rb /= gg; // Divide the target configuration by gcd.
    // Read the values for each item into the respective vectors.
    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i];
    memset(dp, -1, sizeof(dp)); // Initialize all values in the dp array to -1.
    int ans = min_cost(0, 0, 0); // Call the min_cost function with initial values of 0.
    // If the minimum cost is infinity, output -1, otherwise output the minimum cost.
    cout << (ans == INF ? -1 : ans) << '\n';
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
