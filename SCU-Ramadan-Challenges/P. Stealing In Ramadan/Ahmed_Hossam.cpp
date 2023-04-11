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
    //Variables for the sizes of the input arrays and the number of traps that can be set
    int n, m, k;
    //Read in values of n, m, and k
    cin >> n >> m >> k;
    //Declare vectors to store the input arrays, dividing the first one in half for optimization
    vector<ll> a(n/2), b(n - (n/2));
    //Read in values of the input arrays
    cin >> a >> b;
    //Declare two-dimensional vectors to store the sums of the different subsets of each input array
    vector<vector<ll>> trap(m + 5), trap2(m + 5);
    //Get the size of the two halves of the first input array
    int sz_a = sz(a), sz_b = sz(b);
    //Loop through all possible subsets of the first input array
    for(int mask = 0; mask < (1 << sz_a); mask++){
        //Declare variables to store the sum and number of bits in the subset
        ll sum = 0, bits = 0;
        //Loop through each bit of the mask, adding the corresponding element to the sum if the bit is set
        for(int i = 0; i < sz_a; i++){
            if(mask & (1 << i)) 
                sum += a[i], bits++;
        }
        //If the number of bits is less than or equal to m, add the sum to the corresponding vector
        if(bits <= m)
            trap[__builtin_popcount(mask)].push_back(sum);
    }
    //Sort each vector in the trap vector
    for(int i = 0; i <= m; i++)
        sort(all(trap[i]));
    //Declare variable to store the final answer
    ll ans = 0;
    //Loop through all possible subsets of the second input array
    for(int mask = 0; mask < (1 << sz_b); mask++){
        //Declare variables to store the sum and number of bits in the subset
        ll sum = 0, bits = 0;
        //Loop through each bit of the mask, adding the corresponding element to the sum if the bit is set
        for(int i = 0; i < sz_b; i++){
            if(mask & (1 << i)) 
                sum += b[i], bits++;
        }
        //If the number of bits is less than or equal to m, add the sum to the corresponding vector
        if(bits <= m)
            trap2[__builtin_popcount(mask)].push_back(sum);
    }
    //Sort each vector in the trap2 vector
    for(int i = 0; i <= m; i++)
        sort(all(trap2[i]));
    //Loop through all possible combinations of traps from the two input arrays
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= m - i; j++){
            //Loop through all sums in the i-th vector of trap
            for(int x : trap[i]){
                //Calculate the remaining sum needed for k using the current sum x
                ll rem = k - x;
                //If the remaining sum is negative, skip to the next sum
                if(rem < 0) continue;
                //Add the number of sums in the j-th vector of trap2 that are greater than or equal to rem
                ans += upper_bound(all(trap2[j]), rem) - trap2[j].begin();
            }
        }
    }
    //Print the final answer
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
