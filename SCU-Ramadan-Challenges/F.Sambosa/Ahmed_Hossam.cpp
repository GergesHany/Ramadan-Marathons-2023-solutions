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
    // Read input n
    int n;
    cin >> n;

    // Read input P, Q, R and calculate Tot
    ll P, Q, R, Tot;
    cin >> P >> Q >> R;
    Tot = P + Q + R;

    // Read input vector a of length n
    vector < ll > a(n);
    cin >> a;

    // Initialize variables
    ll sum = 0, l = 0, r = 0;

    // Loop through the vector
    while(r < n){
        // Add elements of the vector to the sum until the sum exceeds Tot
        while(r < n && sum + a[r] <= Tot)
            sum += a[r++];

        // If the sum equals Tot
        if(sum == Tot){
            // Initialize variables and loop through the sum
            ll sum1 = 0, sum2 = 0, sum3 = 0, idx = l;
            while(idx < r && sum1 + a[idx] <= P)
                sum1 += a[idx++];
            while(idx < r && sum2 + a[idx] <= Q)
                sum2 += a[idx++];
            while(idx < r && sum3 + a[idx] <= R)
                sum3 += a[idx++];

            // If the sum1 equals P, sum2 equals Q and sum3 equals R, output "YES" and return
            if(sum1 == P && sum2 == Q && sum3 == R)
                return cout << "YES\n", void();
        }

        // Subtract the left element from the sum and move the left index to the right
        sum -= a[l++];
    }

    // If the loop ends without returning, output "NO"
    cout << "NO\n";
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
