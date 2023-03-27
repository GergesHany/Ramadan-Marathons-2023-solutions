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

int n;
float r1,r2;
vc<vc<int>>v;
vc<vc<vc<int>>>memo;
int solve(int i=0,float a=0,float b=0){
    if (a!=0&&b!=0&&a/b==r1/r2)return 0;
    if (i>=n)return 1e9;
    int &ret=memo[i][(int)a][(int)b];
    if (ret!=-1)return ret;
    int ans=v[i][2]+ solve(i+1,a+(float)v[i][0],b+(float)v[i][1]);
    ans= min(ans, solve(i+1,a,b));
    return ret=ans;
}

int main() {
    fast
    cin>>n>>r1>>r2;
    v=vc<vc<int>>(n,vc<int>(3));
    memo=vc<vc<vc<int>>>(n,vc<vc<int>>(400,vc<int>(400,-1)));
    for (int i = 0; i < n; ++i) {
        cin>>v[i][0]>>v[i][1]>>v[i][2];
    }
    int ans=solve();
    cout<<(ans>=1e9?-1:ans);
}
