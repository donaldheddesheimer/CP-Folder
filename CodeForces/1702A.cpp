#include <bits/stdc++.h>

using namespace std;

int main(){
       int t; cin >> t;
       while(t--) {
              int n; cin >> n;
              int cnt = 1;
              if(n < 10) cout << n - 1 << endl;
              else {
                while(n >= cnt * 10) {
                    cnt*=10;
                }

                cout << n - cnt << endl; 
              }
       }
}