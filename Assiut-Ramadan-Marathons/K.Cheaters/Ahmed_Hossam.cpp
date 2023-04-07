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
    string s;
    cin >> s;

    // Count the number of 0's and 1's in the input string s.
    ll suff_0 = count(all(s), '0'), suff_1 = count(all(s), '1');

    // Initialize prefix counts and the answer.
    ll pref_0 = 0, pref_1 = 0, ans = 0;

    // Iterate over each character in the string s.
    for(int i = 0; i < sz(s); i++){
        // Increment prefix counts based on the current character.
        (s[i] == '0' ? pref_0 : pref_1)++;

        // Decrement suffix counts based on the current character.
        (s[i] == '0' ? suff_0 : suff_1)--;

        // Update the answer based on the current character.
        ans += (s[i] == '0' ? pref_1 * suff_1 : pref_0 * suff_0);
    }

    // Print the answer.
    cout << ans << '\n';
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
