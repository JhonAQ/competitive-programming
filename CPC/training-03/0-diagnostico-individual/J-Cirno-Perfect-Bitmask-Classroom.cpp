#include <bits/stdc++.h>

using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        long long int a;
        cin >> a;
        int idx = 0;

        while (idx <= 31) {
            if ((a >> idx) & 1) break;
            idx++;
        }
        long long int b = 1LL << idx;
        // long long int maskInv = ~a & ((1LL << idx) - 1);
        long long int maskInv = ~a & ((1 << 30) - 1);
        maskInv = maskInv & -maskInv;
        b = b | maskInv;
        cout << b <<endl;
    }
    
    return 0;
}
