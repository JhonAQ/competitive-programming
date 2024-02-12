#include<bits/stdc++.h>

using namespace std;

bool distinctDigits(int n){
  bool digitos[10] = {false};
  while (n > 0) {
    int digito = n % 10;
    if (digitos[digito]) {
      return false;
    }
    digitos[digito] = true;
    n /= 10;
  }
  return true;
}

int main(){
  int li, ls;
  scanf("%d %d", &li, &ls);
  for (int i = li; i <= ls; i++) {
    if (distinctDigits(i)) {
      cout << i;
      return 0;
    }
  }
  cout << "-1";
}
