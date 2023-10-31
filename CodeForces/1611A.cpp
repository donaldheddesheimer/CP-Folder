#include <bits/stdc++.h>

using namespace std;

int main(){
       int t; cin >> t;
       while(t--){
              long long n; cin >> n;
              if(n % 2 == 0) cout << 0 << endl;
              else {
                     bool last = 0;
                     bool hasEven = 0;
                     while(n != 0) {
                            if((n % 10) % 2 == 0) {
                                   hasEven = 1;
                                   last = 1;
                            } else last = 0;
                            n/=10;
                     }
                     
                     if(last) cout << 1 << endl;
                     else if(hasEven) cout << 2 << endl;
                     else cout << -1 << endl;
        }
       }
}