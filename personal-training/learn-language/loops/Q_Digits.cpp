#include <bits/stdc++.h>
using namespace std;

int main() {
  int tc;
  cin >> tc;
  while(tc--){
    string number;
    cin >> number;
    for(int i = number.size() - 1; i >= 0; --i){
      cout << number[i] << " ";
    }
    cout << endl;
  }
  return 0;
}