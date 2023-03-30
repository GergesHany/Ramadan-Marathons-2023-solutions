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
bool prime(ll n){
    if(n==2 || n==3) return true;
    if(n<2 || n%2==0  ) return false;
    for(int i=3;i<=sqrt(n);i+=2)   if(n%i==0) return false;
    return true;
}


void solve(){


int n ;
cin >> n ;
vector < int > v(n);
cin (v);
sort(all(v));


vector < int > an;
for(int i=1 ; i < n ; i++){
   an.push_back(v[i]-v[i-1]);
   
   if(i > 1)
        an.push_back(v[i]-v[i-2]);
}



sort(all(an));
cout << an[2] ;

}

int main(){
                 IO();       //  files();

    int testCase=1;  // one test case
   // cin >> testCase ;       
 while(testCase--) 
        solve();  // my code
        
    return 0;
}