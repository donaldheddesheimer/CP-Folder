#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);

    int N; string S; cin >> N >> S;
    if(N<=2) {cout << 1 << endl; return 0;}
    for(int guess = 2; guess <= N; guess++) {
        bool chk = true;
        for(int i = 0; i + guess <= N; i++) {
            for(int j = 0; j < i; j++) {
                if(S.substr(i, guess) == S.substr(j, guess)) chk = false;
            }
        }
        if(chk) {cout << guess << endl; break;}
    }
}   