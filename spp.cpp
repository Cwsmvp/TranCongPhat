#include <algorithm>
#include <cstdint>
#include <iostream>

using namespace std;

int check_spp(int n) {
    if (n <= 1) {
        return 0;
    }

    int64_t sum = 1;
    for (int i = 2; i <= n / i; ++i) {
        if (n % i == 0) {
            sum += i;
            if (n / i != i) {
                sum += n / i;
            }
            if (sum > n) {
                return 1;
            }
        }
    }

    return 0;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    if (!(cin >> a >> b)) {
        return 0;
    }

    int64_t total = 0;
    for (int64_t i = max(a, 1); i <= b; ++i) {
        if (check_spp(static_cast<int>(i))) {
            ++total;
        }
    }
    cout << total;
    return 0;
}
