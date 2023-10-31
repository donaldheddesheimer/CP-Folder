#include <bits/stdc++.h>

using namespace std;

int main(){
       int t; cin >> t;
       while(t--){
              int n; cin >> n;
              vector<int> a(n);
              for(auto& e : a) cin >> e;
              int cnt = 0, mx = 0;
              for(int i = 1; i < n; i++){
                     if((a[i] % 2 == 0 && a[i-1] % 2 == 0) || (a[i]%2==1 && a[i-1]%2==1)) cnt++;
              }
              
              cout << cnt << endl;
       }
}