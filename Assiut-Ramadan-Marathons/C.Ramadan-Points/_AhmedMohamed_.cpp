#include <bits/stdc++.h>
#define Time cerr << "Time Taken: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms\n";
#define meme(s, x) memset(s, x, sizeof(s))
#define memev(v, x) fill(all(v), x)
#define all(v) ((v).begin()), ((v).end())
#define line cout << "\n------------\n";
#define here cout << "Here\n";
#define pb push_back
#define el '\n'
#define int long long
using namespace std;
void judge();
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
// abcdefghijklmnopqrstuvwxyz
// primes 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101
const int N = 2e5 + 5, M = 1e6 + 5, mod = 1e9 + 7, inf = INT_MAX, inff = LLONG_MAX;
//--------------------------------------------------------------
int tcase = 0;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(all(v));
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        if (i + 2 < n) {
            temp.pb(v[i + 2] - v[i]);
        }
        if (i + 1 < n) {
            temp.pb(v[i + 1] - v[i]);
        }
        if (i + 3 < n) {
            temp.pb(v[i + 3] - v[i]);
        }
    }
    sort(all(temp));
    if (temp.size() == 1) {
        cout << temp[0] << el;
    } else if (temp.size() == 2) {
        cout << temp[1] << el;
    } else {
        cout << temp[2] << el;
    }
}

int32_t main()
{
    judge();
    int tt = 1;
    if (tcase)
        cin >> tt;
    while (tt--) {
        solve();
    }
    // time;
}

//

void judge()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
