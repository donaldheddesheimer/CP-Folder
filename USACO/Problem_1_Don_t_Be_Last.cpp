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
int n;
void solve() {
    ifstream cin("notlast.in"); // Input file stream
    ofstream cout("notlast.out"); // Output file stream

    cin >> n;
    vector<pair<string, int>> a(7);
    a[0] = mp("Bessie", 0);
    a[1] = mp("Elsie", 0);
    a[2] = mp("Daisy", 0);
    a[3] = mp("Gertie", 0);
    a[4] = mp("Annabelle", 0);
    a[5] = mp("Maggie", 0);
    a[6] = mp("Henrietta", 0);

    while (n--) {
        string s;
        cin >> s;
        int t;
        cin >> t;
        for (auto& e : a) {
            if (e.F == s) {
                e.S += t;
            }
        }
    }

    sort(a.begin(), a.end(), [&](const pair<string, int>& a, const pair<string, int>& b) { return a.S < b.S; });

    bool chk = 1;
    for (int i = 0; i < 7; i++) {
        if (!(a[i].S == a[0].S)) {
            if(a[i].S != a[i+1].S){
                cout << a[i].F << endl;
                chk = 0;
            }
            break;
        }
    }

    if(chk) cout << "Tie" << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    solve();

    return 0;
}