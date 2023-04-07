#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define endl '\n'
#define MAXN 1000001

vector<vector<int>> divisors;

void sieve() {
    divisors.resize(MAXN);
    for (int i = 1; i <= MAXN; ++i) {
		for (int j = i; j <= MAXN; j += i) 
			divisors[j].push_back(i);
	}
}
 
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	sieve();
	ll n;
	cin >> n;
	map<int, int> freq;
	while (n--) {
		int x;
		cin >> x;
		freq[x]++;
	}
	vector<int> dp(MAXN);
	int ans = 0;
	for (auto& [x, oc] : freq) {
		dp[x] = oc;
		for (auto& I : divisors[x]) {
			if (I == x) continue;
			dp[x] = max(dp[x], oc + dp[I]);
		}
		ans = max(ans, dp[x]);
	}
	cout << ans << endl;
}
