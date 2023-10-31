#include <iostream>
#include <cmath>

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        int a, b, c;
        std::cin >> a >> b >> c;

        int d1 = a - 1;
        int d2 = std::abs(b - c) + c - 1;
        int ans = 0;

        if (d1 <= d2) {
            ans += 1;
        }
        if (d1 >= d2) {
            ans += 2;
        }

        std::cout << ans << std::endl;
    }

    return 0;
}
