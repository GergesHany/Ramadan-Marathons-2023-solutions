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

/*
This function takes an integer input 'n' from the user, 
and stores it as the size of a vector 'a' of type ll. 

A map 'freq' of type <ll,ll> is declared to store the frequency of each element in 'a'.

'MaxFreq' is initialized to 0 and will be used to keep track of the maximum frequency of an element in 'a'.

A loop is run 'n' times to take input of 'n' elements in 'a', 
increment the frequency of the element in the 'freq' map, 
and update the value of 'MaxFreq' if the current element's frequency is greater than the current maximum frequency.

Finally, the function outputs the maximum frequency 'MaxFreq' and the size of 'a' 'n' with a new line character '\n' appended.
*/

void Solve(){
    int n;
    cin >> n;
    vector < ll > a(n);
    map < ll, ll > freq;
    ll MaxFreq = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        freq[a[i]]++;
        MaxFreq = max(MaxFreq, freq[a[i]]);
    }
    cout << MaxFreq << " " << n << '\n';
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
