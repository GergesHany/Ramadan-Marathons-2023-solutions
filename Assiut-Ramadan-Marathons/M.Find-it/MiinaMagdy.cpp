#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define endl '\n'
 
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	ll l = 1, r = 1e15;
	ll add = 0;
	while (l <= r) {
		ll mid = l + (r - l) / 2;
		printf("? %lld\n", mid - add);
        fflush(stdout);
        int good;
        scanf("%d", &good);
        if (good) {
			add += (mid - add);
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	printf("! %lld\n", add);
	fflush(stdout);
}

//  1, 2, 3, 4, 5
//  1  1  1  1  0
// cur = 4         ? 2      good 
// cur = 4 - 2 = 2    ? 4 - 2 = 2 good
