#include <bits/stdc++.h>
using namespace std;
#pragma region Macros
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
mt19937_64
    rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
  uniform_int_distribution<int> uid(0, lim - 1);
  return uid(rang);
}
int mpow(int base, int exp);
void ipgraph(int n, int m);
void dfs(int u, int par);
#pragma endregion

int n;
void solve() {
    cin >> n;
    vi a(n), b(n);
    int cnt = 0,m=-21,mi = 0;
    
    for(int i = 0; i < n; i++){
      cin >> a[i];
      b[i] = a[i];
      if(a[i] > m){
        mi = i; 
        m = a[i];
      }
    }

    for(int i = 1 ; i < n; i++) {
      bool c = 1;
      while(b[i-1] > b[i]) {
        if(c) {
          b[i] += m;
          c = 0;
        } else {
          b[i] += b[i-1];
        }
        cnt++;
      }
    }
    
    cout << cnt << "\n";

    for(int i = 1 ; i < n; i++) {
      bool c = 1;
      while(a[i-1] > a[i]) {
        if(c) {
          a[i] += m;
          c = 0;
          cout << i+1 << ' ' << mi + 1 << endl;
        } else {
          a[i] += a[i-1];
          cout << i+1 << ' ' << i << endl;
        }
      }
    }

    
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}