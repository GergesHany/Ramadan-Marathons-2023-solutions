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
    // Read the number of lines per page.
    int n;
    cin >> n;
    // Read the text as a string, including leading white spaces, and store it in variable s.
    string s;
    getline(cin >> ws, s);
    // Create a vector of integers to store the size of each word in the text, and initialize currSz to 0.
    vector < int > Sz;
    int currSz = 0;
    // Iterate over each character in the text.
    for(auto& c : s){
        // If the character is a space or a dot, the size of the current word is complete, so add it to the vector and reset currSz to 0.
        if(c == ' ' || c == '.')
            Sz.push_back(currSz), currSz = 0;
        // Otherwise, increment the size of the current word.
        else
            currSz++;
    }
    // If currSz is not zero, there is one more word left to add to the vector.
    if(currSz)
        Sz.push_back(currSz);
    // Define a lambda function is_good to check if the given page size is enough for the text to be printed in n pages or less.
    auto is_good = [&](int m){
        // Initialize cnt to 1 and currPage to 0.
        int cnt = 1, currPage = 0;
        // Iterate over each word size in the vector Sz.
        for(auto& sz : Sz){
            // If the size of the word is greater than the given page size, return false.
            if(sz > m)
                return false;
            // If the size of the word plus the current page size is less than or equal to the given page size, add the size of the word to the current page size.
            if(currPage + sz <= m)
                currPage += sz;
            // Otherwise, start a new page with the size of the current word, and increment cnt.
            else
                currPage = sz, cnt++;
        }
        // Return true if cnt is less than or equal to n, false otherwise.
        return cnt <= n;
    };
    // Initialize l to 1, r to 1e9, and ans to -1.
    int l = 1, r = 1e9, ans = -1;
    // Use binary search to find the smallest page size that satisfies the condition in is_good.
    while(l <= r){
        int m = l + (r - l) / 2;
        (is_good(m) ? r = m - 1, ans = m : l = m + 1);
    }
    // Print the answer.
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
