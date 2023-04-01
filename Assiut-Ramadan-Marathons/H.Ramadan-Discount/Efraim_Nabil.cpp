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

ll discount(ll x){
    return (x * 3) / 4;
}

int main(){
    Fero();

    ll n;
    cin >> n;
    ll v[n * 2];
    vector < int > a(n * 2+5, 0);
    for(int i = 0; i < n * 2; i++){
        cin >> v[i];
    }
    int l = 0, r = 0, c = 0;

    while(l < 2 * n && r < 2 * n){
        while(l < 2 * n && a[l]) l++;
        if(v[l] == discount(v[r])){
            cout << v[l] << " " ;
            a[l] = 1;
            a[r] = 1;
            c++;
            l++;
            r++;
        }
        else if (v[l] < discount(v[r])){
            l++;
        }
        else{
            r++;
        }
    }


    

    

    return 0;
}
