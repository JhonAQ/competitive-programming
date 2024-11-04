#include <iostream>

using namespace std;

int ks(int i, int w, int C[], int W[]) {
    if (w == 0 || i == 0) {
        return 0;
    } else {
        if (w < W[i - 1]) {
            return ks(i - 1, w, C, W);
        } else {
            return max(ks(i - 1, w, C, W), C[i - 1] + ks(i - 1, w - W[i - 1], C, W));
        }
    }
}

int ksM(int i, int w, int C[], int W[], int M[][6]) { 
    if (w == 0 || i == 0) {
        return 0;
    } else {
        if (M[i - 1][w] == -1) {
            if (w < W[i - 1]) {
                M[i - 1][w] = ksM(i - 1, w, C, W, M);
            } else {
                M[i - 1][w] = max(ksM(i - 1, w, C, W, M), C[i - 1] + ksM(i - 1, w - W[i - 1], C, W, M));
            }
        }
        return M[i - 1][w];
    }
}

int main() {
    int C[] = {5, 7, 9, 14};
    int W[] = {3, 3, 2, 5};
    int n = sizeof(C) / sizeof(C[0]);
    int wl = 5;


    cout << "Sin memoizacion: " << ks(n, wl, C, W) << endl;

    int M[4][6];
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 6; ++j) {
            M[i][j] = -1;
        }
    }

    cout << "Con memoizacion: " << ksM(n, wl, C, W, M) << endl;

    return 0;
}
