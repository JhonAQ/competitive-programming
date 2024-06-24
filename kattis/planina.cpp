#include <cstdio>

int main() {
    int n = 0;
    scanf("%d", &n);

    double points = 2;
    for (int i = 0; i < n; ++i)
        points += points - 1;

    printf("%.0lf\n", points * points);

    return 0;
}