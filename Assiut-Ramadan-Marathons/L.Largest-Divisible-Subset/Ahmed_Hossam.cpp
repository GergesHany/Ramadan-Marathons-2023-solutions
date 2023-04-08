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

constexpr int N = 1e6;
vector < vector < int > > divisors;

void Seive(){
    divisors = vector < vector < int > > (N + 5);
    for(int i = 1; i <= sqrt(N); i++)
        for(int j = i; j <= N; j += i)
            divisors[j].push_back(i);
}


int largestDivisibleSubset(vector < int >& nums) {
    Seive();
    int n = nums.size(), max_seq = 1;
    vector < int > dp(n, 1), best(1e6 + 5, -INF);
    sort(nums.begin(), nums.end());
    best[nums[0]] = 1;
    for(int i = 1; i < n; i++){
        for(auto& d : divisors[nums[i]]){
            if(best[d] != -INF)
                dp[i] = max(dp[i], best[d] + 1);
            if(best[nums[i] / d] != -INF)
                dp[i] = max(dp[i], best[nums[i] / d] + 1);
        }
        best[nums[i]] = max(best[nums[i]], dp[i]);
        max_seq = max(max_seq, dp[i]);
    }
    return max_seq;
}


void Solve(){
    int n;
    cin >> n;
    vector < int > nums(n);
    cin >> nums;
    cout << largestDivisibleSubset(nums) << '\n';
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
