
#include<bits/stdc++.h>
using namespace std;

const int maxL = 26;
const int maxS = 351;

int dp[maxL + 1][maxS + 1][maxL + 1]; // l, s, start

int count(int l, int s, int start) {
    if (l == 0 && s == 0) return 1;
    if (l == 0 || s < 0 || start > 26) return 0;
    if (dp[l][s][start] != -1) return dp[l][s][start];
    int res = 0;
    for (int i = start; i <= 26; ++i) {
        res += count(l - 1, s - i, i + 1);
    } dp[l][s][start] = res;
    return res;
}

int main() {
    memset(dp, -1, sizeof(dp));

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

        cout << count(L, S, 1) << endl;
    }

    return 0;
}
