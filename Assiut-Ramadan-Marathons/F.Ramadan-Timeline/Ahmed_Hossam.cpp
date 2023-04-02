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

// The Time structure is defined with hour, minute, and second fields, as well as some useful methods and operator overloading.
struct Time {
    ll h, m, s;
 
    // Constructor to set the Time fields with provided parameters.
    Time(ll H = 0, ll M = 0, ll S = 0){
        h = H, m = M, s = S;
    }

    // Constructor to set the Time fields with provided string input.
    Time(const string& S){
        h = stoi(S.substr(0, 2));
        m = stoi(S.substr(3, 2));
        s = stoi(S.substr(6, 2));
    }

    // Operator overloading for less than operation for comparing two Time objects.
    bool operator < (const Time &t) const {
        if (h != t.h) return h < t.h;
        if (m != t.m) return m < t.m;
        return s < t.s;
    }

    // Operator overloading for equality operation for comparing two Time objects.
    bool operator == (const Time &t) const {
        return h == t.h && m == t.m && s == t.s;
    }

    // Method to get the total number of seconds in the Time object.
    ll Seconds(){
        return h * 3600 + m * 60 + s;
    }

    // Operator overloading for subtraction operation to get the difference in seconds between two Time objects.
    ll operator - (Time &t) {
        return Seconds() - t.Seconds();
    }
};

// Function to solve the problem.
void Solve(){
    // Declare a map to store the opening times for each day of the week.
    map < string, Time > D;
    // Take input for the opening times of each day.
    for(int i = 0; i < 7; i++){
        string day, time;
        cin >> day >> time;
        D[day] = Time(time);
    }
    // Declare a vector to store the days of the week.
    vector < string > days = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    // Take input for the number of queries.
    int q;
    cin >> q;
    // Loop through each query and find the minimum number of seconds until the store opens.
    while(q--){
        string day, time;
        cin >> day >> time;
        Time t = Time(time);
        ll seconds = LINF;
        // Loop through each day of the week and find the opening time that is closest to the current time.
        for(int i = 0; i < 7; i++){
            if(days[i] == day){
                if(t < D[days[i]])
                    seconds = min(seconds, (D[days[i]] - t));
                else {
                    Time nxt = D[days[(i + 1) % 7]];
                    if(t < nxt)
                        seconds = min(seconds, (nxt - t) + 24 * 3600);
                    else 
                        seconds = min(seconds, 24 * 3600 - (t - nxt));
                }
                break;
            }
        }
        // Output the minimum number of seconds until the store opens.
        cout << seconds << '\n';
    }
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
