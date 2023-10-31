#include <bits/stdc++.h>

using namespace std;

int main(){
       int t; cin >> t;
       while(t--) {
              int n; cin >> n;
              vector<int> a(n);
              for(auto& e : a) cin >> e;
              sort(a.begin(), a.end(), [](int x, int y){if(x%2 != y!=2) return (x%2 > y%2); else return x < y;});
              for(auto& e : a) cout << e << " "; cout << endl;
       }
}