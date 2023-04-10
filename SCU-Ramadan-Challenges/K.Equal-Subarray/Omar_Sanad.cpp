#include <bits/stdc++.h>

using namespace std;

#define cout_2d(vec,n,m)for(int Ii=0;Ii<n;Ii++,cout<<"\n")for(int Jj=0;Jj<m&&cout<<vec[Ii][Jj]<<" ";Jj++);
#define cin_2d(vec,n,m)for(int iii=0;iii<n;iii++)for(int jjj=0;jjj<m&&cin>>vec[iii][jjj];jjj++);
#define cout_map(mp) for(auto& [fff, sss] : mp) cout << fff << "  " << sss << "\n";
#define cout(vec) for(auto& iii : vec) cout << iii << " "; cout << "\n";
#define cin(vec) for(auto& iii : vec) cin >> iii
#define to_decimal(bin) stoll(bin, nullptr, 2)
#define unq(VEC) sort(all(VEC)); VEC.resize(unique(all(VEC)) - VEC.begin());
#define ll long long
#define ceil(N, M) ((N) / (M) + !!((N) % (M)))
#define dg(DG)   cout << #DG << ": " << (DG) << "\n"
#define dg1(DG) cout << #DG << ": " << (DG) << " || ";
#define dg3(DG1,DG2,DG3) {dg2(DG1, DG2) dg1(DG3)}
#define dg2(DG1, DG2) {dg1(DG1) dg1(DG2)}
#define dg4(DG1,DG2,DG3,DG4) {dg3(DG1,DG2,DG3) dg1(DG4)}
#define sz(x) (int)(x.size())
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define ff first
#define ss second
#define el "\n"
constexpr long long OO = 1 << 30, OOL = 1LL << 60, MOD = 1e9 + 7;
constexpr double EPS = 1e-9;
string get_binary(long long num){if(!num)return"";return get_binary(num/2)+(num%2?"1":"0");}
bool is_subseq(string p, string w){int szp = p.size(), szw = w.size(), ip=0, iw=0;
for (; ip < szp && iw < szw; iw++){if (p[ip] == w[iw]){ip++;}}  return ip == szp;}
vector<pair<int,int>>dxy4={{1,0},{0,1},{0,-1},{-1,0}};
vector<pair<int,int>>dxy8={{1,-1}, {0,-1}, {-1,-1}, {1,0}, {-1,0}, {1,1}, {0,1}, {-1,1}};
vector<pair<int,int>>dxyk={{-1,-2}, {-2,-1}, {1,-2}, {2,-1}, {-2,1}, {-1,2}, {1,2}, {2,1}};



void SOLVE(int ts_ctr) {
    int n;
    cin >> n;
    vector<int> v(n);
    cin(v);
    int lastsz = 0;
    int maxSz = 0;
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j < n && v[j] == v[i])   j++;
        int k = j;
        while (k < n && v[k] == v[j])   k++;

        maxSz = max(maxSz, 2 * min(lastsz, j - i));
        lastsz = k - j;
        maxSz = max(maxSz, 2 * min(j - i, k - j));
        maxSz = max(maxSz, ((j - i) / 2) * 2);
        maxSz = max(maxSz, ((k - j) / 2) * 2);

        i = k - 1;
    }

    cout << maxSz << el;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#if !defined(ONLINE_JUDGE)
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    // cout << fixed << setprecision(10);
    int testcases = 1;
    cin >> testcases;
    for (int test_ctr = 1; test_ctr <= testcases; test_ctr++)   SOLVE(test_ctr);
    /* cerr<<"Time Taken: "<<(float)clock()/CLOCKS_PER_SEC<<" Secs"<<"\n"; */
}
