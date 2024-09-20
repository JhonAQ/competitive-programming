#include <iostream>
#include <numeric>

using namespace std;

int gcd_extrem(int N) {
  int G = 0;
  for (int i = 1; i < N; i++)
    for (int j = i + 1; j <= N; j++)
      G += gcd(i, j);

  return G;
}

void print(int results[], int len) {
  for (int i = 0; i < len; i++)
    cout << results[i] << endl;
}

int main(void) {
  int i = 0, n, results[100];

  while (n != 0) {
    cin >> n;
    cout << n << endl;
    results[i++] = gcd_extrem(n);
  }

  print(results, i);

  return 0;
} 
