#include <bits/stdc++.h>

using namespace std;

int main() {
       int t; cin >> t;
       while(t--) {
              long long n,l,r,k; cin >> n >> l >> r >> k;
              vector<int> a;
              for(int i = 0; i < n; i++) {
                     long long temp; cin >> temp;
                     if(temp >= l && temp <= r) {
                            a.push_back(temp);
                     }
              }
              
              sort(a.begin(),a.end());
              
              long long cnt = 0, cost = 0;
              for(auto&e : a){
                if(cost + e > k) break;
                else {
                    cost += e;
                    cnt++;
                }
              }
              
              cout << cnt << endl;
       }
}