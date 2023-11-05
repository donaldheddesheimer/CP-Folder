#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream fin("milkorder.in"); // Input file stream
    ofstream fout("milkorder.out"); // Output file stream
    int N,M,K; fin >> N >> M >> K;
    
    vector<int> order(N+1), fixed(N+1), hei(M);
    for(auto& e : hei) fin >> e;
    for(int i = 0; i < K; i++) {
        int c,p; fin >> c >> p;
        fixed[c] = p;
        order[p] = c;
    }

    if(fixed[1]) {
        fout << fixed[1] << endl;
        return 0;
    }

    //binary search alg
    int ptr = N;
    for(int i = M-1; i >= 0; --i){ 
        int cur = hei[i];
        if(cur==1) {
            for(int j = 0; j <= i; j++) {
                cur = hei[j];
                if(fixed[cur]) {
                    ptr = fixed[cur] + 1;
                    continue;
                }
                while(order[ptr]) ptr++;
                order[ptr] = cur;
                ptr++;
            }
            fout << ptr-1 << endl;
            return 0;
        }
        if(fixed[cur]) {
            ptr = fixed[cur] - 1;
            continue;
        }
        while(order[ptr]) ptr--;
        order[ptr] = cur;
        ptr--;
    }

    for(int i = 1; i <= N; i++) {
        if(order[i] ==0) {
            fout << i << endl;
            return 0;
        }
    }
    

}