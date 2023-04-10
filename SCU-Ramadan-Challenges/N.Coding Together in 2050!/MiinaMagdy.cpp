#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define endl '\n'
 
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	deque<char> s[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			char c;
			cin >> c;
			s[i].push_back(c);
		}
		deque<char> t = s[i];
		for (int j = 1; j < k; j++) {
			t.push_front(t.back());
			t.pop_back();
			if (t < s[i]) s[i] = t;
		}
	}
	ll ans = 0;
	map<deque<char>, int> freq;
	for (int i = 0; i < n; i++) {
		ans += freq[s[i]]++;
	}
	cout << ans << endl;
}
