#include <bits/stdc++.h>
#define ll long long
#define OO 1e9
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.ren()
#define TC int t; cin >> t; while(t--)
using namespace std;
void Fero(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
    #endif
}

vector < pair < ll, ll > > divisors; // first * second = n

void getDivisors(ll n){
    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0){
            divisors.push_back({i, n / i});
        }
    }
}

ll divisors_cnt(ll n){
    ll cnt = 1;
    long double l = 0;
    vector < ll > mp(1005);
    for(ll i = n; i >= 1; i--){
        ll x = i;
        for(ll j = 2; j <= x; j++){
            while(x % j == 0){
                x /= j;
                mp[j]++;
            }
        }
    }
    for(ll i = 0; i <= n; i++){
        cnt *= (mp[i] + 1);
        l += log10(mp[i] + 1);
    }
    if(l > 18) return -1;
    return cnt;
}


int main(){
    Fero();

    vector < ll > v(110);
    for(ll i = 1; i <= 108; i++){
        v[i] = divisors_cnt(i);
    }
    TC{
        ll n;
        cin >> n;
        bool ok = false;
        for(ll i = 1; i <= 108; i++){
            if(v[i] == n){
                cout << i << endl;
                ok = true;
                break;
            }
        }
        if(!ok) cout << "Ramaden Kareem Ya Amoor" << endl;
    }




    return 0;
}
