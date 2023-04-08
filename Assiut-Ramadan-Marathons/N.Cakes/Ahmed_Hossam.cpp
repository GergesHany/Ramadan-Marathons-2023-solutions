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
    // Declare three variables of long long data type
    ll n1, n2, n3;
    // Read three integers from input
    cin >> n1 >> n2 >> n3;
    
    // Calculate the number of cakes that can be made using half of n2
    ll cakes = (n2 / 2);
    // Update n2 to the remaining value of n2 after using half of it
    n2 = (n2 & 1);
    
    // Find the minimum value of n1 and n3 and add it to the cake count
    ll mn = min(n1, n3);
    cakes += mn, n1 -= mn, n3 -= mn;
    
    // If there is an odd number in n2 and n1 is greater than 1, add one more cake and update n1 and n2 accordingly
    if(n2 && n1 > 1)
        cakes++, n1 -= 2, n2--;
    
    // Calculate the number of cakes that can be made using the remaining pieces of n1
    cakes += n1 / 4;
    
    // Print the total number of cakes that can be made
    cout << cakes << "\n";
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
