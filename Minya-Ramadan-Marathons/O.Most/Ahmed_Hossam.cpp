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

// Function to count the number of subsequences containing a and b in s.
ll cnt_subsequence(char a, char b, string& s){
    ll suff = count(all(s), a), pref = 0, ans = 0;
    // Count the number of occurrences of 'a' in s, and initialize pref and suff to 0.
    // 'pref' represents the number of occurrences of 'a' before the current character, 
    // and 'suff' represents the number of occurrences of 'a' after the current character.
    for(char& c : s){
        if(c == a)
            pref++, suff--;
        // If the current character is 'a', update 'pref' and 'suff' accordingly.
        if(c == b)
            ans += pref * suff;
        // If the current character is 'b', add the product of 'pref' and 'suff' to 'ans'.
    }
    return ans;
}

// Function to calculate nCr for f.
ll nCr_Freq(ll f){
    if(f < 3) return 0;
    // If f < 3, nCr(f, 3) is 0.
    return f * (f - 1) * (f - 2) / 6;
    // Else, calculate nCr(f, 3) using the formula and return the value.
}

// Main function to solve the problem.
void Solve(){
    int n;
    string s;
    cin >> n >> s;
    // Input n and s.
    vector < ll > freq(26);
    // Initialize a vector freq to keep track of the frequency of each character in s.
    for(char& c : s)
        freq[c - 'a']++;
    // Calculate the frequency of each character in s.
    ll maxAns = 0;
    string ans = "{{{";
    // Initialize maxAns to 0 and ans to "{{{".
    auto make_string = [&](char a, char b){
        string ret = "";
        ret += a, ret += b, ret += a;
        return ret;
    };
    // Define a lambda function to create a string of the form "a...a" or "aba" given two characters a and b.
    for(char a = 'a'; a <= 'z'; a++)
        for(char b = 'a'; b <= 'z'; b++){
            if(a == b) continue;
            // If a == b, skip to the next iteration.
            ll cnt = cnt_subsequence(a, b, s);
            // Calculate the number of subsequences containing a and b in s.
            if(maxAns < cnt)
                maxAns = cnt, ans = make_string(a, b);
            // If cnt is greater than maxAns, update maxAns to cnt and ans to the string created using a and b.
            else if(maxAns == cnt && cnt)
                ans = min(ans, make_string(a, b));
            // If cnt is equal to maxAns and not equal to 0, update ans to the lexicographically smallest string created using a and b.
        }
    for(char a = 'a'; a <= 'z'; a++){
        ll cnt = nCr_Freq(freq[a - 'a']);
        // Calculate the number of subsequences of length 3 that can be formed using the character a.
        if(maxAns < cnt)
            maxAns = cnt, ans = make_string(a, a);
        // If cnt is greater than maxAns, update maxAns to cnt and ans to the string created using a.
        else if(maxAns == cnt && cnt)
         	ans = min(ans, make_string(a, a));
	}
    cout << (ans == "{{{" ? "-1" : ans) << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int test_cases = 1;
    cin >> test_cases;
    for(int tc = 1; tc <= test_cases; tc++){
        // cout << "Case #" << tc << ": ";
        Solve();
    }
    return 0;
}
