#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define OO 2'000'000'000
#define ull unsigned long long
#define nl '\n'
#define sz(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define rall(s)  s.rbegin(), s.rend()
#define getline(s) getline(cin>>ws,s)
#define ceill(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define pi  3.141592653589793
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define multi_ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

 
void Fast_IO(){
ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
// freopen("filename.in", "r", stdin);
// freopen("filename.txt", "w", stdout);
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#endif
}




int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

const int MAXN = 1e5+5;

int parent[MAXN], siz[MAXN],n;
ll ans;

struct edge{
    int u, v, w;
};

edge edges[MAXN];

bool cmp(edge &a, edge &b){
    return a.w<b.w;
}

int find(int u){
    while(parent[u] != u){
        parent[u] = parent[parent[u]];
        u = parent[u];
    }
    return u;
}

void unite(int u, int v){
    u = find(u), v = find(v);
    if(siz[u] < siz[v]) swap(u, v);
    parent[v] = u;
    siz[u] += siz[v];
}

void DSU(){
    for(int i=1;i<=n;i++){
        parent[i] = i;
        siz[i] = 1;
    }

    sort(edges,edges+n-1,cmp);

    for(int i=0;i<n-1;i++){
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        int parent_u = find(u), parent_v = find(v);
        ans += 1LL * w * siz[parent_u] * siz[parent_v];
        unite(parent_u, parent_v);
    }
}


void solve(){
    cin>>n;

    for(int i=0;i<n-1;i++){
        int u, v, w;
        cin>>u>>v>>w;
        edges[i].u = u;
        edges[i].v = v;
        edges[i].w = w;
    }

    DSU();

    cout<<ans<<nl;


}
 
int main(){
    Fast_IO();
int t =1; 
//cin>>t;
while(t--){
solve();
}
return 0;
}  
