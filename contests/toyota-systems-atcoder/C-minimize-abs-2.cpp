#include<bits/stdc++.h>

using namespace std;

int main(){
  long c;
  scanf("%ld", &c);
  long rpta = sqrt(c), i = rpta;

  while(i){
    long j = sqrt(c - i * i);
    rpta = min(rpta, abs(i*i + j*j - c));
    j++;
    rpta = min(rpta, abs(i*i + j*j - c));
    i--;
  }
  cout << rpta<<endl;
}

