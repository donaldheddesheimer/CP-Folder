#include <bits/stdc++.h>

using namespace std;

int main(){
       int t; cin >> t;
       while(t--) {
              int n,k; cin >> n >> k;
              vector<pair<int,int>> a(n);

              int temparr[n],temparr2[n];
              for(auto& e : temparr) cin >> e;
              for(auto& e : temparr2) cin >> e;
              
              int j = 0;
            for(auto& e : a){
                e.first = temparr[j];
                e.second = temparr2[j];
                j++;
            }

              sort(a.begin(),a.end());

                vector<pair<int,int>> b(n);
              for(int i = 0; i < n; i++) {
                b[i].first = a[i].second - a[i].first;
                b[i].second = a[i].first;
              }

              sort(b.begin(),b.end());
                int cnt = k;
              for(int i = n-1; i >= 0; i--) {
                if(k + b[i].first < 0) break;
                else {
                    k+=b[i].first;
                    cnt += b[i].second;
                }
              }
              
              cout << cnt << endl;
              
       }
}