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


ll POW(ll a , ll b , ll m){
     ll ans=1;
     while(b){
         if(b&1) ans*=a , ans%=m;
         
         a*=a;
         b/=2;
         a%=m;
     }
     return ans  ;
}

void solve(){

ll n;
cin >> n ;

ll  MO = 998244353;


vector < pair < ll , ll > >  pr;

for(ll i=1 ; i <=sqrtl(n); i++){
    if(n % i ==0){
        pr.push_back( {i , n/i });
    }
}

pair < ll , ll > cm = { pr[0].fi , pr[0].se} ;
double temp= 0.0 +pr[0].se * log(pr[0].fi );

for(int i=0 ; i < sz(pr) ; i++){
    ll x= pr[i].fi , y = pr[i].se;
    if( x * log(y) > temp){
        temp =x * log(y) ;
       cm.fi=y , cm.se=x;
    }
    
    if( y * log(x) > temp){
        temp =y * log(x) ;
        cm.fi=x  , cm.se=y;
    }
    
}
cout << fixed(0) <<  POW( cm.fi , cm.se , MO)   << nl;
 
}

int main(){
                 IO();       //  files();

    int testCase=1;  // one test case
    cin >> testCase ;       
 while(testCase--) 
        solve();  // my code
        
    return 0;
}
