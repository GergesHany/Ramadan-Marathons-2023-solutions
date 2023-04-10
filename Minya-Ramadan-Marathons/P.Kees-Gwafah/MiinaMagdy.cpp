#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define endl '\n'

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
		
	int test;
	cin >> test;
	while (test--) {
		int n, m;
		cin >> n >> m;
		vector<vector<ll>> grid, pre_row, pre_col, suf_row, suf_col;
		grid = pre_row = pre_col = suf_row = suf_col = vector<vector<ll>>(n + 2, vector<ll>(m + 2, 1));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> grid[i][j];
				pre_row[i][j] = lcm(grid[i][j], pre_row[i][j - 1]);
				pre_col[i][j] = lcm(grid[i][j], pre_col[i - 1][j]);
			}
		}
		for (int i = n; i >= 1; i--) {
			for (int j = m; j >= 1; j--) {
				suf_row[i][j] = lcm(grid[i][j], suf_row[i][j + 1]);
				suf_col[i][j] = lcm(grid[i][j], suf_col[i + 1][j]);
			}
		}
		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				ll R = lcm(pre_row[i][j - 1], suf_row[i][j + 1]);
				ll C = lcm(pre_col[i - 1][j], suf_col[i + 1][j]);
				if (lcm(R, C) == lcm(pre_row[i][m], pre_col[n][j])) ans++;
			}
		}
		cout << ans << endl;
	}
}
