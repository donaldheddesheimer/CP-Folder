#include <bits/stdc++.h> 

using namespace std;

unordered_map<string, int> mem;
int f(string s, vector<string> a) {
    if(mem.find(s) != mem.end()) return mem[s];
    if(s.empty()) return 1;
    int cnt = 0;
    for(auto& e : a) {
        if(s.find(e) == 0) {
            string str = s.substr(e.size());
            int t = f(str,a);
            if(t != 0) {mem[str] = t; cnt+= t;}
        }
    }
    
    mem[s] = cnt;
    return cnt;
}

int main() {
    string target; int n; cin >> n >> target;
    vector<string> a(n);
    for(auto& e : a) cin >> e;
    cout << f(target, a) << endl;
}