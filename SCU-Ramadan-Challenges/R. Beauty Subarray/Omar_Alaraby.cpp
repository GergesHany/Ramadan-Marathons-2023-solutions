#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
 
using namespace std;
using namespace __gnu_pbds;
 
void Omar_Alaraby(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
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
#define dl "\n"
#define ordered_set tree<ll ,  null_type ,  less_equal<> ,  rb_tree_tag ,  tree_order_statistics_node_update>
 
const ll Mod = 998244353;
 
template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x : v) in >> x;
    return in;
}
 
template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) {
    for (const T &x: v) out << x << ' ';
    return out;
}
 
ll n , k;
vector < ll > v;
constexpr int N = 3e5 + 5;
vector < vector < vector < ll > > > dp;
 
/*
    000000011111111122222222
    -------#########--------
*/
 
ll Max(int idx , int sub, int div){
    if(idx == n)
        return 0;
 
    ll &ret = dp[idx][sub][div];
    if(~ret)
        return ret;
 
    ret = 0;
    if(!sub){
        ret = max(ret , Max(idx + 1 , sub , div));
        ret = max(ret , v[idx] + Max(idx + 1 , 1 , div));
        ret= max(ret , v[idx] / k + Max(idx + 1 , 1 , 1));
    }
    else if(sub == 1){
        ret = max(ret , Max(idx + 1 , 2 , 2));
        if(!div){
            ret = max(ret , v[idx] + Max(idx + 1 , 1 , div));
            ret = max(ret , v[idx] / k + Max(idx + 1 , 1 , 1));
        }
        else if(div == 1){
            ret = max(ret , v[idx] / k + Max(idx + 1 , 1 , 1));
            ret = max(ret , v[idx] + Max(idx + 1 , 1 , 2));
        }
        else
            ret= max(ret , v[idx] + Max(idx + 1,  1 , div));
    }
    
    return ret;
}
 
 
void Solve(){
 
    cin >> n >> k;
    v.assign(n , 0); cin >> v;
    dp.assign(n , vector < vector < ll > >(3 , vector < ll > (3 , -1)));
 
    cout << Max(0 , 0 , 0) << dl;
}
 
int main(){
    Omar_Alaraby();
 
    int tc = 1;
    //cin >> tc;
 
    for(int i=1; i<=tc; i++){
        //cout << "Scenario #" << i << ":" << dl;
        Solve();
    }
 
    Time
    return 0;
}
