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

// This function takes an input integer n and constructs a grid with 5 rows.
void Solve(){
    int n;
    cin >> n;
    vector < string > grid(5);

    // For each input integer x in the range [0,n), it constructs 5 rows of the grid.
    for(int i = 0; i < n; i++){
        for(int j = 0, x; j < 5 && cin >> x; j++){
            // For each bit in x, if the bit is 1, it adds a '*' character to the current row of the grid.
            // Otherwise, it adds a ' ' (space) character.
            for(int b = 5; b >= 0; b--)
                grid[j] += (x & (1 << b) ? '*' : ' ');
        }
    }

    // Prints the constructed grid, excluding the first character of each row.
    for(int i = 0; i < 5; i++){
        for(int j = 1; j < sz(grid[i]); j++)
            cout << grid[i][j];
        cout << " \n";
    }
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
