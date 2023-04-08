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
    // Reading the size of the array
    int n;
    cin >> n;

    // Reading the array
    vector<ll> a(n);
    cin >> a;

    // Creating a vector of pairs to store the number and its frequency
    vector<Pair<ll>> pairs;

    // Initializing variables to store the current number and its frequency
    ll curr = a[0], sz = 1;

    // Looping through the array to find the frequency of each number
    for(int i = 1; i < n; i++){
        // If the current number is equal to the previous number, increment the frequency
        if(a[i] == curr) sz++;
        // If the current number is not equal to the previous number, add the previous number and its frequency to the vector of pairs and update the current number and its frequency
        else {
            pairs.push_back({curr, sz});
            curr = a[i], sz = 1;
        }
    }    

    // Adding the last number and its frequency to the vector of pairs
    pairs.push_back({curr, sz});

    // Initializing a variable to store the answer
    ll ans = 0;

    // Looping through the vector of pairs to find the maximum even frequency and the maximum frequency of a pair of adjacent numbers
    for(int i = 0; i < sz(pairs); i++){
        // Finding the maximum even frequency
        ans = max(ans, pairs[i].se - (pairs[i].se & 1));

        // If the current pair and the previous pair have different numbers, find the maximum frequency of a pair of adjacent numbers
        if(i)
            ans = max(ans, min(pairs[i].se, pairs[i - 1].se) * 2);
    }

    // Outputting the answer
    cout << ans << "\n";
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
