#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define endl '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		ll arr[n + 2];
		ll ans = 1e18;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		for (ll i = 1; i <= n; i++) {
			for (ll j = 1; j <= n; j++) {
				ll c = (j - arr[i] % j) % j + abs(i - j);
				ll v = arr[i] + (j - arr[i] % j) % j;
				ans = min(ans, c + v / j + j);
			}
		}
		cout << ans << endl;
	}
}
