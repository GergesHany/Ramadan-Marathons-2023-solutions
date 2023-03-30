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


map <  string , ll >  mp;


for(int i=0 ; i < 7;i++){
    string s  , t;
    cin >> s >> t;
    int h =( t[0]-'0')* 10 + (t[1]-'0');
    int m = ( t[3]-'0')* 10 + (t[4]-'0');
    int se=( t[6]-'0')* 10 + (t[7]-'0');
    
    mp[s] = 0ll+ se + m * 60 + h * 60 * 60  ;
    
}

map < string , int > mp2 ;
mp2["Saturday"]=0;
mp2["Sunday"]=1;
mp2["Monday"]=2;
mp2["Tuesday"]=3;
mp2["Wednesday"]=4;
mp2["Thursday"]=5;
mp2["Friday"]=6;

int q;cin >> q;
while(q--){
    string st  , t ;
    cin >> st >> t ;
    
     int h =( t[0]-'0')* 10 + (t[1]-'0');
    int m = ( t[3]-'0')* 10 + (t[4]-'0');
    int se=( t[6]-'0')* 10 + (t[7]-'0');
    
    ll cm = 0ll+ se + m * 60 + h * 60 * 60 ; 
    
   if( mp[st] > cm)
       cout<< mp[st] - cm << nl;
  
   else{
     int id= mp2[st];
     id++;
     id%=7;
     for(auto& [ x,y] : mp2){
         if( y == id){
             cout << 86400 + mp[x] - cm << nl;
             break;
         }
     }
     
   }
    
}

}

int main(){
                 IO();       //  files();

    int testCase=1;  // one test case
    //cin >> testCase ;       
 while(testCase--) 
        solve();  // my code
        
    return 0;
}
