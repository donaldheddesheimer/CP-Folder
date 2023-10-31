#include <bits/stdc++.h>

using namespace std;

// int fib(int n) {
//     if(n <= 2) return 1;
//     return fib(n-1) + fib(n-2);
// }
unordered_map<int, long long> mem;
long long fib(int n) {
    if(n<=2) return 1;

    if(mem.find(n) != mem.end()) return mem[n];

    mem[n] = fib(n-1) + fib(n-2);
    return mem[n];
}

int main() {
    int n; cin >> n;
    unordered_map<int, long long> mem;
    cout << fib(n) << endl;
    return 0;
}