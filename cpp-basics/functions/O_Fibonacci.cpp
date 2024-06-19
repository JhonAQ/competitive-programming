#include <bits/stdc++.h>

using namespace std;

long long fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    long long fib_n_minus_2 = 0;  // Fib(0)
    long long fib_n_minus_1 = 1;  // Fib(1)
    long long fib;

    for (int i = 2; i <= n; ++i) {
        fib = fib_n_minus_2 + fib_n_minus_1;
        fib_n_minus_2 = fib_n_minus_1;
        fib_n_minus_1 = fib;
    }

    return fib;
}

int main() {
  int n;
  cin >> n;
  cout << fibonacci(n - 1);
  return 0;
}