#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int numTeclas;
    cin >> numTeclas;

    vector<int> originalT(numTeclas);
    vector<int> diff(numTeclas);

    for (int i = 0; i < numTeclas; ++i) {
        cin >> originalT[i];
        diff[i] = originalT[i] - i;
    }

    nth_element(diff.begin(), diff.begin() + numTeclas / 2, diff.end());
    int mediana = diff[numTeclas / 2];

    if (numTeclas % 2 == 0) {
        nth_element(diff.begin(), diff.begin() + numTeclas / 2 - 1, diff.end());
        mediana = (mediana + diff[numTeclas / 2 - 1]) / 2;
    }

    int ans = 0;
    for (int i = 0; i < numTeclas; ++i) {
        ans += abs(diff[i] - mediana);
    }

    cout << ans << endl;
    return 0;
}

