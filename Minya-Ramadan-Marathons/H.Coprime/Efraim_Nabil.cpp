#include <bits/stdc++.h>
#define ll long long
#define OO 1e9
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define TC int t; cin >> t; while(t--)
using namespace std;
void Fero(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
    #endif
}

// Phi Function

ll phi(int n) {
  ll result = n;
  for (ll i = 2; i * i <= n; i++) {
      if (n % i == 0) {
          while (n % i == 0)
              n /= i;
          result -= result / i;
      }
  }
  if (n > 1)
      result -= result / n;
  return result;
}

int main(){
    Fero();

    TC{
        ll a;
        cin >> a;
        cout << phi(a) << endl;
    }

    return 0;
}
