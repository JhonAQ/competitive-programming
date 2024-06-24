#include <bits/stdc++.h>
using namespace std;

int counter = 0;

void sumUntil1(string num){
  if(num.size() == 1) return;
  long long sum = 0;
  for(long long j= 0; j < num.size(); j++){
    sum += num[j] - '0';
  }
  counter++;
  sumUntil1(to_string(sum));
}

int main() {
  string num;
  cin >> num;
  sumUntil1(num);
  cout << counter;
  return 0;
}