#include <bits/stdc++.h>

using namespace std;

unordered_map<int, vector<int>> mem;
vector<int> bestSum(int n, vector<int> a) {
    if(mem.find(n) != mem.end()) return mem[n];
    if(n==0) return {};
    if(n < 0) return {-1};
    vector<int> id = {-1};
    for(auto& e : a) {
        vector<int> r = bestSum(n-e, a);
        if(r.empty() || r[0] != -1) {
            r.push_back(e);
            if(id[0] == -1 || id.size() > r.size()) {
                id = r;
            }
        }
    }

    mem[n] = id;
    return mem[n];
    
}

int main() {
    int n,k; cin >> n >> k;
    vector<int> a(n);
    for(auto& e : a) cin >> e;
    auto ans = bestSum(k,a);
    for(auto &e : ans) cout << e << " ";
    cout << endl;
}