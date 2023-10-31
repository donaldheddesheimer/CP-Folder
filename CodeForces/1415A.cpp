#include <bits/stdc++.h>

using namespace std;

int main(){
       int t; cin >> t;
       while(t--) {
              int n,m,r,c; cin >> n >> m >> r >> c;
              cout << max(abs(n - r) + abs(m-c), n - abs(n - r) + m - abs(m - c)) << endl;
       }
}