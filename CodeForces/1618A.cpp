#include <bits/stdc++.h>

using namespace std;

int main(){
       int t; cin >> t;
       while(t--) {
              vector<int> a(7);
              for(auto& e : a) cin >> e;
              cout << a[0] << " " << a[1] << " " << ((a[2] == a[1] + a[0]) ? a[3] : a[2]) << endl;
       }
}