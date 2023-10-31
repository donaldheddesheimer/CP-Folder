#include <bits/stdc++.h>

using namespace std;

int main(){
       int t; cin >> t;
       while(t--) {
              int n; cin >> n;
              string s; cin >> s;
              int cnt = 0;
              for(auto& e : s){
                     if(e == ')') cnt++;
                     else cnt = 0;
              }
              
              cout << ((cnt > n / 2) ? "YES" : "NO") << endl;
       }
}