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


// Declare a struct named Prefix_2D that is a template class
// It has a template parameter T that defaults to int
template < typename T = int > struct Prefix_2D {
 
    // Declare two integers n and m
    // Declare a 2D vector named prefix that stores elements of type T
    int n, m;
    vector < vector < T > > prefix;
    
    // Constructor function
    Prefix_2D(int N = 0, int M = 0){
        n = N, m = M;
        prefix.assign(n + 5, vector < T > (m + 5));
    }
 
    // Get the sum of the number in the rectangle between x1, y1, x2, y2
    T Get_Query(int x1, int y1, int x2, int y2){
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);
        return prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1];
    }
 
    // Build prefix sum matrix from the given matrix
    void Build_Prefix(vector < vector < T > >& matrix){
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                prefix[i][j] = matrix[i - 1][j - 1] + prefix[i][j - 1] + prefix[i - 1][j] - prefix[i - 1][j - 1];
    }
 
    // Print the prefix sum matrix
    void Print_Prefix(){
        for(int i = 1; i <= n; i++, cout << '\n')
            for(int j = 1; j <= m && cout << prefix[i][j] << ' '; j++);
    }
    
};

void Solve(){
    int n, m;
    cin >> n >> m;
    // Declare a 2D vector named matrix that stores elements of type ll
    vector < vector < ll > > matrix(n, vector < ll > (n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> matrix[i][j];
    // Declare an object of the Prefix_2D class named prefix that stores elements of type ll
    Prefix_2D < ll > prefix(n, n);
    prefix.Build_Prefix(matrix);
    ll MaxScore = 0;
    for(int i = 1; i + m - 1 <= n; i++)
        for(int j = 1; j + m - 1 <= n; j++){
            ll score = prefix.Get_Query(i, j, i + m - 1, j + m - 1);
            MaxScore = max(MaxScore, score);
        }
    cout << MaxScore << '\n';
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
