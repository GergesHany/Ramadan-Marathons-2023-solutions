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
 
template < typename T = int, int Base = 1 > struct DSU {
    
    vector < T > parent, Gsize;
 
    DSU(int MaxNodes){
        parent = Gsize = vector < T > (MaxNodes + 5);
        for(int i = Base; i <= MaxNodes; i++)
          parent[i] = i, Gsize[i] = 1;
    }
    
    T find_leader(int node){
        return parent[node] = (parent[node] == node ? node : find_leader(parent[node]));
    }
 
    bool is_same_sets(int u, int v){
        return find_leader(u) == find_leader(v);
    }
 
    void union_sets(int u, int v){
        int leader_u = find_leader(u), leader_v = find_leader(v);
        if(leader_u == leader_v) return;
        if(Gsize[leader_u] < Gsize[leader_v]) swap(leader_u, leader_v);
        Gsize[leader_u] += Gsize[leader_v], parent[leader_v] = leader_u;
    }
 
    ll get_size(int u){
        return Gsize[find_leader(u)];
    }
};
 
struct edge{
    ll u , v , w;
    
    edge(int U = 0 , int V = 0 , int W = 0){
        u = U , v = V , w = W;
    }
 
    bool operator < (const edge& rhs) const{
        return w < rhs.w;
    }
};
 
 
void Solve(){
 
    ll n; cin >> n;
    vector < edge > edges(n - 1);
    DSU < ll > dsu(n);
 
    for(auto &[u , v , w] : edges)
        cin >> u >> v >> w;
 
    sort(all(edges));
    
    ll ans = 0;
    for(auto &[u , v , w] : edges){
        ans += w * (dsu.get_size(u) * dsu.get_size(v));
        dsu.union_sets(u , v);
    }
    cout << ans << dl;
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
