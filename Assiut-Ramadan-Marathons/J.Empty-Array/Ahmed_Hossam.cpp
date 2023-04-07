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
    int n, q;
    cin >> n >> q;
    vector < ll > nums(n);
    set < int > Idx;

    // Insert index values into the set
    for(int i = 0; i < n; i++)
        Idx.insert(i);

    // Process queries
    while(q--){
        ll type, x, idx;
        cin >> type >> x;
        if(type == 1){
            cin >> idx;
            // Add value to nums array at given index
            nums[idx] += x;
            
            // If index is in the set, remove it
            if(Idx.count(idx))
                Idx.erase(idx);

            // If value at given index is non-zero, add it to the set
            if(!nums[idx])
                Idx.insert(idx);
        }
        else {
            // If set is empty, continue to next iteration
            if(Idx.empty()) continue;
            
            // Get the first index in the set
            idx = *Idx.begin();
            
            // Add value to nums array at first index in set
            nums[idx] += x;
            
            // If value at first index is non-zero, remove it from the set
            if(nums[idx])
                Idx.erase(idx);
        }
    }
    // the answer
    cout << nums << "\n";
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
