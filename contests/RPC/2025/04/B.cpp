#include <bits/stdc++.h>
#define int long long
using namespace std;

bool isCorner(int x, int y) {
    return (x == 0 || x == 2024) && (y == 0 || y == 2024);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    bool c1 = isCorner(x1, y1);
    bool c2 = isCorner(x2, y2);
    int extra;
    if (c1 && c2) {
        extra = 0;
    } else if (c1 || c2) {
        extra = 1;
    } else {
        extra = 2;
    }

    cout << extra << "\n";
}
