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

// This function takes a vector of integers and returns a vector
// containing the indices of the next greater element for each element in the input vector
template < typename T = int > vector < T > nextGreaterelement(vector < T >& nums) {
    int n = nums.size();
    vector < T > res(n);
    stack < int > st;
    // loop through the input vector from the end
    for (int i = n - 1; i >= 0; i--) {
        // keep popping elements from the stack until we find an element greater than the current element
        while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
        // if the stack is empty, there is no greater element to the right of the current element
        res[i] = (st.empty() ? -1 : st.top());
        // push the current element's index onto the stack
        st.push(i);
    }
    return res;
}

// This function takes a vector of integers and returns a vector
// containing the indices of the previous greater element for each element in the input vector
template < typename T = int > vector < T > prevGreaterelement(vector < T >& nums) {
    int n = nums.size();
    vector < T > res(n);
    stack < int > st;
    // loop through the input vector from the start
    for (int i = 0; i < n; i++) {
        // keep popping elements from the stack until we find an element greater than the current element
        while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
        // if the stack is empty, there is no greater element to the left of the current element
        res[i] = (st.empty() ? -1 : st.top());
        // push the current element's index onto the stack
        st.push(i);
    }
    return res;
}

void Solve() {
    int n;
    cin >> n;
    vector < ll > a(n);
    cin >> a;
    // get vectors of the next greater element and the previous greater element for the input vector
    vector < ll > nxt = nextGreaterelement(a);
    vector < ll > prv = prevGreaterelement(a);
    ll ans = 0;
    // loop through the input vector
    for (int i = 0; i < n; i++) {
        // if the current element is equal to n, skip it
        if (a[i] == n) continue;
        // get the index of the next greater element and the index of the previous greater element
        ll currnxt = ~nxt[i] ? nxt[i] : i;
        ll currprv = ~prv[i] ? prv[i] : i;
        // calculate the distance between the current element and the next greater element,
        // and the distance between the current element and the previous greater element,
        // and add them together
        ans = max(ans, (currnxt - i) + (i - currprv));
    }
    // output the answer
    cout << ans << '\n';
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
