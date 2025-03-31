#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k, p;
        cin >> n >> k >> p;

        int max_sum = n * p;
        int min_sum = n * (-p);

        if (k > max_sum || k < min_sum) {
            cout << -1 << endl;
        } else {
            int target_sum = abs(k);
            int max_add_per_operation = p;

            int operations = target_sum / max_add_per_operation;

            if (target_sum % max_add_per_operation != 0) {
                operations++;
            }

            cout << min(operations, n) << endl;
        }
    }
}
