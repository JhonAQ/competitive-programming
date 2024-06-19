#include <bits/stdc++.h>
using namespace std;

long long summation(long long arr[], int len){
  long long sum = 0;
  for(int i = 0; i < len; i++){
    sum += arr[i];
  }
  return sum;
}

int main() {
  int x; 
  cin >> x;
  long long arr[x];
  while(x--){
    cin >> arr[x];
  }
  int len = sizeof(arr) / sizeof(arr[0]);
  cout << abs(summation(arr, len));
  return 0;
}