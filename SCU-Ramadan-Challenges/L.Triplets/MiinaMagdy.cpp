#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define endl '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& I : v) cin >> I;
	sort(all(v));
	set<vector<int>> st;
	for (int i = 0; i < n; i++) {
		int l = i + 1, r = n - 1;
		while (l < r) {
			int sum = v[i] + v[l] + v[r];
			if (sum < 0) l++;
			else if (sum > 0) r--;
			else st.insert({v[i], v[l++], v[r--]});
		}
	}
	if (sz(st)) {
		cout << sz(st) << endl;
		for (auto& I : st) {
			for (auto& J : I) cout << J << " ";
			cout << endl;
		}
	}
	else {
		cout << -1 << endl;
	}
}
