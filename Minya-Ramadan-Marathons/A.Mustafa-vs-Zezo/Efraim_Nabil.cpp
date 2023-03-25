#include <bits/stdc++.h>
#define ll long long
#define OO 1e9
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define TC int t; cin >> t; while(t--)
using namespace std;
vector < int > dx = {1, -1, 0, 0, 1, -1, 1, -1};
vector < int > dy = {0, 0, 1, -1, 1, -1, -1, 1};
void Fero(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
    #endif
}


int main(){
    Fero();

    TC{
        string s;
        cin >> s;
        if(s == "2") cout << "Mustafa\n";
        else if(s[sz(s) - 1] == '0' || s[sz(s) - 1] == '2' || s[sz(s) - 1] == '4' || s[sz(s) - 1] == '6' || s[sz(s) - 1] == '8') cout << "Zezo\n";
        else cout << "Mustafa\n";
    }
    
    
    return 0;
}