#include <bits/stdc++.h>

using namespace std;

int main(){
       int t; cin >> t;
       while(t--){
              int n; cin >> n;
              vector<long long> a(n);
              long long mine = INT_MAX;
              for(auto& e : a) {
                     cin >> e;
                     mine = min(mine,e);
              }
              long long cnt = 0;
              for(int i = 0; i < n; i++) {
                     cnt += (a[i] - mine);
              }
              cout << cnt << endl;
       }
}