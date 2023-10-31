#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

long long mod_pow(long long x, long long y) {
    long long result = 1;
    x %= MOD;
    while (y > 0) {
        if (y % 2 == 1) {
            result = (result * x) % MOD;
        }
        x = (x * x) % MOD;
        y /= 2;
    }
    return result;
}

int main() {
    int N;
    cin >> N;
    
    long long numerator = 1, denominator = 1;

    for (int i = 1; i <= N; i++) {
        int P;
        cin >> P;
        
        // Calculate the inverse modulo of P
        long long inv_P = (P == 0) ? 0 : mod_pow(P, MOD - 2);
        
        numerator = (numerator * i) % MOD;
        denominator = (denominator * (1 - inv_P + MOD)) % MOD;
    }

    // Calculate the expected value modulo 998244353
    long long expected_value = (numerator * mod_pow(denominator, MOD - 2)) % MOD;
    cout << expected_value << endl;

    return 0;
}
