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
using namespace std;
int xd[4]={-1,0,1, 0};//,-1,-1, 1, 1};
int yd[4]={ 0,1,0,-1};//, 1,-1, 1,-1};
//===============================The solution===============================

int even(int a){
    return a&1?a-1:a;
}

void solve() {
    int n;cin>>n;
    vc<int>v;
    int cnt=0,pre=-1;
    for (int i = 0; i < n; ++i) {
        int x;cin>>x;
        if (!i||x==pre)cnt++;
        else v.push_back(cnt),cnt=1;
        pre=x;
    }
    v.push_back(cnt);
    int ans=v[0];
    for (int i = 0; i < v.size()-1; ++i) {
        ans= max({ans,even(v[i]), even(v[i + 1]), 2 * min(v[i], v[i + 1])});
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
