#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define endl '\n'
 
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
		
	ll a, b, c;
	cin >> a >> b >> c;
	ll ans = 0;
	ll d = min(c, a);
	ans += d;
	c -= d;
	a -= d;
	b += a / 2;
	ans += b / 2;
	cout << ans << endl;
}
