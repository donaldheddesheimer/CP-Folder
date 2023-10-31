#include <bits/stdc++.h>

using namespace std;

// vector<int> howSum(int s, const vector<int>& a) {
//     if (s == 0) return {}; // Empty vector represents []
//     if (s < 0) return {-1};  // Empty vector represents []

//     for(auto& e : a) {
//         int r  = s - e;
//         auto res = howSum(r,a);
//         if(res.size() < 1 || res[0] != -1) {
//             res.push_back(e);
//             return res;
//         }
//     }

//     return {-1}; // No combination found, return an empty vector
// }

unordered_map<int,vector<int>> mem;
vector<int> howSum(int s, const vector<int>& a) {
    if(mem.find(s) != mem.end()) return mem[s];
    if (s == 0) return {}; 
    if (s < 0) return {-1}; 

    for(auto& e : a) {
        int r  = s - e;
        auto res = howSum(r,a);
        if(res.size() < 1 || res[0] != -1) {
            res.push_back(e);
            mem[s] = res;
            return mem[s];
        }
    }

    mem[s] = {-1};
    return mem[s]; 
}

int main() {
    int n,k; cin >> n >> k; 
    vector<int> a(n);
    for(auto& e : a) cin >> e;
    for(auto& e : howSum(k,a)) {
        cout << e << " ";
    } cout << endl;
    
    
    return 0;
}