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
    // Declare variable n and get the input
    ll n;
    cin >> n;
    // Multiply n by 2 and declare vector a with size n
    n *= 2;
    vector < ll > a(n);
    // Get the input values and store them in vector a
    cin >> a;
    // Sort the values in vector a in ascending order
    sort(all(a));
    // Declare vector vis with size n
    vector < bool > vis(n);
    // Loop through the values in vector a
    for(int i = 0, j = 0; i < n; i++){
        // Check if the current value in vector a is divisible by 4
        if(a[i] % 4 == 0){
            // Calculate the target value for the current value in vector a
            ll target = a[i] - (a[i] / 4);
            // Find the first value in vector a that is greater than or equal to the target value
            // and has not been visited yet
            while(j < i && (a[j] < target || vis[j])) j++;
            // Check if the target value has been found and mark the current and target values as visited
            if(j < n && a[j] == target && !vis[j]){
                cout << target << " ";
                vis[i] = vis[j] = true;
            }
        }
    }
    // Output a newline character
    cout << "\n";
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
