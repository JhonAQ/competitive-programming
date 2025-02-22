#include <bits/stdc++.h>

using namespace std;

unsigned long long memo[66][66][2];

unsigned long long dp(int n, int s, int state) {
    if (n == 0) {
        return s == 0 ? 1 : 0;
    }
    if (memo[n][s][state] != -1) { return memo[n][s][state];
    }

    unsigned long long res = 0;
    if (state == 0) { // Current drawer is unlocked
        res += dp(n - 1, s, 0);
        res += dp(n - 1, s, 1);
    } else { // Current drawer is locked
        res += dp(n - 1, s, 0);
        if (s > 0)
            res += dp(n - 1, s - 1, 1);
    }

    memo[n][s][state] = res;
    return res;
}

int main() {
    memset(memo, -1, sizeof(memo));
    int n, s;
    while (cin >> n >> s && (n >= 0 && s >= 0)) {
        if (s > n) {
            cout << 0 << endl;
            continue;
        }
        cout << dp(n, s, 1) << endl;
    }
    return 0;
}
