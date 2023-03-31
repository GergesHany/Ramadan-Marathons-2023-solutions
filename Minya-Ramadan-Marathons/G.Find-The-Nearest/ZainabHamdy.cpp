#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define ull unsigned ll
#define nl "\n"
#define sz(x) int(x.size())
#define NumOfDigit(w) log10(w) + 1
#define fill(arr, val)  memset(arr, val , sizeof(arr))
#define PI 3.141592654
#define ceil(w, m) (((w) / (m)) + ((w) % (m) ? 1 : 0))
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define fi first
#define se second
#define cin(v) for (auto&i:v) cin >> i;
#define cout(v) for (auto&i:v) cout << i << " ";
#define fixed(n) fixed << setprecision(n)
//#define MOD  1e9 + 7


void IO(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
}
void files(){
    //freopen("filename.in" , "r" ,stdin);
            #ifndef ONLINE_JUDGE
              freopen("input.txt", "r", stdin);  freopen("output.txt", "w", stdout);
            #endif
}


void solve(){


ll x , z;               cin >> x >> z;


ll ans = x / (z+1) +1;


cout <<  (( x / ans )== z ? ans : -1) << nl;


}

int main(){
                 IO();       //  files();

    int testCase=1;  // one test case
    cin >> testCase ;       
 while(testCase--) 
        solve();  // my code
        
    return 0;
}
