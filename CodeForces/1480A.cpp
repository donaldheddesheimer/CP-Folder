#include <bits/stdc++.h>

using namespace std;

int main() {
       int t; cin >> t;
       while(t--) {
              string s; cin >> s;
              bool b = 0;
              for(auto& e : s){
                     if(!b) cout << ((e != 'a') ? "a" : "b");
                     else cout << ((e != 'z') ? "z" : "y");
                     b = !b;
              }
              
              cout << endl;
       }
}