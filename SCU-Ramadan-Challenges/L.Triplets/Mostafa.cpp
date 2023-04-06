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

void solve() {
    int n;cin>>n;
    vc<int>v(n);cin(v);
    sort(all(v));
    set<vc<int>>ans;
    for (int i = 0; i < n; ++i) {
        int target=-v[i];
        int l=i+1,r=n-1;
        while (l<r){
            int sum=v[l]+v[r];
            if (sum>target)r--;
            else if (sum<target)l++;
            else {
                vc<int>ele={v[l],v[r],v[i]};
                sort(all(ele));
                ans.insert(ele);
                l++;
            }
        }
    }
    if (ans.empty())cout<<-1;
    else {
        cout<<ans.size()<<endl;
        for (const auto& triplet:ans) {
            print(triplet);ln
        }
    }
}

int main() {
    fast
    int t=1;//cin>>t;
    while (t--){
        solve();ln
    }
}
