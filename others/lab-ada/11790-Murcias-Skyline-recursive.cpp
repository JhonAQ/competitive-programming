
#include<bits/stdc++.h>
using namespace std;

vector<int> height, width, dp_inc, dp_dec;

int dp_inc_func(int i) {
    if (dp_inc[i] != -1) return dp_inc[i];
    int ans = width[i];
    for (int j = 0; j < i; ++j) {
        if (height[i] > height[j]) {
            ans = max(ans, dp_inc_func(j) + width[i]);
        }
    }
    dp_inc[i] = ans;
    return ans;
}

int dp_dec_func(int i) {
    if (dp_dec[i] != -1) return dp_dec[i];
    int ans = width[i];
    for (int j = 0; j < i; ++j) {
        if (height[i] < height[j]) {
            ans = max(ans, dp_dec_func(j) + width[i]);
        }
    }
    dp_dec[i] = ans;
    return ans;
}

int main() {
    int T, caseNum = 1;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        height.resize(N);
        width.resize(N);
        for (int i = 0; i < N; ++i) {
            cin >> height[i];
        }
        for (int i = 0; i < N; ++i) {
            cin >> width[i];
        }

        dp_inc.assign(N, -1);
        dp_dec.assign(N, -1);

        int max_inc = 0, max_dec = 0;
        for (int i = 0; i < N; ++i) {
            max_inc = max(max_inc, dp_inc_func(i));
            max_dec = max(max_dec, dp_dec_func(i));
        }

        if (max_inc >= max_dec) {
            cout << "Case " << caseNum << ". Increasing (" << max_inc << "). Decreasing (" << max_dec << ")." << endl;
        } else {
            cout << "Case " << caseNum << ". Decreasing (" << max_dec << "). Increasing (" << max_inc << ")." << endl;
        }
        caseNum++;
    }
    return 0;
}
