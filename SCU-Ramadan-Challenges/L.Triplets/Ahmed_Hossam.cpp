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
    int n;
    cin >> n;
    // Create the input vector
    vector < int > a(n);
    cin >> a;
    // Sort the input vector
    sort(all(a));
    // Create a map to store the occurrence of elements in the input vector
    map < int, set < Pair < int > > > occ;
    // Create a set to store the found triplets
    set < vector < int >, greater < vector < int > > > triplets;
    // Loop through each element of the input vector to find triplets
    for(int i = 0; i < n; i++){
        // Initialize two pointers to find the sum of three elements
        int l = i + 1, r = n - 1;
        while(l < r){
            // Calculate the sum of three elements
            int sum = a[i] + a[l] + a[r];
            // If the sum is zero, add the triplet to the set of found triplets and move the pointers
            if(sum == 0)
                triplets.insert({a[i], a[l], a[r]}), l++, r--;
            // If the sum is less than zero, move the left pointer
            else if(sum < 0)
                l++;
            // If the sum is greater than zero, move the right pointer
            else
                r--;
        }
    }
    // If no triplets were found, return -1
    if(triplets.empty())
        return cout << -1 << "\n", void();
    // Otherwise, print the number of found triplets and the triplets themselves
    cout << sz(triplets) << '\n';
    for(auto& v : triplets)
        cout << v << '\n';
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
