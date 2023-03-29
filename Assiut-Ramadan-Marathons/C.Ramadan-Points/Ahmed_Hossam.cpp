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

// A function to solve a problem that finds the maximum difference between any two elements of an array 
void Solve(){
    int n;  // declare a variable n to store the size of the array
    cin >> n;  // get the size of the array from the user
    vector < int > a(n);  // declare a vector a of size n to store the array
    cin >> a;  // get the array elements from the user
    sort(all(a));  // sort the array in ascending order using the sort function from the algorithm library
    priority_queue < int > pq;  // declare a priority queue pq to store the maximum 3 differences
    for(int i = 0; i < n; i++){  // loop through each element of the array
        for(int j = i - 1; j >= max(0, i - 3); j--){  // loop through the previous 3 elements before the current element
            pq.push(a[i] - a[j]);  // push the difference between the current element and the previous element into the priority queue
            if(sz(pq) > 3)  // if the size of the priority queue is greater than 3
                pq.pop();  // remove the top element from the priority queue
        }
    }
    cout << pq.top() << '\n';  // output the top element of the priority queue, which will be the maximum difference
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
