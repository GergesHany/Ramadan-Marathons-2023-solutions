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
#define dl "\n"
#define ordered_set tree<ll ,  null_type ,  less_equal<> ,  rb_tree_tag ,  tree_order_statistics_node_update>
 
const ll Mod = 1e9 + 7;
 
template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x : v) in >> x;
    return in;
}
 
template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) {
    for (const T &x: v) out << x << ' ';
    return out;
}
 
ll n , m , k;
vector < ll > v;
 
vector < vector < ll > > get_sums(int l , int r){
 
    int size = r - l + 1;
    vector < vector < ll > > ret(size + 2 , vector < ll >());
 
    for(int mask = 1; mask < (1 << (size)); mask++){
        ll sum = 0;
 
        int cnt = __builtin_popcount(mask);
        if(cnt > m)
            continue;
 
        for(int i=0; i<size; i++){
            if(mask & (1 << i))
                sum += v[l + i];
        }
        //cout << cnt << " -----> " << sum << dl;
        if(sum <= k and cnt <= m)
            ret[cnt].push_back(sum);
    }
 
    for(auto &i : ret)
        sort(all(i));
 
    return ret;
}
 
void Solve(){
 
    cin >> n >> m >> k;
    v.assign(n , 0); cin >> v;
 
    vector < vector < ll > > first_half = get_sums(0 , n / 2 - 1);
    vector < vector < ll > > second_half = get_sums(n / 2 , n - 1);
 
//    for(int i=0; i<sz(first_half); i++){
//        cout << i << " --> " << first_half[i] << dl;
//    }
 
    ll ans = 0;
 
    for(auto &i : first_half)
        ans += sz(i);
 
    for(auto &i : second_half)
        ans += sz(i);
 
    for(int i = 1; i<sz(first_half); i++){
        for(auto &it : first_half[i]){
 
            for(int j = 1; j<sz(second_half) and i + j <= m; j++)
                ans += upper_bound(all(second_half[j]) , k - it) - second_half[j].begin();
        }
    }
 
    cout << ans + 1 << dl;
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
