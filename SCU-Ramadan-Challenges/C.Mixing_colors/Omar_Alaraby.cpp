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
#define mod  1000000007
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
 
struct offer{
    int cyan , mag , cost;
};
 
ll n , ra, rb;
double Nesba;
vector < offer > v;
vector < vector < vector < ll > > > dp;
 
ll min_cost(int curr , ll c , ll m){
    if(curr == n)
        return (double)c / (double)m == Nesba? 0 : 1e9;
 
    ll &ret = dp[curr][c][m];
    if(~ret)
        return ret;
 
    ret = v[curr].cost + min_cost(curr + 1 , c + v[curr].cyan , m + v[curr].mag);
    ret = min(ret , min_cost(curr + 1 , c , m));
    return ret;
}
 
void Solve(){
 
    cin >> n >> ra >> rb;
    v.assign(n , {0,  0, 0});
    dp.assign(45 , vector < vector < ll > > (410 , vector < ll > (410 , -1)));
    Nesba = (double)ra / (double)rb;
 
    for(auto &i : v)
        cin >> i.cyan >> i.mag >> i.cost;
 
    ll ans = min_cost(0 , 0 , 0);
    cout << ((ans >= 1e9)? -1 : ans) << dl;
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
