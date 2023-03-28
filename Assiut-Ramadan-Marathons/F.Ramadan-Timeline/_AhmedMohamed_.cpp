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
/*
 * Another buggy code by _AhmedMohamed_
 */

map<string, vector<int>> mp;
int get_diff(string nextday, int myh, int mym, int mys)
{
    int hh = mp[nextday][0];
    int mm = mp[nextday][1];
    int ss = mp[nextday][2];
    int iftar = hh * 3600 + mm * 60 + ss;
    int current_time = myh * 3600 + mym * 60 + mys;
    int rem = (23 * 60 * 60 + 59 * 60 + 60) - current_time;
    return rem + iftar;
}
void solve()
{
    string s;
    char c;
    int t, q;
    for (int i = 0; i < 7; i++) {
        cin >> s;
        for (int j = 0; j < 3; j++) {
            cin >> t;
            mp[s].pb(t);
            if (j != 2) cin >> c;
        }
    }
    cin >> q;
    while (q--) {
        int hour, min, sc;
        cin >> s;
        cin >> hour >> c;
        cin >> min >> c;
        cin >> sc;
        if (s == "Saturday") {
            int hh = mp["Saturday"][0];
            int mm = mp["Saturday"][1];
            int ss = mp["Saturday"][2];
            int iftar = hh * 3600 + mm * 60 + ss;
            int current_time = hour * 3600 + min * 60 + sc;
            if (current_time < iftar) {
                cout << iftar - current_time << el;
            } else {
                cout << get_diff("Sunday", hour, min, sc) << el;
            }
        } else if (s == "Sunday") {
            int hh = mp["Sunday"][0];
            int mm = mp["Sunday"][1];
            int ss = mp["Sunday"][2];
            int iftar = hh * 3600 + mm * 60 + ss;
            int current_time = hour * 3600 + min * 60 + sc;
            if (current_time < iftar) {
                cout << iftar - current_time << el;
            } else {
                cout << get_diff("Monday", hour, min, sc) << el;
            }
        } else if (s == "Monday") {
            int hh = mp["Monday"][0];
            int mm = mp["Monday"][1];
            int ss = mp["Monday"][2];
            int iftar = hh * 3600 + mm * 60 + ss;
            int current_time = hour * 3600 + min * 60 + sc;
            if (current_time < iftar) {
                cout << iftar - current_time << el;
            } else {
                cout << get_diff("Tuesday", hour, min, sc) << el;
            }
        } else if (s == "Tuesday") {
            int hh = mp["Tuesday"][0];
            int mm = mp["Tuesday"][1];
            int ss = mp["Tuesday"][2];
            int iftar = hh * 3600 + mm * 60 + ss;
            int current_time = hour * 3600 + min * 60 + sc;
            if (current_time < iftar) {
                cout << iftar - current_time << el;
            } else {
                cout << get_diff("Wednesday", hour, min, sc) << el;
            }
        } else if (s == "Wednesday") {
            int hh = mp["Wednesday"][0];
            int mm = mp["Wednesday"][1];
            int ss = mp["Wednesday"][2];
            int iftar = hh * 3600 + mm * 60 + ss;
            int current_time = hour * 3600 + min * 60 + sc;
            if (current_time < iftar) {
                cout << iftar - current_time << el;
            } else {
                cout << get_diff("Thursday", hour, min, sc) << el;
            }
        } else if (s == "Thursday") {
            int hh = mp["Thursday"][0];
            int mm = mp["Thursday"][1];
            int ss = mp["Thursday"][2];
            int iftar = hh * 3600 + mm * 60 + ss;
            int current_time = hour * 3600 + min * 60 + sc;
            if (current_time < iftar) {
                cout << iftar - current_time << el;
            } else {
                cout << get_diff("Friday", hour, min, sc) << el;
            }
        } else if (s == "Friday") {
            int hh = mp["Friday"][0];
            int mm = mp["Friday"][1];
            int ss = mp["Friday"][2];
            int iftar = hh * 3600 + mm * 60 + ss;
            int current_time = hour * 3600 + min * 60 + sc;
            if (current_time < iftar) {
                cout << iftar - current_time << el;
            } else {
                cout << get_diff("Saturday", hour, min, sc) << el;
            }
        }
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

