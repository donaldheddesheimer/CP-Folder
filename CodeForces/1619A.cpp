#include <bits/stdc++.h>

using namespace std;

int main(){
       int t; cin >> t;
       while(t--){
              string s; cin >> s;
              int n = s.size();
              cout << (!(n % 2 == 1 || s.substr(0,n/2) != s.substr(n/2,n/2)) ? "YES" : "NO") << endl;
       } 
}