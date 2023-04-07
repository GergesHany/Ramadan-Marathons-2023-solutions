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
void solve(){
 ll n; cin >> n;

 vi v(n);
 bool found = false;
 for(int i = 0; i < n; i++){
  cin >> v[i];
 }
    sort(all(v));

 set<vector<int>> triplets;
  for (int i = 0; i < n - 1; i++) {
        int l = i + 1;
        int r = n - 1;
        int x = v[i];
        while (l < r) {
            if (x + v[l] + v[r] == 0) {
                vector<int> triplet = {x, v[l], v[r]};
                triplets.insert(triplet);
                l++;
                r--;
                found = true;
            }
            else if (x + v[l] + v[r] < 0) {
                l++;
            }
            else {
                r--;
            }
        }
    }
    if (!found) {
        cout << "-1" << endl;
    }
    else {
        cout << triplets.size() << endl;
        for (auto triplet : triplets) {
            cout << triplet[0] << " " << triplet[1] << " " << triplet[2] << endl;
        }
    }
}
int main(){
  // Accepted it
  cout << fixed << setprecision(6);
	M7MDAN_FRAG(); 
//freopen("easy.in", "r", stdin); freopen("easy.out", "w", stdout);
	int t=1,xd=1; 
//cin>>t;
	while(t--){
		solve(); 
	}
}
