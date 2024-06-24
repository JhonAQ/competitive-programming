#include <bits/stdc++.h>
using namespace std;

int main() {
  const string PI  = "3.14159265358979323846";
  int n; cin >> n;
  double truncar = stod(PI.substr(n + 1, 1) + "." + PI.substr(n + 2, 1));
  int truncado = (int) ((double) truncar + 0.5);
  cout << PI.substr(0, n + 1) << truncado;
  return 0;
}