#include <bits/stdc++.h>

using namespace std;

int main(){
       int t; cin >> t;
       while(t--) {
              string str; cin >> str;
              unordered_map<char, int> map;
              for(int i = 0; i < 26; i++) {
                     map[str[i]] = i+1;
              }
              
              string word; cin >> word;
              int cnt = 0;
              for(int i = 1; i < word.size(); i++){
                     cnt += abs(map[word[i]] - map[word[i-1]]);
              }
              
              cout << cnt << endl;
       }
}