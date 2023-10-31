#include <bits/stdc++.h>

using namespace std;

int main(){
       int t; cin >> t;
       while(t--) {
              string s; cin >> s;
              int ans = -1;
              for(int i = s.size() - 2; i >= 0; i--) {
                     if(s[0] != s[i]) {
                            ans = s.length() - 1;
                            break;
                     }
              }
              
              cout << ans << endl;
       }
}