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
int n ;
cin >> n ;

int cnt4=0 , cnt2=0 , odd=0;
for(int x=0 ; x<n ; x++){
    ll i ; cin >> i;
    if( i % 4==0) cnt4++;
    else if(i % 2 ==0 ) cnt2++;
    
}
odd= n - cnt2-cnt4;

if( odd ==0  )    cout <<"YES";
else if( cnt4 >= odd and cnt2!=0 ) cout <<"YES";
else if(cnt2==0 and cnt4 >= odd-1)  cout <<"YES";
else cout <<"NO";



}
int main(){
                 IO();       //  files();

    int testCase=1;  // one test case
   // cin >> testCase ;       
 while(testCase--) 
        solve();  // my code
        
    return 0;
}
