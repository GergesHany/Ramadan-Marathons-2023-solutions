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
int n , m;
cin >> n >> m ;
vector < int > a(n) , b(m) , freq(305) , freq2(305);


for(int i=0;i<n;i++){
    cin >> a[i] ;
    freq[a[i]]++;
}

for(auto& i : b){
    cin >> i;
    freq2[i]++;
}

for(int i=0;i<305;i++){
    if(freq2[i] > freq[i]) return void(cout <<"NO\n");
    if(freq2[i]==0 and freq[i]==1) return void(cout <<"NO\n");
}

int j=0 ,sze ;
for(int i=0;i<m;i++){
    int t= j;
    if( i !=0 and b[i]==b[i-1]){
        if(sze>0) sze--;
        else return void(cout <<"NO\n");
        continue;
    }
    
     while(j < n and a[j]!=b[i]) j++;
     while(j < n and a[j]==b[i]) j++;
    
     sze= j-t+1;
    if(sze == 1 and i >0 and b[i]!=b[i-1]) return void(cout <<"NO\n");
    sze--;
}

cout << (j==n ? "YES" : "NO") << nl;


}
int main(){
                 IO();       //  files();

    int testCase=1;  // one test case
   cin >> testCase ;       
 while(testCase--) 
        solve();  // my code
        
    return 0;
}
