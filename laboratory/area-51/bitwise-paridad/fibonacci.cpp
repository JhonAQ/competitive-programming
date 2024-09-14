#include <iostream>

using namespace std;

void printFibo(long n) {
  if (!n) return;

  long a = 0;
  long b = 1;

  cout << 0 << " ";

  for (long i = 1; i < n; i++) {
    long fibo = a + b;
    cout << fibo << " ";

    a = b;
    b = fibo;
  }
}

int main() {
  long n;
  cout << "Ingrese el numero de numeros a mostrar:" << endl;
  cin >> n;
  printFibo(n);
}