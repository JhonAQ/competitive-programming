#include<bits/stdc++.h>

using namespace std;

int main() {
    int T, caseNum = 1;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> height(N), width(N);
        for (int i = 0; i < N; ++i) {
            cin >> height[i];
        }
        for (int i = 0; i < N; ++i) {
            cin >> width[i];
        }

        vector<int> dp_inc(N), dp_dec(N);
        int max_inc = 0, max_dec = 0;

        for (int i = 0; i < N; ++i) {
            dp_inc[i] = width[i];
            dp_dec[i] = width[i];
            for (int j = 0; j < i; ++j) {
                if (height[i] > height[j]) {
                    if (dp_inc[j] + width[i] > dp_inc[i]) {
                        dp_inc[i] = dp_inc[j] + width[i];
                    }
                }
                if (height[i] < height[j]) {
                    if (dp_dec[j] + width[i] > dp_dec[i]) {
                        dp_dec[i] = dp_dec[j] + width[i];
                    }
                }
            }
            max_inc = max(max_inc, dp_inc[i]);
            max_dec = max(max_dec, dp_dec[i]);
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
