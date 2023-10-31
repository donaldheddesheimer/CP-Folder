#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int minElectricityFee(int N, int Q, vector<int>& A, vector<vector<int>>& events) {
    vector<vector<int>> dp(N, vector<int>(2, INF));
    dp[0][0] = 0;

    for (int i = 0; i < Q; ++i) {
        int a = A[i];
        vector<int>& event = events[i];

        if (event[0] == 1) {
            int x = event[1] - 1;
            int y = event[2] - 1;

            vector<vector<int>> new_dp(N, vector<int>(2, INF));

            for (int floor = 0; floor < N; ++floor) {
                for (int elevator = 0; elevator < 2; ++elevator) {
                    if (dp[floor][elevator] == INF) {
                        continue;
                    }

                    int cost = dp[floor][elevator] + a * abs(floor - x);
                    new_dp[y][elevator] = min(new_dp[y][elevator], cost);

                    if (elevator == 0) {
                        new_dp[floor][1] = min(new_dp[floor][1], dp[floor][0] + a * (abs(floor - x) + abs(x - y)));
                    }
                }
            }

            dp = new_dp;
        } else {
            int p = event[1] - 1;
            swap(dp[p][0], dp[p][1]);
        }
    }

    for(auto &e : dp) for(auto &z : e) cout << z << " ";
    cout << endl;

    int minCost = min(dp[N - 1][0], dp[N - 1][1]);
    return minCost;
}

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> A(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> A[i];
    }

    vector<vector<int>> events(Q, vector<int>(3));
    for (int i = 0; i < Q; ++i) {
        cin >> events[i][0];
        if (events[i][0] == 1) {
            cin >> events[i][1] >> events[i][2];
        } else {
            cin >> events[i][1];
        }
    }

    int result = minElectricityFee(N, Q, A, events);
    cout << result << endl;

    return 0;
}
