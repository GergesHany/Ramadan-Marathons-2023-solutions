/** حَسْبِيَ اللَّهُ لا إِلَـهَ إِلاَّ هُوَ عَلَيْهِ تَوَكَّلْتُ وَهُوَ رَبُّ الْعَرْشِ الْعَظِيمِ **/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long 
#define sz(x) int(x.size())
#define PI acos(-1)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define GCin(a)	 getline(cin,a);
#define clr(v, d) memset(v, d, sizeof(v))
#define endl "\n"
#define c_2  300000000
#define vl vector<ll>
#define vi vector<int>
#define pb push_back
#define MOD ((ll) 1e9 + 7)
void M7MDAN_FRAG(){
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
 #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);
  #endif
}
const ll aka =2e5 + 5;
const ll N = 1e7 + 5;
bool isPrime(ll n){
    if(n == 2 or n == 3)return true;
    if(n % 2 == 0 or n < 2)return false;
    for(ll i = 3; i * i <= n; i += 2){
        if(n % i == 0) return false;
    }
    return true;
}
bool cmp(pair<ll, ll>& a,pair<ll, ll>& b){
  if(a.first==b.first) return a.second > b.second ;
   else return a.first < b.first;
}

const long long OO =(ll)1e18;
int dx[8] = {0,0,1,-1,1,-1,1,-1};
int dy[8] = {1,-1,0,0,1,-1,-1,1};
// frq 1 2 3 4 5 6 7 8 9 10
//     0 0 0 0 0 0 0 0 0 0
///*-*-*-*-*-*-*-*-*-*-*-*-*-*-*>> # Tonight gehrman joins the hunt # <<*-*-*-*-*-*-*-*-*-*-*-*-*-*-*///

vl adj[aka];
ll dp[aka][4];
ll n,k;
bool vis[aka];
vl color(aka);
//ll see[aka][4];
void dfs(ll node,ll par){
  if(vis[node]) return ;
  vis[node]=1; 
 dp[node][1]=dp[node][2]=dp[node][3]=1;
  for(auto child:adj[node]){
    if(!vis[child]){
     dfs(child,node);
     dp[node][1]=dp[node][1]*(dp[child][2]+dp[child][3])%MOD;
    dp[node][2]=dp[node][2]*(dp[child][1]+dp[child][3])%MOD;
    dp[node][3]=dp[node][3]*(dp[child][1]+dp[child][2])%MOD;
     }
    }
    if(color[node]==1){
      dp[node][2]=0;
      dp[node][3]=0;
    }
    else if(color[node]==2){
      dp[node][1]=0;
      dp[node][3]=0;
    }
    else if(color[node]==3){
      dp[node][1]=0;
      dp[node][2]=0;
    }
  }
    /*
   if(color[node]!=0){
    ok=color[node];
    if(color[node]==1){
      see[node][1]=1;see[node][2]=0;see[node][3]=0;
    }
    else if(color[node]==2){
      see[node][1]=0;see[node][2]=1;see[node][3]=0;
    }
    else if(color[node]==3){
      see[node][1]=0;see[node][2]=0;see[node][3]=1;
    }
  }
  else{
    see[node][1]=1;see[node][2]=1;see[node][3]=1;
  }
  */

void solve(){

cin>>n>>k;

clr(dp,0);

for(int i=1;i<n;i++){
  ll u,v;
  cin>>u>>v;
  adj[u].pb(v);
  adj[v].pb(u);
}
for(int i=1;i<=k;i++){
  ll x,y; cin>>x>>y;
  color[x]=y;
}

dfs(1,-1);

ll ans=0;
for(int i=1;i<=3;i++){
  ans=(ans+dp[1][i])%MOD;
}

cout<<ans<<endl;

}
int main(){
  // Accepted it
  cout << fixed << setprecision(0);
	M7MDAN_FRAG(); 
//freopen("easy.in", "r", stdin); freopen("easy.out", "w", stdout);
	int t=1,xd=1; 
//cin>>t;
	while(t--){
		solve(); 
	}
}
