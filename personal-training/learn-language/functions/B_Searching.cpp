#include <bits/stdc++.h>
using namespace std;

int search(int arr[], int len, int x) {
  for (int i = 0; i < len; ++i) {
    if (x == arr[i]) return i;
  }
  return -1;
}

int main() {
  int tc;
  cin >> tc;
  int arr[tc];
  for (int i = 0; i < tc; i++) {
    cin >> arr[i];
  }
  int f;
  cin >> f;
  cout << search(arr, tc, f);
  return 0;
}