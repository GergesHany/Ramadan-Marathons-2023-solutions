#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()

string s;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	cin >> s;
	int suf_1 = count(all(s), '1');
	int suf_0 = count(all(s), '0');
	int pre_1 = 0, pre_0 = 0;
	ll ans = 0;
	for (int i = 0; i < sz(s); i++) {
		if (s[i] == '1') {
			suf_1--;
			ans += 1ll * pre_0 * suf_0;
			pre_1++;
		}
		else {
			suf_0--;
			ans += 1ll * pre_1 * suf_1;
			pre_0++;
		}
	}
	cout << ans << endl;
}
