#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define endl '\n'


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	int n, m;
	cin >> n >> m;	
	vector<vector<int>> dir[2];
	dir[0].resize(n + 1);
	dir[1].resize(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		dir[0][u].push_back(v);
		dir[1][v].push_back(u);
	}
	int a, b, cnt = 1e9;
	cin >> a >> b;
	deque<vector<int>> dq; // node, cost, dir
	dq.push_back({a, 0, 0});
	vector<bool> vis[2];
	vis[0].resize(n + 1);
	vis[1].resize(n + 1);
	vis[0][a] = true;
	vis[1][a] = true;
	while (sz(dq)) {
		auto v = dq.front();
		dq.pop_front();
		if (v[0] == b) {
			cnt = min(cnt, v[1]);
			continue;
		}
		for (auto& I : dir[v[2]][v[0]]) {
			if (!vis[v[2]][I]) {
				vis[v[2]][I] = true;
				dq.push_front({I, v[1], v[2]});
			}
		}
		for (auto& I : dir[!v[2]][v[0]]) {
			if (!vis[!v[2]][I]) {
				vis[!v[2]][I] = true;
				dq.push_back({I, 1 + v[1], !v[2]});
			}
		}
	}
	dq.push_back({a, 0, 1});
	vis[0].assign(n + 1, 0);
	vis[1].assign(n + 1, 0);
	vis[0][a] = true;
	vis[1][a] = true;
	while (sz(dq)) {
		auto v = dq.front();
		dq.pop_front();
		if (v[0] == b) {
			cnt = min(cnt, v[1]);
			continue;
		}
		for (auto& I : dir[v[2]][v[0]]) {
			if (!vis[v[2]][I]) {
				vis[v[2]][I] = true;
				dq.push_front({I, v[1], v[2]});
			}
		}
		for (auto& I : dir[!v[2]][v[0]]) {
			if (!vis[!v[2]][I]) {
				vis[!v[2]][I] = true;
				dq.push_back({I, 1 + v[1], !v[2]});
			}
		}
	}
	cout << cnt << endl;
}
