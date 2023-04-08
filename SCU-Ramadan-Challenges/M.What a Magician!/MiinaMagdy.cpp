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
	map<int, int> freq;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		freq[a]++;
		freq[b]--;
	}
	
	ll ans = 0;
	for (auto& [x, oc] : freq) {
		if (oc > 0) {
			ans += oc;
		}
	}
	cout << ans << endl;
}

