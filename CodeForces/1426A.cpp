#include <bits/stdc++.h>

using namespace std;

int main(){
       int t; cin >> t;
       while(t--) {
              int n,x; cin >> n >> x;
              cout << ((n <= 2) ? 1 : (n-3) / x+2) << endl;
       }
}