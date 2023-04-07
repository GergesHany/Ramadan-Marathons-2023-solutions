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

// Function to find the minimal rotated string using Booth's Algorithm
string boothAlgorithm(string str) {
    // Append the string with itself to handle circularity
    int n = str.size();
    str += str;
    int i = 0, j = 1, k = 0;
 
    // Booth's algorithm to find minimal rotated string
    while (i < n && j < n && k < n) {
        if (str[i + k] == str[j + k])
            k++;
        else {
            if (str[i + k] > str[j + k])
                i = i + k + 1;
            else
                j = j + k + 1;
 
            if (i == j) j++;
            k = 0;
        }
    }
    // Store the index of the minimal rotated string
    int idx = min(i, j);
    // Return the minimal rotated string
    return str.substr(idx, n);
}

void Solve(){
    // Input the length of string and number of operations
    int n, k;
    cin >> n >> k;
    // Input the strings
    vector < string > a(n), rotated(n);
    cin >> a;

    // Rotate each string using Booth's algorithm
    for(int i = 0; i < n; i++) 
        rotated[i] = boothAlgorithm(a[i]);

    // Count the frequency of each rotated string using map
    map < string, int > freq;
    for(int i = 0; i < n; i++) 
        freq[rotated[i]]++;

    // Calculate the answer using the sum formula
    ll ans = 0;
    auto sum = [&](ll x){
        return x * (x - 1) / 2;
    };
    for(auto& [str, cnt] : freq)
        ans += sum(cnt);
    // Output the answer
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
