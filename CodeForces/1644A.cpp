#include <bits/stdc++.h>

using namespace std;

int main(){
       int t; cin >> t;
       while(t--) {
              string s; cin >> s;
              string a = "RGB", b = "rgb";
              bool check = 1;
              for(int i = 0; i < 3; i++) {
                     size_t l_pos = s.find(b[i]);
                     size_t u_pos = s.find(a[i]);
                     if(u_pos < l_pos) check = 0;
              }
              cout << (check ? "YES" : "NO") << endl;
       }
}