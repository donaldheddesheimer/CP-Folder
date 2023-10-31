#include <bits/stdc++.h>

using namespace std;

bool cs(long long n, vector<int> a) {
    if(n == 0) return true;
    if(n < 0) return false;

    for(auto& e : a) {
        if(cs(n-e, a)) return true;
    }

    return false;
}

// unordered_map<int, bool> mem;
// bool cs(int n, vector<int> a) {
//     if(mem.find(n) != mem.end()) return mem[n];
//     if(n == 0) return true;
//     if(n < 0) return false;

//     for(auto& e : a) {
//         if(cs(n-e, a)){
//             mem[n-e] = true;
//             return mem[n-e];
//         }
//     }

//     mem[n] = false;
//     return mem[n];
// }

int main() {
    long long n,k; cin >> n >> k;
    vector<int> a(n);
    for(auto& e : a) cin >> e;
    cout << (cs(n,a) ? "TRUE" : "FALSE") << endl;
    return 0;
}