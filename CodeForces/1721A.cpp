#include <bits/stdc++.h>

using namespace std;

int main(){
       int t; cin >> t;
       while(t--) {
              string s1,s2; cin >> s1 >> s2;
              vector<char> a(4);
              a[0] = s1[0]; a[1] = s1[1]; a[2] = s2[0]; a[3] = s2[1];
              sort(a.begin(), a.end());
              int cnt = 0;
              for(int i = 1; i < 4; i++) {
                     if(a[i] != a[i-1]) cnt++;
              }
              cout << cnt << endl;
       }
}