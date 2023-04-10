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
		int x;
		cin >> x;
		freq[x]++;
	}
	int k = 0;
	for (auto& I : freq) {
		k = gcd(I.second, k);
	}
	cout << (k > 1 ? "YES" : "NO") << endl;
}

//  1, 2, 3, 4, 5
//  1  1  1  1  0
// cur = 4         ? 2      good 
// cur = 4 - 2 = 2    ? 4 - 2 = 2 good
