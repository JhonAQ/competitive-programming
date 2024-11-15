
#include<bits/stdc++.h>

using namespace std;

unsigned long long dp[66][66][2];

int main() {
    memset(dp, 0, sizeof(dp));

    dp[0][0][0] = dp[0][0][1] = 1;

    for (int n = 1; n <= 65; ++n) {
        for (int s = 0; s <= n; ++s) {
            dp[n][s][0] = 0;
            dp[n][s][0] += dp[n-1][s][0];
            dp[n][s][0] += dp[n-1][s][1];

            dp[n][s][1] = 0;
            if (s > 0)
                dp[n][s][1] += dp[n-1][s-1][1];
            dp[n][s][1] += dp[n-1][s][0];
        }
    }

    int n, s;
    while (cin >> n >> s && (n >= 0 && s >= 0)) {
        if (s > n) {
            cout << 0 << endl;
            continue;
        }
        cout << dp[n][s][1] << endl;
    }
    return 0;
}
