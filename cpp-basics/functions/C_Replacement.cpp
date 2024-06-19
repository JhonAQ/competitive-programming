#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; 
  cin >> n;
  int arr[n];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
    if(arr[i] == 0) continue;
    arr[i] = (arr[i] > 0 ? 1: 2);
  }
  for(int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }
  return 0;
}