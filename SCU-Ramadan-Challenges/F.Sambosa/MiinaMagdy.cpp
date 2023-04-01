/*
+---------------------------------------------+
|                                             |
|  Copytright, MinaMagdy, 29/03/2023 (21:51)  |
|                                             |
+---------------------------------------------+
*/
/*
        .@@@@@@@@   @@@                                              @@       @@
    ,@@@@@@     @@ .@@@      @@    @@@        @@@%@@@@.   @@@        @@  @@  @@@@/      @@@
    /& @@@@    @@@ *@@@     @@@#  @@@&@@@    @@@@@@@#&@@ @@@%&,      @@ @@@@  @@@@    @@@&
        @@@  .@@@   /@%@     @@@  @@@@   @@& .@@@         @@&&&@      @@ @@@@  >@@@@ @@@@
        %@@@@@@&     /&&&     %@&  @&@     @& @&@&         &&@#%@%.   &@@ &@&#   %@@@@@@
        @@@@@        /@&%@%&@@@&@  @&&    ,@@ @@&&@@&@@@   &@@ /@@&/  @@, @@@/    %@@@@
        @@@.         *@@@@#,  @@@  @@@   ,@@  @@@.         @@@   @@@@@@@  %@@/   @@@@@@%
        @@@          *@@%     @@@   @@@@@@#    @@@@@@@@@@  @@@    ,@@@@    @@& .@@@  @@@@
        &@@,          @@%      @@                          @@@                 @@      @@@
                                                            &*
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

using namespace __gnu_cxx;
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define multi_ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ceil(w, m) (((w) / (m)) + ((w) % (m) ? 1 : 0))
#define endl "\n"
#define NumOfDig(w) log10(w) + 1
#define MOD 1000000007
#define INF 2000000000
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define sz(x) int(x.size())
#define init(x, c) memset(x, c, sizeof(x))
#define getlineCh(s, c) getline(cin >> ws, s, c)
#define TC int testcases = 1; cin >> testcases; for (ll test = 1; test <= testcases; test++)
// --------------------------->         GEOMETRY         <---------------------------    
#define EPS 1e-9
#define PI acos(-1)
#define X real()
#define Y imag()
#define angle(a) atan2(a.Y, a.X)
#define vec(a, b) point((b) - (a))
#define length(a) hypot(a.Y, a.X)
#define normalize(a) (a) / length(a)
#define dot_prod(a, b) real(conj(a) * (b))
#define cross_prod(a, b) imag(conj(a) * (b))
#define lengthSqr(p) dot_prod(p, p)
#define rotateO(p, ang) p * exp(point(0, ang))
#define rotateA(p, about, ang) rotateO(vec((about), (p)), ang) + (about)
#define reflicatO(v, m) conj(v / m) * m
#define reflicatA(v, about, m) conj(vec(about, v) / vec(about, m)) * vec(about, m) + about

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef complex<double> point;

/**
 * @author MiinaMagdy
 * @remark Time limit - memory limit (EFFICIENCY)
 * @remark (OVERFLOW) long long
 * @remark freopen() file
 * @remark (CORNER) test case
 * @remark division by (ZERO) || Out of array's (RANGE)
 * @remark use logarithm if you want to compare two products
 * @remark Brute Force means try all possible solutions remember (MAXPOINT - CodeChef)
 * @remark '/0' takes all input in getline string
 * @remark pass vector by reference to avoid tle
 * @remark assign vector instade of resize to avoid rte
 */

void phoenix()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
    #endif
    Time
}

double fix_360(double radian) {
    while (radian < 0) radian += 2 * PI;
    while (radian > 2 * PI) radian -= 2 * PI;
    return radian;
}

double to_degree(double radian) {
    return radian * 180 / PI;
}

bool is_collinear(point a, point b, point c) {
    return fabs(cross_prod(b - a, c - a)) <= EPS;
}

int dcmp(double a, double b) {
    return fabs(a - b) <= EPS ? 0 : (a > b ? 1 : -1); 
}

bool on_ray(point a, point b, point c) {
    if (!is_collinear(a, b, c)) {
        return false;
    }
    return dcmp(dot_prod(b - a, c - a), 0) == 1;
}

// closest distance from point c to line a-b
double distToLine(point a, point b, point c) {
    double dist = cross_prod(vec(a, b), vec(a, c)) / length(vec(a, b));
    return fabs(dist);
}

// distance from point p2 to segment p0-p1
ld distToSegment(point p0, point p1, point p2) {
    double d1, d2;
    point v1 = p1 - p0, v2 = p2 - p0;
    if ((d1 = dot_prod(v1, v2)) <= 0) {
        return length(vec(p0, p2));
    }
    if ((d2 = dot_prod(v1, v1)) <= d1) {
        return length(vec(p2, p1));
    }

    double t = d1 / d2;
    return length(vec(p0 + t * v1, p2));
}

bool intersectSegments(point a, point b, point c, point d, point & intersect) {
  double d1 = cross_prod(a - b, d - c), d2 = cross_prod(a - c, d - c), d3 = cross_prod(a - b, a - c);
  if (fabs(d1) < EPS)
    return false;  // Parllel || identical

  double t1 = d2 / d1, t2 = d3 / d1;
  intersect = a + (b - a) * t1;

  if (t1 < -EPS || t2 < -EPS || t2 > 1 + EPS)
    return false;  //e.g ab is ray, cd is segment ... change to whatever
  return true;
}

// pair<double, point> findCircle(point a, point b, point c) {
//     point v1 = b - a, v2 = b - c;
//     point m1 = (a + b) * 0.5, m2 = (b + c) * 0.5;
//     point pv1 = point(v1.imag(), -v1.real()), pv2 = point(v2.imag(), -v2.real());
//     point end1 = m1 + pv1, end2 = m2 + pv2, center;
//     intersectSegments(m1, end1, m2, end2, center);
//     return {length(vec(center, a)), center};
// }

bool cin_point(point &p) {
    double x = -INF, y = -INF;
    cin >> x >> y;
    p = {x, y};
    return x != -INF or y != -INF;
}

int main(void)
{
    phoenix();
    int testcase = 1;
    // cin >> testcase;
    while (testcase--)
    {
        ll n, p[3];
        cin >> n >> p[0] >> p[1] >> p[2];
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        map<ll, ll> mp;
        mp[0] = 0;
        ll sum = 0;
        ll cnt = 0;
        ll j = 0;
        vector<map<ll, ll>> v(3);
        for (ll i = 0; i < n; i++) {
            sum += a[i];
            for (int j = 0; j < 3; j++) {
                if (mp.count(sum - p[j])) {
                    v[j][mp[sum - p[j]]] = i + 1;
                }
            }
            mp[sum] = i + 1;
        }
        // for (int i = 0; i < 3; i++) {
        //     cout << sz(v[i]) << ": ";
        //     for (auto& I : v[i]) {
        //         cout << I.first << ", " << I.second << " | ";
        //     }
        //     cout << endl;
        // }
        bool can = false;
        for (auto& I : v[0]) {
            if (v[1].count(I.second)) {
                auto d = v[1][I.second];
                if (v[2].count(d)) {
                    can = true;
                    break;
                }
            }
        }
        cout << (can ? "YES" : "NO") << endl;
    }
    return 0;
}
