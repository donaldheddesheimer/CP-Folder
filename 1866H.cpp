#include <iostream>
using namespace std;

const int MOD = 998244353;

int main() {
    int N, K;
    cin >> N >> K;

    long long result = 1;

    for (int i = 1; i <= N; i++) {
        result = (result * K) % MOD;
    }

    cout << result << endl;

    return 0;
}
