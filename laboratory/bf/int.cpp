#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int n;
vector<int> a, b;
vector<vector<int>> table;
long long count_ways = 0;

bool is_valid(int row, int col, int num) {
    if (row == 0) {
        if (col > 0 && table[row][col - 1] >= num) return false;
        if (table[row + 1][col] != 0 && table[row + 1][col] <= num) return false;
        for (int x : a) {
            if (x == num && row != 0) return false;
        }
    } else {
        if (col > 0 && table[row][col - 1] >= num) return false;
        if (table[row - 1][col] != 0 && table[row - 1][col] >= num) return false;
        for (int x : b) {
            if (x == num && row != 1) return false;
        }
    }
    return true;
}

void solve(int k) {
    if (k == 2 * n + 1) {
        count_ways++;
        return;
    }

    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < n; col++) {
            if (table[row][col] == 0) {
                if (is_valid(row, col, k)) {
                    table[row][col] = k;
                    solve(k + 1);
                    table[row][col] = 0; 
                }
                return; // Important optimization: Once a cell is found, no need to check other cells for the same number
            }
        }
    }
}

int main() {
    cin >> n;

    int x;
    cin >> x;
    a.resize(x);
    for (int i = 0; i < x; i++) {
        cin >> a[i];
    }

    int y;
    cin >> y;
    b.resize(y);
    for (int i = 0; i < y; i++) {
        cin >> b[i];
    }

    table.resize(2, vector<int>(n, 0));
    solve(1);

    cout << count_ways % 998244353 << endl;

    return 0;
}
