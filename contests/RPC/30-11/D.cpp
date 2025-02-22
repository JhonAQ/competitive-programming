
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#define int long long
using namespace std;


const int MOD = 1e9 + 7;

// Exponenciación modular rápida
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

signed main() {
    int n, q;
    double p;
    cin >> n >> q >> p;

    long long p_inv = modExp(1e9 + 7 - 1 - p * 1e9, MOD - 2, MOD); // Inverso modular de (1 - p)
    vector<long long> lights(n + 1, 0); // Intensidad en cada punto

    for (int i = 0; i < q; ++i) {
        char op;
        cin >> op;

        if (op == '+') {
            int b, x;
            cin >> b >> x;
            lights[x] += b;
        } else if (op == '-') {
            int b, x;
            cin >> b >> x;
            lights[x] -= b;
        } else if (op == '?') {
            int x;
            cin >> x;

            long long total_intensity = 0;
            for (int i = 1; i <= n; ++i) {
                if (lights[i] > 0) {
                    int distance = abs(i - x);
                    total_intensity += (lights[i] * modExp(p_inv, distance, MOD)) % MOD;
                    total_intensity %= MOD;
                }
            }
            cout << total_intensity << endl;
        }
    }

    return 0;
}
