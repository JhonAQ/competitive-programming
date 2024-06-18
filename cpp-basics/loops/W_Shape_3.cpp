#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n - i - 1; j++) cout << " ";
    for(int k = 0; k < i * 2 + 1; k++) cout << "*";
    cout << endl;
  }
  for(int i = 0; i < n; i++){
    for(int k = 0; k < i; k++) cout << " ";
    for(int j = 0; j < (n - i) * 2 - 1; j++) cout << "*";
    cout << endl;
  }
  return 0;
}