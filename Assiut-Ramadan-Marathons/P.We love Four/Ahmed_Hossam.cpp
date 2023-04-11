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

// This function solves a problem that checks if a given sequence can be divided into pairs such that each pair's sum is divisible by 4
void Solve(){

    // Read the length of the sequence
    int n;
    cin >> n;

    // Read the sequence into a vector
    vector < int > a(n);
    cin >> a;

    // Count the number of elements that are divisible by 4, by 2 but not by 4, and odd numbers
    int cnt4 = 0, cnt = 0, cnt2 = 0;
    for(auto& x : a){
        if(x % 4 == 0) cnt4++;
        else if(x % 2 == 0) cnt2++;
        else cnt++;
    }

    // If there are an odd number of elements that are divisible by 2 but not by 4, remove one of them
    cnt2 &= 1;

    // Check if it is possible to divide the sequence into pairs such that each pair's sum is divisible by 4
    if(cnt + cnt2 <= cnt4 + (cnt4 > 0))
        cout << "Yes\n";
    else
        cout << "No\n";    
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
