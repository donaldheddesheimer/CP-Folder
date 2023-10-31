#include <bits/stdc++.h>
using namespace std;
#pragma region Macros
#define gc getchar_unlocked
#define fo(n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
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

const int mod = 1'000'000'007;
const int N = 3e5, M = N;
ll n,k;

bool check(int mid, vi&b, vi&a, int n, int k) {
  int ans = INT_MAX;
  for(int i = 0;i < n-1; i++) {
    int r = mid;
    int s = 0;
    for(int j = i; j < n; j++) {
      if(b[j] >= r && a[j] < r) {s+=(abs(a[j] - r)); r--;}
      else if(a[j] >= r) break;
      else if(b[j] < r) {s = INT_MAX; break;}
    }
    ans = min(ans,s);
  }
  return ans <= k;
}

void solve() {
    cin >> n >> k;
    vi a(n);
    for(auto& e : a) cin >> e;
    vi b = a;
    for(int i = n-2; i>=0 ;i--) {
      if(b[i] <= b[i+1]) b[i] = b[i+1] + 1;
    }

    int low= *max_element(all(a));
    int high= *max_element(all(b));
    int ans= *max_element(all(a));

    while(low <= high) {
      int mid = low + (high - low) / 2;
      if(check(mid, b, a,n,k)) {low = mid+1; ans = max(ans,mid);}
      else high = mid-1;
    }

    cout << ans << endl;

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