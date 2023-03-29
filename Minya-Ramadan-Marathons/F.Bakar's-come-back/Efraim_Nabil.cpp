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


int main(){
    Fero();

    ll n;
    cin >> n;
    if(n % 2 == 0){
        cout << "-1\n";
    }
    else{
        if(n <= 2) cout << -1 << endl;
        else{
            n -= 3;
            ll ans = 1;
            for(int i = 0; i < n / 2; i++){
                ans *= 10;
            }
            cout << ans << endl;
        }
    }
    
    

    return 0;
}
