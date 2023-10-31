#include <bits/stdc++.h>
using namespace std;

const int64_t mod = 998244353;

int64_t calc(int n, int r) {
    vector<int64_t> fact(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    vector<int64_t> inv_fact(n + 1);
    inv_fact[n] = 1;
    for (int i = n - 1; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
    }
    return (fact[n] * inv_fact[r] % mod * inv_fact[n - r] % mod) % mod;
}

int64_t solv(int n, vector<int>& a, vector<int>& b, int m, vector<int>& c, vector<int>& d) {
    vector<pair<int, int>> factors_x;
    vector<pair<int, int>> factors_y;
    for (int i = 0; i < n; i++) {
        factors_x.push_back({a[i], b[i]});
    }
    for (int i = 0; i < m; i++) {
        factors_y.push_back({c[i], d[i]});
    }
    int64_t ans = 1;
    for (auto factor_y : factors_y) {
        int prime_y = factor_y.first;
        int exp_y = factor_y.second;
        bool flag = false;
        int max_valid_exp = 0;
        for (auto factor_x : factors_x) {
            int prime_x = factor_x.first;
            int exp_x = factor_x.second;
            if (prime_x == prime_y) {
                max_valid_exp = max(max_valid_exp, exp_x);
            }
        }
        if (max_valid_exp < exp_y) {
            return 0;
        }
        int valid_exp = max_valid_exp - exp_y + 1;
        ans = (ans * calc(valid_exp, 1)) % mod;
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    cin >> m;
    vector<int> c(m), d(m);
    for (int i = 0; i < m; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> d[i];
    }
    int64_t ans = solv(n, a, b, m, c, d);
    cout << ans << endl;
    return 0;
}
