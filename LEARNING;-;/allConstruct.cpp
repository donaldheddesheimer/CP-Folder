#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> f(string target, vector<string>& wordBank, unordered_map<string, vector<vector<string>>>& memo) {
    if (memo.find(target) != memo.end()) return memo[target];
    if (target == "") return {{}};

    vector<vector<string>> result;

    for (const string& word : wordBank) {
        if (target.find(word) == 0) {
            string suffix = target.substr(word.length());
            vector<vector<string>> suffixWays = f(suffix, wordBank, memo);

            for (vector<string>& way : suffixWays) {
                vector<string> targetWay = {word};
                targetWay.insert(targetWay.end(), way.begin(), way.end());
                result.push_back(targetWay);
            }
        }
    }

    memo[target] = result;
    return result;
}


int main() {
    int n; string str; cin >> n >> str;
    vector<string> a(n);
    for(auto& e : a) cin >> e;
    unordered_map<string, vector<vector<string>>> mem;
    vector<vector<string>> ans = f(str,a,mem);
    for(auto& e : ans) {
        for(auto& d : e){
            cout << d << " ";
        }
        cout << '\n';
    }
    cout << endl;
}