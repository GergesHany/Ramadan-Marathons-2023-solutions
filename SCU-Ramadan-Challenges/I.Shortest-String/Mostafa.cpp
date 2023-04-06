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

string s;
bool can(int cnt){
    string sq=s.substr(0,cnt);
    for (int i = 0; i < s.size(); i+=cnt) {
        string cut=s.substr(i,cnt);
        if (cut!=sq)return false;
    }
    return true;
}
void solve() {
    cin>>s;
    for (int i = 1; i < s.size(); ++i) {
        if (s.size()%i==0 && can(i))rv(cout<<i);
    }
    cout<<-1;
}

int main() {
    fast
    int t=1;//cin>>t;
    while (t--){
        solve();
    }
}
