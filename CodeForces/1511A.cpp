#include <bits/stdc++.h>

using namespace std;

int main(){
       int t; cin >> t;
       while(t--) {
              int n; cin >> n;
              vector<int> a(n);
              int cnt = 0;
              for(auto& e: a){ cin >> e;
                     if(e == 1 || e == 3) cnt++;
              }
              cout << cnt << endl;
       }
}