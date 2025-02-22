
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Trick {
    int t;      // Tiempo en el que ocurre el truco
    double p;   // Probabilidad de éxito
    int d;      // Tiempo perdido si falla
};

int main() {
    int n, r, m;
    cin >> n >> r >> m;

    vector<Trick> tricks(m);
    for (int i = 0; i < m; ++i) {
        cin >> tricks[i].t >> tricks[i].p >> tricks[i].d;
    }

    // DP array: tiempo esperado mínimo desde el truco i hasta el final
    vector<double> dp(m + 2, 0);
    dp[m + 1] = n; // Caso base: sin trucos restantes

    // Procesar los trucos en orden inverso
    for (int i = m; i >= 1; --i) {
        double continue_time = tricks[i - 1].t 
                               + tricks[i - 1].p * dp[i + 1] 
                               + (1 - tricks[i - 1].p) * (dp[i + 1] + tricks[i - 1].d);

        double restart_time = tricks[i - 1].t + dp[1];

        dp[i] = min(continue_time, restart_time);
    }

    // El resultado es el tiempo esperado mínimo desde el inicio
    printf("%.6f\n", dp[1]);
    return 0;
}
