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
		string s;
		cin >> s;
		int freq[26]{};
		int mx = 0;
		for (int i = 0; i < sz(s); i++) {
			freq[s[i] - 'a']++;
			mx = max(mx, freq[s[i] - 'a']);
		}
		cout << (mx == 1 ? -1 : mx) << endl;
	}
}
