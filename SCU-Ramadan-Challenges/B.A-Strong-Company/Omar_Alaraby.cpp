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
 
template < typename T = int > struct Modulo_multiplicative_inverse{
 
    Modulo_multiplicative_inverse() = default;
 
    T n, r, Mod;
    vector < T > fact, inv_fact;
 
    auto Take_mod(T a, T b) -> ll {
        return (a % mod * b % mod) % mod;
    };
 
    Modulo_multiplicative_inverse(T n, T r, T Mod) : n(n), r(r), Mod(Mod) {
        fact = vector < T > (n + 1, 1);
        inv_fact = vector < T > (n + 1, 1);
        for (T i = 1; i <= n; i++) {
            fact[i] = Take_mod(fact[i - 1], i);
            inv_fact[i] = Modulo_Inverse(fact[i]);
        }
    }
 
    T fast_power(T a, T b){
        T res = 1;
        while (b){
            if (b & 1) res = Take_mod(res, a);
            a = Take_mod(a, a);
            b >>= 1;
        }
        return res;
    }
 
    // fact[n] / (fact[r] * fact[n - r]) = fact[n] * (fact[r] * fact[n - r])^-1 = fact[n] * inv_fact[r] * inv_fact[n - r]
    T nCr(T n, T r){
        if (n < r) return 0;
        return Take_mod(fact[n], Take_mod(inv_fact[r], inv_fact[n - r]));
    }
 
    // fact[n] / fact[n - r] = fact[n] * (fact[n - r])^-1 = fact[n] * inv_fact[n - r]
    T nPr(T n, T r){
        if (n < r) return 0;
        return Take_mod(fact[n], inv_fact[n - r]);
    }
 
    T Modulo_Inverse(T a){
        return fast_power(a, Mod - 2);
    }
 
};
 
//ll ans = 0;
//
//void f(int size , int k , int sum){
//
//    if(!size and sum <= k){
//        ans++;
//        return;
//    }
//
//    if(sum > k)
//        return;
//
//    for(int i=1; i<=k; i++){
//        f(size - 1, k , sum + i);
//    }
//}
 
Modulo_multiplicative_inverse < ll > math;
 
void Solve(){
    ll n , k; cin >> n >> k;
 
//    for(int i=1; i<=n; i++){
//        f(i , k , 0);
//        cout << ans << ' ';
//        ans = 0;
//    }
//    cout << dl;
 
 
    ll ans = 0;
    for(int i=1; i<=n; i++){
        ans += math.nCr(k , i);
        ans %= mod;
    }
    cout << ans << dl;
}
 
int main(){
    Omar_Alaraby("input.txt" , "output.txt");
 
    int tc = 1;
    cin >> tc;
    math = Modulo_multiplicative_inverse < ll > (1e6, 1e6, mod);
 
    for(int i=1; i<=tc; i++){
        //cout << "Scenario #" << i << ":" << dl;
        Solve();
    }
 
    Time
    return 0;
}
