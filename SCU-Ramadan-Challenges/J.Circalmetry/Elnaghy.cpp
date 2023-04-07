  #include <bits/stdc++.h>
  #include <ext/pb_ds/assoc_container.hpp>
  #include <ext/pb_ds/tree_policy.hpp>  
  #include <ext/rope>
  using namespace __gnu_pbds;
  using namespace std;
  /***************************************************************************************************************/
  template <typename K, typename V, typename Comp = std::less<K>>
  using ordered_map = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;

  template <typename K, typename Comp = std::less<K>>
  using ordered_set = ordered_map<K, null_type, Comp>;

  template <typename K, typename V, typename Comp = std::less_equal<K>>
  using ordered_multimap = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;

  template <typename K, typename Comp = std::less_equal<K>>
  using ordered_multiset = ordered_multimap<K, null_type, Comp>;

  template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
      for (auto &x : v) in >> x;
      return in;
  }
  template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) { 
      for (const T &x : v) out << x << ' '; 
      return out;
  }
  /***************************************************************************************************************/  
  #define cin_2d(vec, n, m) for(int ii = 0; ii < n; ii++) for(int jj = 0; jj < m && cin >> vec[ii][jj]; jj++);
  #define cout_2d(vec, n, m) for(int i = 0; i < n; i++, cout << "\n") for(int j = 0; j < m && cout << vec[i][j] << " "; j++);
  #define cout_map(mp) for(auto& [f,s] :mp) cout<<f<<" "<<s<<"\n";
  #define num_of_digit(n) ((int)log10(n)+1)
  #define ll long long
  #define oo 2000000000
  #define sz(s) s.size()
  #define Ceil(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
  #define f(i,k,n) for (ll i = k; i < n; i++)
  #define ln "\n"
  #define all(vec) vec.begin(),  vec.end()
  #define rall(s)  s.rbegin(), s.rend()
  #define fixed(n) fixed << setprecision(n)
  #define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
  #define unq(VEC) sort(all(VEC)); VEC.resize(unique(all(VEC)) - VEC.begin());
  #define put(s) return void(cout << s << ln);
  #define de cout<<"Here"<<ln 
  #define yes cout<<"YES"
  #define no cout<<"NO"
  void zyad_elnaghy(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr), cout.tie(nullptr); 
      #ifndef ONLINE_JUDGE  
      freopen("input.txt","r" , stdin), freopen("output.txt","w",stdout);
      #endif 
  }
//__________________________________________________C O D E__________________________________________________//  


void solve(){
  long double x , r, pi = 3.141592654;
  cin >> x >> r;
  long double hight = sqrt( pow((x + r) , 2) - ( r * r)  );
  long double tri = 0.5 * r *hight;
  
  long double angle = acos(  r / (r + x)  ) *(180 / pi);
  

  angle = 180 - angle;
  long double cir = pi * r * r;
  long double arc = (angle / 360) * cir;
  cout << fixed(6) << arc + tri <<ln;

}
  int main()  
  { zyad_elnaghy();
    int testcases = 1;         
      cin >> testcases;
    while(testcases--){
        solve(); 
      //  cout<<ln;   
    } 
    // Time;
  }
