#include<bits/stdc++.h>

using namespace std;

int main(){
  int c;
  scanf("%d", &c);
  int rpta = sqrt(c), i = rpta;

  while(i){
    for (int j = 0; j <= i; j++) {
      int xy = abs((i * i + j * j) - c);
      if(xy < rpta) rpta = xy;
    }
    i--;
  }
  cout << rpta<<endl;
}

