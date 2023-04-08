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

// A function to query a value x and return the result
ll query(ll x){
    // output the query to the console
    cout << "? " << x << endl;
    // flush the output to make sure the message is sent
    cout.flush();
    // read the result from the console
    ll ret;
    cin >> ret;
    // return the result
    return ret;
}

// A function to output the answer
void put_ans(ll x){
    // output the answer to the console
    cout << "! " << x << endl;
    // flush the output to make sure the message is sent
    cout.flush();
}

void Solve(){
    // Set the initial range for the answer
    ll l = 1, r = 1e15, ans = 0;

    // Use binary search to find the answer
    while(l <= r){
        // Compute the middle point of the range
        ll m = l + (r - l) / 2;
        // Query the value m - ans and update the range based on the result
        (query(m - ans) ? l = m + 1, ans += (m - ans) : r = m - 1);
    }

    // Output the final answer
    put_ans(ans);
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
