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
    double x, r; 
    cin >> x >> r;
    
    // Calculate the arc angle of the circular sector
    double arc_angle = acos(r / (x + r));
    
    // Calculate the length of the tangent side of the right triangle
    double tangent_side = sqrt(x * (x + r + r));
    
    // Calculate the area of the half circle
    double half_circle_area = r * r * PI * 0.5;
    
    // Calculate the area of the right triangle
    double triangle_area = 0.5 * tangent_side * r * sin(90 * PI / 180);
    
    // Calculate the area of the circular sector
    double circular_sector = 0.5 * arc_angle * r * r;
    
    // Calculate the area of the marked region
    double marked_area = half_circle_area - (circular_sector - triangle_area);
    
    // Output the marked area to standard output with fixed 6 decimal places
    cout<< fixed(6) << marked_area << "\n";
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
