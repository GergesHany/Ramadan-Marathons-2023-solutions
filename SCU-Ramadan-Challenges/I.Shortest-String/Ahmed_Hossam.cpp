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

    // The length of the input string.
    int n = s.size();
    
    // This lambda function receives a possible size of the substring and returns whether this size is valid or not.
    auto try_size = [&](int sz){
        // The loop iterates over all possible repetitions of the substring with size 'sz'.
        for(int i = sz; i + sz - 1 < n; i += sz){
            // If the first substring and the current substring are different, the size is not valid.
            if(s.substr(0, sz) != s.substr(i, sz))
                return false;
        }
        // If all repetitions were equal, the size is valid.
        return true;
    };
 
    // The minimum size of the substring that, when repeated, forms the entire string.
    int MinSize = n;
 
    // This loop iterates over all possible sizes of a substring that can form the entire string.
    for(int i = 1; i <= sqrt(n); i++){
        // If the size is a divisor of the length of the string, it is a valid size.
        if(n % i == 0){
            // If the current size is valid, update the minimum size if necessary.
            if(try_size(i))
                MinSize = min(MinSize, i);
            if(try_size(n / i))
                MinSize = min(MinSize, n / i);
        }
    }
 
    // If no valid size was found, set the minimum size to -1.
    if(MinSize == n)
        MinSize = -1;
 
    // Print the minimum size.
    cout << MinSize << '\n';
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
