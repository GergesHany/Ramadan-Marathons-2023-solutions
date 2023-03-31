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

#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define output  freopen("/Users/mostafayoussef/CLionProjects/Test/input.txt","w",stdout);
#define input  freopen("input.txt","rt",stdin);
#define cin(v) for(auto &ele:v)cin>>ele
#define print(v) for(auto &ele:v)cout<<ele<<" "
#define all(v) v.begin(),v.end()
#define rv(x) return void(x)
#define pp pair<int,int>
#define ln cout<<endl;
#define yes cout<<"YES"
#define no cout<<"NO"
#define ll long long
#define vc vector
#define f first
//#define s second
using namespace std;
int xd[4]={-1,0,1, 0};//,-1,-1, 1, 1};
int yd[4]={ 0,1,0,-1};//, 1,-1, 1,-1};
//===============================The solution===============================

void solve(){
    ll n,q,p,r;cin>>n>>q>>p>>r;
    vc<ll>v(n+1,0);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        v[i] += v[i - 1];
    }
    for (int i = 1; i <= n; ++i) {
        int qInd= lower_bound(all(v),v[i-1]+q)-v.begin();
        if (qInd<=n&&v[qInd]==v[i-1]+q){
            int pInd= lower_bound(v.begin()+qInd,v.end(),v[qInd]+p)-v.begin();
            if (pInd<=n&&v[pInd]==v[qInd]+p){
                int rInd= lower_bound(v.begin()+pInd,v.end(),v[pInd]+r)-v.begin();
                if (rInd<=n && v[rInd]==v[pInd]+r)rv(yes);
            }
        }
    }
    no;
}

int main() {
    fast
    int t=1;//cin>>t;
    while (t--){
        solve();ln
    }
}



