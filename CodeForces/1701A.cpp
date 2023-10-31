#include <bits/stdc++.h>

using namespace std;

int main(){
       int t; cin >> t;
       while(t--) {
              vector<int> a(4);
              int cnt = 0;
              for(auto& e : a){ cin >> e;
                     if(e == 1) cnt++;
              }
              
              if(cnt > 0) {
                if(cnt == 4) cout << 2 << endl;
                else cout << 1 << endl;
              } else cout << 0 << endl;
              
       }
}