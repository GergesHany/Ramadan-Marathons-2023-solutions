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
		string s;
		cin >> n >> s;
		vector<vector<int>> pos(26);
		for (int i = 0; i < n; i++)
			pos[s[i] - 'a'].push_back(i);
		
		auto bin = [&](int idx, char c) {
			int l = 0, r = pos[c].size() - 1;
			int best = -1;
			while (l <= r) {
				int m = l + (r - l) / 2;
				(pos[c][m] < idx ? best = m, l = m + 1 : r = m - 1);
			}
			return best;
		};
		map<pair<char, char>, ll> freq;
		for (int mid = 0; mid < n; mid++) {
			for (int c = 0; c < 26; c++) {
				int idL = bin(mid, c);
				if (idL + 1 < sz(pos[c])) {
					int idR = idL + 1;
					if (pos[c][idL + 1] == mid) idR++;
					if (idR >= sz(pos[c])) continue;
					ll cntL = idL + 1, cntR = sz(pos[c]) - idR;
					freq[{c + 'a', s[mid]}] += cntL * cntR;
				}
			}
		}
		string t;
		ll ans = 0;
		for (auto& I : freq) {
			if (I.second > ans) {
				ans = I.second;
				t = I.first.first;
				t += I.first.second;
				t += I.first.first;
			}
		}
		cout << (sz(t) ? t : "-1") << endl;
	}
	
}
