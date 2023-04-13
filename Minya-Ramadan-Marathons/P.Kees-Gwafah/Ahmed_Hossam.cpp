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

// Function to find the LCM of two numbers a and b
ll LCM(ll a, ll b){
    return a / __gcd(a, b) * b;
}

// Main function to solve the problem
void Solve(){
    // Reading input values
    int n, m;
    cin >> n >> m;

    // Creating a 2D vector to store the grid values
    vector < vector < ll > > grid(n + 5, vector < ll > (m + 5));

    // Reading the grid values
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> grid[i][j];

    // Creating 2D vectors to store prefix and suffix LCMs for rows and columns
    vector < vector < ll > > pre_row(n + 5, vector < ll > (m + 5, 1));
    vector < vector < ll > > pre_col(n + 5, vector < ll > (m + 5, 1));
    vector < vector < ll > > suff_col(n + 5, vector < ll > (m + 5, 1));
    vector < vector < ll > > suff_row(n + 5, vector < ll > (m + 5, 1));

    // Finding prefix LCMs for rows
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            pre_row[i][j] = LCM(pre_row[i][j - 1], grid[i][j]);

    // Finding prefix LCMs for columns
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            pre_col[i][j] = LCM(pre_col[i - 1][j], grid[i][j]);

    // Finding suffix LCMs for rows
    for(int i = n; i >= 1; i--)
        for(int j = m; j >= 1; j--)
            suff_row[i][j] = LCM(suff_row[i][j + 1], grid[i][j]);

    // Finding suffix LCMs for columns
    for(int i = n; i >= 1; i--)
        for(int j = m; j >= 1; j--)
            suff_col[i][j] = LCM(suff_col[i + 1][j], grid[i][j]);

    // Initializing the answer
    ll ans = 0;

    // Looping through all the cells in the grid
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            // Finding the LCM of prefix and suffix without the current cell for both row and column
            ll without_row = LCM(pre_row[i][j - 1], suff_row[i][j + 1]);
            ll without_col = LCM(pre_col[i - 1][j], suff_col[i + 1][j]);
            ll without_cell = LCM(without_row, without_col);

            // Finding the LCM of prefix with the last cell in the row and prefix with the last cell in the column
            ll with_row = pre_row[i][m];
            ll with_col = pre_col[n][j];
            ll with_cell = LCM(with_row, with_col);

            // Adding 1 to the answer if the LCM with and without the current cell is the same
            ans += (without_cell == with_cell);
        }

    // Printing the answer
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
