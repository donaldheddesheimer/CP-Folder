#include <iostream>
#include <vector>
#include <stack>
using namespace std;
const int MOD = 998244353;

vector<vector<pair<int, int>>> graph; 
vector<int> Z; 

long long count_inversions() {
    int n = Z.size();
    vector<int> bit_count(n + 1, 0);
    long long inversions = 0;

    for (int i = n - 1; i >= 0; i--) {
        int val = Z[i];
        for (int j = val; j > 0; j -= (j & -j)) {
            inversions += bit_count[j];
        }

        for (int j = val + 1; j <= n; j += (j & -j)) {
            bit_count[j]++;
        }
    }

    return inversions % MOD;
}

void dfs(int start) {
    stack<int> stk;
    stk.push(start);

    while (!stk.empty()) {
        int v = stk.top();
        stk.pop();

        for (auto& edge : graph[v]) {
            int u = edge.first;
            int w = edge.second;
            Z.push_back(w);
            stk.push(u);
        }
    }
}

int main() {
    int N;
    cin >> N;

    graph.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        int Si;
        cin >> Si;

        for (int j = 1; j <= Si; j++) {
            int Li, Wi;
            cin >> Li >> Wi;
            graph[i].emplace_back(Li, Wi);
        }
    }

    Z.clear();
    dfs(1); // Perform iterative DFS starting from vertex 1

    long long result = count_inversions();
    cout << result << endl;

    return 0;
}
