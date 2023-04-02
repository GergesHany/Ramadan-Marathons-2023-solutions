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
 
const ll Mod = 1e8;
 
template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x : v) in >> x;
    return in;
}
 
template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) {
    for (const T &x: v) out << x << ' ';
    return out;
}
 
void Solve(){
 
    ll n; cin >> n;
    vector < ll > v(n); cin >> v;
 
    vector < vector < int > > adj(n , vector < int >());
    for(int i=0; i<n; i++){
        if(i != n - 1)
            adj[i].push_back(i + 1);
        if(v[i] - 1 != i)
            adj[i].push_back(v[i] - 1);
    }
 
    queue < int > q;
    q.push(0);
    vector < int > distance(n , -1);
    distance[0] = 0;
 
    while(not q.empty()){
        int curr = q.front();
        q.pop();
 
        for(auto &i : adj[curr])
            if(distance[i] == -1)
                distance[i] = distance[curr] + 1, q.push(i);
    }
 
    cout << distance[n - 1] << dl;
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
