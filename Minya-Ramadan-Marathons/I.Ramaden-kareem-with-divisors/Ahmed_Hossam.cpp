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

// This is the upper limit for primes to sieve.
constexpr int N = 115;

// Initialize all numbers to be prime initially.
vector < ll > isPrime(N + 5, true), primes;

// Implementation of the Sieve of Eratosthenes algorithm to find all prime numbers up to N.
void Sieve(){
    // 0 and 1 are not prime numbers.
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i <= N; i++){
        if(isPrime[i]){
            // Add prime numbers to the list.
            primes.push_back(i);
            // Mark all multiples of the current prime number as composite.
            for(int j = i * i; j <= N; j += i)
                isPrime[j] = false;
        }
    }
}

// Function to calculate the highest power of prime p that divides n!.
ll FactN_PrimePowers(ll n, ll p){
    ll powers = 0;
    for(ll i = p; i <= n; i *= p)
        powers += n / i;
    return powers;
}

// A map that will store the precomputed factorizations.
map < ll, ll > fact;

// Precompute factorizations for all integers up to 115.
void build(){
    for(int i = 1; i <= N; i++){
        ll powers = 1;
        for(int j = 0; j < sz(primes); j++){
            if(primes[j] > i)
                break;
            powers *= FactN_PrimePowers(i, primes[j]) + 1;
        }
        fact[powers] = i;
    }
}

// The main function to solve the problem.
void Solve(){
    ll n;
    cin >> n;
    if(fact.count(n))
        cout << fact[n] << "\n";
    else
        cout << "Ramaden Kareem Ya Amoor\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int test_cases = 1;
    cin >> test_cases;
    Sieve();
    build();
    for(int tc = 1; tc <= test_cases; tc++){
        // cout << "Case #" << tc << ": ";
        Solve();
    }
    return 0;
}
