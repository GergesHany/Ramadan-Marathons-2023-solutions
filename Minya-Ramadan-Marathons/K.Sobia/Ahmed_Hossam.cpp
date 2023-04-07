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

// This function solves a problem that requires finding the maximum possible value x
// such that there are no more than M segments in an array of n integers a,
// where each segment has a sum that is at most x.
void Solve() {
    
    // Declare and initialize n and M, and read their values from standard input.
    int n, M;
    cin >> n >> M;

    // Declare a vector of long long integers a of size n, and read its values from standard input.
    vector < ll > a(n);
    cin >> a;

    // Sort the elements in vector a in non-decreasing order.
    sort(all(a));

    // Define a lambda function is_good that takes a long long integer x and returns a boolean value.
    auto is_good = [&](ll x){
        
        // Declare and initialize two long long integers sum and cnt to 0 and 1, respectively.
        ll sum = 0, cnt = 1;

        // Loop through all elements in vector a.
        for(auto& v : a){

            // If an element is greater than x, return false.
            if(v > x)
                return false;

            // Otherwise, add the element's value to sum.
            sum += v;

            // If the current sum exceeds x, increment cnt and set sum to the current element's value.
            if(sum > x)
                sum = v, cnt++;
        }

        // If the number of segments is less than or equal to M, return true; otherwise, return false.
        return cnt <= M;
    };

    // Declare and initialize three long long integers l, r, and ans to 1, 1e18, and -1, respectively.
    ll l = 1, r = 1e18, ans = -1;

    // Loop until l is greater than r.
    while(l <= r){

        // Compute the midpoint m of l and r.
        ll m = l + (r - l) / 2;

        // If is_good(m) returns true, set r to m - 1 and ans to m; otherwise, set l to m + 1.
        (is_good(m) ? r = m - 1, ans = m : l = m + 1);
    }

    // Print the value of ans to standard output followed by a newline character.
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
