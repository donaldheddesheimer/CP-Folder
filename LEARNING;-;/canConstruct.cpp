#include <bits/stdc++.h>

using namespace std;

unordered_map<string, bool> mem;
bool f(string s, vector<string> a) {
    if(mem.find(s) != mem.end()) return mem[s];
    if(s.empty()) return true;

    for(auto& e : a) {
        if(s.find(e) == 0) {
            string str = s.substr(e.size());
            if(f(str,a)) {mem[str] = true; return mem[str];}
        }
    }
    
    mem[s] = false;
    return false;
}

int main() {
    string target; int n; cin >> target >> n;
    vector<string> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << (f(target, a) ? "YES" : "NO") << endl;
}