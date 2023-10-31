#include <bits/stdc++.h>

using namespace std;

long long f(int n) {
    long long a = 0;
    long long b = 1;
    for(int i = 2; i<=n; i++) {
        long long c = a + b;
        a=b;
        b=c;
    }

    return b;
}

int main() {
    int n; cin >> n;
    cout << f(n) << endl;
}