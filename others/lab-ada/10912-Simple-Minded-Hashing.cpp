
#include<bits/stdc++.h>

using namespace std;

int main() {
    const int maxL = 26;
    const int maxS = 351;

    int dp[maxL + 1][maxS + 1];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;

    for (int i = 1; i <= 26; ++i) {
        for (int l = maxL; l >= 1; --l) {
            for (int s = maxS; s >= i; --s) {
                dp[l][s] += dp[l - 1][s - i];
            }
        }
    }

    int minSum[maxL + 1];
    int maxSum[maxL + 1];
    minSum[0] = maxSum[0] = 0;
    for (int l = 1; l <= maxL; ++l) {
        minSum[l] = l * (l + 1) / 2;
        maxSum[l] = l * (53 - l) / 2;
    }

    int L, S;
    int caseNum = 1;
    while (cin >> L >> S) {
        if (L == 0 && S == 0) break;

        cout << "Case " << caseNum++ << ": ";

        if (L > 26 || L <= 0) {
            cout << "0" << endl;
            continue;
        }

        if (S < minSum[L] || S > maxSum[L]) {
            cout << "0" << endl;
            continue;
        }

        cout << dp[L][S] << endl;
    }

    return 0;
}
