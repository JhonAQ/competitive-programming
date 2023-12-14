#include<bits/stdc++.h>

using namespace std;

int main(){
  int c;
  scanf("%d", &c);
  int rpta = sqrt(c), i = rpta;

  while(i){
    int j = sqrt(c - i * i);
    rpta = min(rpta, abs(i*i + j*j - c));
    j++;
    rpta = min(rpta, abs(i*i + j*j - c));
    i--;
  }
  cout << rpta<<endl;
}

