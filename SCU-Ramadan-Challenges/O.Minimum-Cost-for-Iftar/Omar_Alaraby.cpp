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
 
ll n , m;
vector < vector < pair < int , int > > > adj;
ll Start , End;
 
ll bfs(int dir){
    queue < pair < int , int > > q;
    vector < vector < int > > distance(n + 2 , vector < int >(2 , 2e9));
    q.push({Start , dir});
    distance[Start][1] = distance[Start][0] = 0;
 
    while(not q.empty()){
        pair < int , int > curr = q.front();
        q.pop();
 
        for(auto &[l , r] : adj[curr.first]){
            if(distance[l][r] > distance[curr.first][curr.second] + (r != curr.second)){
                q.push({l , r});
                distance[l][r] = distance[curr.first][curr.second] + (r != curr.second);
            }
        }
    }
 
    return min(distance[End][1] , distance[End][0]);
}
 
void Solve(){
 
    cin >> n >> m;
    adj.assign(n + 1 , {});
 
    for(int i=0; i<m; i++){
        ll x , y; cin >> x >> y;
        adj[x].push_back(make_pair(y , 1));
        adj[y].push_back(make_pair(x , 0));
    }
 
    cin >> Start >> End;
 
    cout << min(bfs(0) , bfs(1)) << dl;
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
