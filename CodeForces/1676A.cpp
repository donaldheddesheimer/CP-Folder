#include <bits/stdc++.h>

using namespace std;

int main() {
       int t; cin >> t;
       while(t--) {
              int n; cin >> n;
              int cnt = 0, cntt = 0;
              for(int i = 0; i < 3; i++) {
                     cnt += n % 10;
                     n/=10;
              }
              for(int i = 0; i < 3; i++) {
                     cntt += n % 10;
                     n/=10;
              }
              
              cout << (cnt==cntt ? "YES" : "NO") << endl;
       }
}