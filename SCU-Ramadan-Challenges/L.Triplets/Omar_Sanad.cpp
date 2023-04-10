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

constexpr int NN = 2e5 + 10, SHIFT = 1e5;
int freq[NN];

bool good(int num) {
    return num >= -1e5 && num <= 1e5;
}


void SOLVE(int ts_ctr) {
    int n;
    cin >> n;
    int v[n];
    vector<int> tmpvec(n);
    for (int i = 0; i < n; i++)
        cin >> v[i], tmpvec[i] = v[i], freq[v[i] + SHIFT]++;

    vector < vector < int > > Ans;
    if (freq[0 + SHIFT] >= 3)   Ans.push_back({0, 0, 0});
    if (freq[0 + SHIFT]) {
        for (int i = 0; i < n; i++)
            if (freq[-v[i] + SHIFT] && v[i] < 0)
                Ans.push_back({0, v[i], -v[i]});
    }
    freq[0 + SHIFT] = 0;

    unq(tmpvec);
    if (tmpvec.front() == 0)
        swap(tmpvec.front(), tmpvec.back()), tmpvec.pop_back();

    for (int i = 0; i < sz(tmpvec); i++)
        if (freq[tmpvec[i] + SHIFT] >= 2 && good(tmpvec[i] * 2) && freq[tmpvec[i] * -2 + SHIFT])
            Ans.push_back({tmpvec[i], tmpvec[i], -2 * tmpvec[i]});

    for (auto &I : freq)
        if (I)
            I = 1;


    vector<int> NOW;
    for (int i = 0; i < sz(tmpvec); i++)
        if (tmpvec[i]) {
            freq[tmpvec[i] + SHIFT] = 0;
            for (int j = i + 1; j < sz(tmpvec); j++)
                if (tmpvec[j] != tmpvec[i] && -tmpvec[i]-tmpvec[j] != tmpvec[i] && -tmpvec[i]-tmpvec[j] != tmpvec[j] && freq[tmpvec[j] + SHIFT] > 0 && good(tmpvec[j] + tmpvec[i]) && freq[-tmpvec[j] -tmpvec[i] + SHIFT] > 0) {
                    // freq[tmpvec[j] + SHIFT] = 0;
                    NOW = {tmpvec[i], tmpvec[j], -tmpvec[j] -tmpvec[i]};
                    sort(all(NOW));
                    Ans.push_back(NOW);
                }
        }

    unq(Ans);

    cout << (sz(Ans) ? sz(Ans) : -1) << el;
    for (auto &vec : Ans)
        for (auto &I : vec)
            cout << I << " \n"[&I == &vec.back()];
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // cout << fixed << setprecision(10);
    int testcases = 1;
    // cin >> testcases;
    for (int test_ctr = 1; test_ctr <= testcases; test_ctr++)   SOLVE(test_ctr);
    /* cerr<<"Time Taken: "<<(float)clock()/CLOCKS_PER_SEC<<" Secs"<<"\n"; */
}
