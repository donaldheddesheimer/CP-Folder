#include <bits/stdc++.h>

using namespace std;

int main(){
       int t; cin >> t;
       while(t--){
              int n; cin >> n;
              vector<int> a(n);
              for(auto& e : a) cin >> e;
              bool check = 0;
              for(int i = 0; i < n; i++) {
                     if(a[i] <= i+1) check = 1;
              }
              
              cout << (check ? "YES" : "NO") << endl;
       } 
}