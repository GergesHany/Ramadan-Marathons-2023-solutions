#include <bits/stdc++.h>
#define ll long long
#define OO 1e9
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.ren()
#define TC int t; cin >> t; while(t--)
using namespace std;
void Fero(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
    #endif
}



int main(){
    Fero();

    ll n, m;
    cin >> n >> m;
    map < string, string > mp;
    for(int i = 0; i < n; i++){
        string a, b;
        cin >> a >> b;
        mp[a] = b;
    }
    for(int i = 0; i < m; i++){
        string a, b;
        cin >> a >> b;
        if(mp[a] == b){
            cout << "Allow" << endl;
        }else{
            cout << "Block" << endl;
        }
    }



    return 0;
}
