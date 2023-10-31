#include <bits/stdc++.h>

using namespace std;

int main(){
       int t; cin >> t;
       while(t--) {
              int n; string s; cin >> n >> s;
              int a=-1,b=-1;
              for(int i = 1; i < n; i++) {
                     if(s[i] != s[i-1]){a=i;b=i+1;}
              }
              cout << a << " " << b << endl; 
       }
}