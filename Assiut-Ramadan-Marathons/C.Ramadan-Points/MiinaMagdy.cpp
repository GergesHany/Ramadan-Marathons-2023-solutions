/*
+---------------------------------------------+
|                                             |
|  Copytright, MinaMagdy, 25/03/2023 (22:16)  |
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

using namespace std;

#define endl "\n"
#define all(x) x.begin(), x.end()
#define INF 2000000000
typedef long long ll;

void phoenix()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
    #endif
}

const int mod = 998244353;

ll fast_pow(ll b, ll e) {
    ll prod = 1;
    while (e) {
        if (e & 1) prod = (prod * b) % mod;
        e >>= 1;
        b = (b * b) % mod;
    }
    return prod;
}

int main(void)
{
    phoenix();
    int testcase = 1;
    // cin >> testcase;
    while (testcase--)
    {
        int n;
        cin >> n;
        ll arr[n];
        for (auto& I : arr) cin >> I;
        sort(arr, arr + n);
        ll v[4] = {arr[n - 1] - arr[0], INF, INF, INF};
        for (int i = 1; i < n; i++) {
            v[3] = arr[i] - arr[i - 1];
            sort(v, v + 4);
            if (i - 1 > 0) {
                v[3] = arr[i] - arr[i - 2];
                sort(v, v + 4);
            }
        }
        cout << v[2] << endl;
    }
    return 0;
}
