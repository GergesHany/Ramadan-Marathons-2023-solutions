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

// This function solves a problem that compares two input vectors
void Solve(){
    int n, m;
    // Taking input values for n and m
    cin >> n >> m;
    
    // Initializing two vectors a and b with n and m elements respectively
    vector < int > a(n), b(m);
    
    // Taking input values for vector a and vector b
    cin >> a >> b;
    
    // Defining a lambda function named get_vector which returns a vector of pairs
    auto get_vector = [&](vector < int >& v){
        vector < Pair < int > > ans;
    
        // Initializing current count and element value to 0 and -1 respectively
        int curr = 0, element = -1;
        
        // Looping over the elements in vector v
        for(int i = 0; i < sz(v); i++){
            // If element value is -1 or same as v[i], increase the current count and set element to v[i]
            if(element == -1 || element == v[i])
                curr++, element = v[i];
            // If element value is not same as v[i], add the (element, count) pair to ans vector and reset the curr and element values
            else{
                ans.emplace_back(element, curr);
                element = v[i], curr = 1;
            }
        }

        // Adding the last (element, count) pair to ans vector
        ans.emplace_back(element, curr);
        
        // Return ans vector
        return ans;
    };

    // Calling the get_vector function for vector a and vector b and storing the results in A and B vectors
    vector < Pair < int > > A = get_vector(a);
    vector < Pair < int > > B = get_vector(b);    
    
    // If size of vector A is not equal to size of vector B, return "NO"
    if(A.size() != B.size())
        return cout << "NO\n", void();
    
    // Looping over the pairs of vectors A and B
    for(int i = 0; i < sz(A); i++){
        // If the first value of the ith pair of vector A is not same as the first value of the ith pair of vector B, return "NO"
        if(A[i].first != B[i].first)
            return cout << "NO\n", void();
    
        // If the second value of the ith pair of vector A is less than the second value of the ith pair of vector B, return "NO"
        if(A[i].second < B[i].second)
            return cout << "NO\n", void();
    }
    
    // If none of the above conditions are satisfied, return "YES"
    cout << "YES\n";
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
