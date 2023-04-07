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

    int n;
    cin >> n;
    vector < pair < int, int > > v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(all(v));
    multiset < int, greater < int > > s;
    for(int i = 0; i < n; i++){
        auto it = s.find(v[i].first);
        if(it != s.end()){
            s.erase(it);
        }
        s.insert(v[i].second);
    }
    cout << sz(s) << endl;
    
    return 0;
}
