/*
        submitedd by :)
        ███╗░░░███╗░█████╗░░██████╗████████╗░█████╗░███████╗░█████╗░
        ████╗░████║██╔══██╗██╔════╝╚══██╔══╝██╔══██╗██╔════╝██╔══██╗
        ██╔████╔██║██║░░██║╚█████╗░░░░██║░░░███████║█████╗░░███████║
        ██║╚██╔╝██║██║░░██║░╚═══██╗░░░██║░░░██╔══██║██╔══╝░░██╔══██║
        ██║░╚═╝░██║╚█████╔╝██████╔╝░░░██║░░░██║░░██║██║░░░░░██║░░██║
        ╚═╝░░░░░╚═╝░╚════╝░╚═════╝░░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░░░░╚═╝░░╚═╝

        //Don't wish for it  Work for it
*/

//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define output  freopen("/Users/mostafayoussef/CLionProjects/Test/input.txt","w",stdout);
#define input  freopen("input.txt","rt",stdin);
#define cin(v) for(auto &ele:v)cin>>ele
#define print(v) for(auto &ele:v)cout<<ele<<" "
#define all(v) v.begin(),v.end()
#define rv(x) return void(x)
#define pp pair<ll,ll>
#define ln cout<<endl;
#define yes cout<<"Yes\n"
#define no cout<<"No\n"
#define ll long long
#define vc vector
using namespace std;
int xd[4]={-1,0,1, 0};//,-1,-1, 1, 1};
int yd[4]={ 0,1,0,-1};//, 1,-1, 1,-1};
//===============================The solution===============================

void build(vc<vc<ll>> &v,int n){
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            v[i][j]+=v[i-1][j]+v[i][j-1]-v[i-1][j-1];
        }
    }
}
void solve() {
    int n,m;cin>>n>>m;
    vc<vc<ll>>v(n+1,vc<ll>(n+1,0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin>>v[i][j];
        }
    }
    build(v,n);
    ll ans=0;

    for (int i = m; i <= n; ++i) {
        for (int j = m; j <= n; ++j) {
            ans= max(ans,v[i][j]-v[i-m][j]-v[i][j-m]+v[i-m][j-m]);
        }
    }
    cout<<ans;

}

int main() {
    fast
    int t=1;cin>>t;
    while (t--){
        solve();ln
    }
}
