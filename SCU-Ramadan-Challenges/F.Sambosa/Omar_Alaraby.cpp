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
 
bool good(int i , int j , vector < int > &first , vector < int > &third){
    return binary_search(all(first) , i - 1) and binary_search(all(third) , j + 1);
}
 
void Solve(){
 
    ll n , p , q ,r ; cin >> n >> p >> q >> r;
    vector < ll > v(n); cin >> v;
 
    for(int i=1; i<n; i++)
        v[i] += v[i - 1];
 
    vector < int > first, third;
 
    for(int i=0; i<n; i++){
        if(v[i] == p)
            first.push_back(i);
        else if(v[i] > p){
            int idx = lower_bound(all(v) , v[i] - p) - v.begin();
            if(v[i] - v[idx] == p)
                first.push_back(i);
        }
    }
 
    for(int i=0; i<n; i++){
        if(v[i] == r)
            third.push_back(0);
        else if(v[i] > r){
            int idx = lower_bound(all(v) , v[i] - r) - v.begin();
            if(v[i] - v[idx] == r)
                third.push_back(idx + 1);
        }
    }
 
    if(first.empty() or third.empty())
        put("NO");
 
    for(int i=0; i<n; i++){
        if(v[i] >= q){
            int idx = lower_bound(all(v) , v[i] - q) - v.begin();
            if(v[i] - v[idx] == q and good(idx + 1,  i , first , third))
                put("YES");
        }
    }
    cout << "NO" << dl;
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
