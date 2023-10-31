#include <bits/stdc++.h>

using namespace std;

int main(){
       int t; cin >> t;
       while(t--) {
              int n,m; cin >> n >> m;
              vector<int> a(n);
              int tot = 0;
              for(auto& e : a) {
                     cin >> e;
                     tot += e;
              }
              cout << ((m - tot >= 0) ? 0 : tot-m) << endl;
       }
}