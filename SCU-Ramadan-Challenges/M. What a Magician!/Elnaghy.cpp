#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>  
#include <ext/rope>
using namespace __gnu_pbds;
using namespace std;
/***************************************************************************************************************/
template <typename K, typename V, typename Comp = std::less<K>>
using ordered_map = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;

template <typename K, typename Comp = std::less<K>>
using ordered_set = ordered_map<K, null_type, Comp>;

template <typename K, typename V, typename Comp = std::less_equal<K>>
using ordered_multimap = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;

template <typename K, typename Comp = std::less_equal<K>>
using ordered_multiset = ordered_multimap<K, null_type, Comp>;

template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x : v) in >> x;
    return in;
}
template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) { 
    for (const T &x : v) out << x << ' '; 
    return out;
}
/***************************************************************************************************************/  
#define cin_2d(vec, n, m) for(int ii = 0; ii < n; ii++) for(int jj = 0; jj < m && cin >> vec[ii][jj]; jj++);
#define cout_2d(vec, n, m) for(int i = 0; i < n; i++, cout << "\n") for(int j = 0; j < m && cout << vec[i][j] << " "; j++);
#define cout_map(mp) for(auto& [f,s] :mp) cout<<f<<" "<<s<<"\n";
#define num_of_digit(n) ((int)log10(n)+1)
#define ll long long
#define oo 2000000000
#define sz(s) (ll) s.size()
#define Ceil(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define f(i,k,n) for (ll i = k; i < n; i++)
#define ln "\n"
#define all(vec) vec.begin(),  vec.end()
#define rall(s)  s.rbegin(), s.rend()
#define fixed(n) fixed << setprecision(n)
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
#define unq(VEC)  sort(all(VEC)); VEC.resize(unique(all(VEC)) - VEC.begin());
#define de cout<<"Here "<<ln; 
#define yes cout<<"YES"<<ln
#define no cout<<"NO"<<ln
#define put(x) return void(cout<<x<<ln)
#define pb push_back
//#define tolower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
typedef vector<int> vi;
typedef vector<ll> vl;  
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
//_________________________________C O D E___________________________________________//

void solve()
{
    int  n ; cin>>n;
    multiset<pair<int,int>>bst;
    f(i,0,n)
    {
        int x,y; cin>>x>>y;
        bst.insert({x,y});
    }
    ll ans = 0;

    while(bst.size() > 0)
    {
        int y = bst.begin()->second , se = 0;
        auto it = bst.lower_bound({y,0});
        while ( bst.size() > 0 and it != bst.end() and it->first == y )
        {
            se = it->second;
            bst.erase(it);
            y = se;
            it = bst.lower_bound({y,0});
        }
        if(bst.size() > 0) 
            bst.erase(bst.begin());
        ans++;
    }
    cout<<ans<<ln;
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    int testCases = 1; 
        // cin>>testCases;
    while(testCases--){
        solve(); 
    // cout<<ln;   
    } 
// Time;
}
