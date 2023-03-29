#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
 
using namespace std;
using namespace __gnu_pbds;
 
void Omar_Alaraby(char * input , char * output){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen(input, "r", stdin), freopen(output, "w", stdout);
#endif
}
 
#define cin2d(vec, n, m) for(int i = 0; i < n; i++) for(int j = 0; j < m && cin >> vec[i][j]; j++);
#define cout2d(vec , n , m) for(int i = 0; i < n; i++, cout << "\n") for(int j = 0; j < m && cout << vec[i][j] << " "; j++);
#define cout_map(mp) for(auto& [first, second] : mp) cout << first << " --> " << second << "\n";
#define put(s) return void(cout << s << dl);
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
#define fixed(n) fixed << setprecision(n)
#define ceil(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define sz(x) int(x.size())
#define ll long long
#define ull unsigned long long
#define Mod  1000000007
#define dl "\n"
#define ordered_set tree<ll ,  null_type ,  less_equal<> ,  rb_tree_tag ,  tree_order_statistics_node_update>
 
template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x : v) in >> x;
    return in;
}
 
template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) {
    for (const T &x: v) out << x << ' ';
    return out;
}
 
ll n , k;
vector < vector < int > > adj;
vector < set < int > > adjColors;
vector < int > colored;
vector < vector < ll > > dp;
 
void init(){
    adj.assign(n + 1 , {});
    adjColors.assign(n + 1 , {});
    colored.assign(n + 1 , 0);
    dp.assign(n + 2 , vector < ll > (4 , 0));
}
 
bool fail(){
    for(int i=1; i<n; i++){
        if(colored[i]){
            for(auto &tower : adj[i])
                if(colored[tower] == colored[i])
                    return true;
        }
        else{
            set < int > check;
            for(auto &tower : adj[i])
                if(colored[tower])
                    check.emplace(colored[tower]);
            if(sz(check) == 3)
                return true;
        }
    }
    return false;
}
 
void cnt(int curr , int par){
 
    if(colored[curr])
        dp[curr][colored[curr]] = 1;
    else
        dp[curr][1] = dp[curr][2] = dp[curr][3] = 1;
 
    if(colored[par])
        dp[curr][colored[par]] = 0;
 
    for(auto &tower : adj[curr]){
        if(tower == par)
            continue;
 
        cnt(tower , curr);
 
        if(colored[curr]){
            dp[curr][colored[curr]] *= (dp[tower][1] + dp[tower][2] + dp[tower][3] - dp[tower][colored[curr]]);
            dp[curr][colored[curr]] %= Mod;
            continue;
        }
 
        for(int i=1; i<=3; i++){
            ll res = dp[tower][1] + dp[tower][2] + dp[tower][3] - dp[tower][i];
            dp[curr][i] *= res;
            dp[curr][i] %= Mod;
        }
    }
}
 
void Solve(){
 
    cin >> n >> k;
    init();
 
    for(int i=1; i<n; i++){
        ll x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
 
    for(int i=0; i<k; i++){
        ll x , c; cin >> x >> c;
        colored[x] = c;
    }
 
 
    cnt(1 , 0);
 
    ll ans = 0;
    for(int i=1; i<=3; i++){
        ans += dp[1][i] % Mod;
        ans %= Mod;
    }
    cout << ans << dl;
}
 
int main(){
    Omar_Alaraby("input.txt" , "output.txt");
 
    int tc = 1;
    //cin >> tc;
 
    for(int i=1; i<=tc; i++){
        //cout << "Scenario #" << i << ":" << dl;
        Solve();
    }
 
    Time
    return 0;
}

