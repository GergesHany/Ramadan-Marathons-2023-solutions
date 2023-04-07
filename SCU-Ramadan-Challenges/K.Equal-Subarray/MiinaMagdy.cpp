#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()

string s;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		vector<pair<int, int>> components;
		int prev = -1;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (x != prev)
				components.push_back({x, 0});
			components.back().second++;
			if (components.back().second % 2 == 0) ans = max(ans, components.back().second);
			prev = x;
		}
		for (int i = 1; i < sz(components); i++) {
			ans = max(ans, 2 * min(components[i].second, components[i - 1].second));
		}
		cout << ans << endl;
	}
}
