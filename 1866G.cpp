#include <bits/stdc++.h>

using namespace std;

bool isPossible(vector<int>& passengers, vector<int>& doors, int Z) {
    int n = passengers.size();
    int prev_passengers = 0;
    
    for (int i = 0; i < n; i++) {
        int space = Z - passengers[i];
        
        if (space < 0) {
            return false;
        }
        
        if (i < n - 1) {
            space = min(space, doors[i]);
        }
        
        passengers[i] += space;
        passengers[i + 1] -= space;
        
        if (passengers[i] > Z) {
            return false;
        }
    }
    
    return true;
}

int findMinimumZ(vector<int>& passengers, vector<int>& doors) {
    int left = 0;
    int right = 1e9; // A large upper bound for binary search
    
    while (left < right) {
        int mid = (left + right) / 2;
        
        if (isPossible(passengers, doors, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> passengers(N);
    vector<int> doors(N);
    
    for (int i = 0; i < N; i++) {
        cin >> passengers[i];
    }
    
    for (int i = 0; i < N; i++) {
        cin >> doors[i];
    }
    
    int minimum_Z = findMinimumZ(passengers, doors);
    cout << minimum_Z << endl;
    
    return 0;
}
