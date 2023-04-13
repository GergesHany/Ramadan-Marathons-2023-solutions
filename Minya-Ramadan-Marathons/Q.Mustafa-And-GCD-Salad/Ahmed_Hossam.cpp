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

// inital variables
constexpr int N = 1e4;
vector < int > Div[N + 5];
vector < int > cnt(N + 5);

// make seive factorization
void build(){
    for(int i = 1; i <= N; i++)
        for(int j = i; j <= N; j += i)
            Div[j].push_back(i);
}

void Solve(){
    // initialize variables
    int n, k;
    cin >> n >> k;

    // create a vector and read its elements from input
    vector < int > a(n);
    cin >> a;

    // find the maximum element in vector a
    int maxGCD = 1;

    // initialize the cnt vector with zeros
    fill(all(cnt), 0);

    // lambda function to add divisors to the cnt vector
    auto add_divisors = [&](int x){
        for(auto& d : Div[x]){
            cnt[d]++;
            if(cnt[d] == k)
                maxGCD = max(maxGCD, d);
        }
    };

    // loop through vector a and add divisors to the cnt vector
    for(auto& x : a)
        add_divisors(x);

    // print the maximum gcd
    cout << maxGCD << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int test_cases = 1;
    cin >> test_cases;
    build();
    for(int tc = 1; tc <= test_cases; tc++){
        // cout << "Case #" << tc << ": ";
        Solve();
    }
    return 0;
}
