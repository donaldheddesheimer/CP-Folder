#include <bits/stdc++.h>

using namespace std;

int main(){
       int t; cin >> t;
       while(t--) {
              int n; cin >> n;
              int m = n/3 * 2;
              int m2 = n - m;
              
              if(m2 - m/2 == 2){
                     m+=2; m2-=2;
              }
              
              cout << m2 << " " << m/2 << endl;
       }
}