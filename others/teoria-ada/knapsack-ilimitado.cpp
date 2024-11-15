#include <iostream>

using namespace std;

int uksMemo(int i, int w, int C[], int W[], int M[][8]) {
    if (w == 0 || i == 0) {
        return 0;
    } else if (M[i][w] != -1) {
        return M[i][w];
    } else {
        if (w < W[i - 1]) {
            M[i][w] = uksMemo(i - 1, w, C, W, M);
        } else {
            M[i][w] = max(uksMemo(i - 1, w, C, W, M), C[i - 1] + uksMemo(i, w - W[i - 1], C, W, M));
        }
        return M[i][w];
    }
}

int uks(int i, int w, int C[], int W[]) {
    if (w == 0 || i == 0) {
        return 0;
    } else {
        if (w < W[i - 1]) {
            return uks(i - 1, w, C, W);
        } else {
            return max(uks(i - 1, w, C, W), C[i - 1] + uks(i, w - W[i - 1], C, W));
        }
    }
}

int main() {
    int C[] = {5, 7, 9, 14};
    int W[] = {3, 3, 2, 5};
    int n = sizeof(C) / sizeof(C[0]);
    int wl = 7;

    // Memo
    int M[5][8];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= wl; j++) {
            M[i][j] = -1;
        }
    }

    cout << "Resultado con memoizacion: " << uksMemo(n, wl, C, W, M) << endl;


    cout << "Resultado sin memoizacion: " << uks(n, wl, C, W) << endl;

    return 0;
}
