#include <bits/stdc++.h>

using namespace std;

// long long gt(int n, int m) {
//     if(m==1, n==1) return 1;
//     if(m==0 || n == 0) return 0;
//     return gt(m-1,n) + gt(m,n-1);
// }

unordered_map<string, long long> mem;

long long gt(int n, int m) {
    stringstream ss;
    ss << n << '#' << m;
    string key = ss.str();

    if (mem.find(key) != mem.end())
        return mem[key];

    if (m == 1 && n == 1)
        return 1;
    if (m == 0 || n == 0)
        return 0;

     
}

int main() {
    int n,k; cin >> n >> k;
    unordered_map<int, long long> mem;
    cout << gt(n, k) << endl;
    return 0;
}