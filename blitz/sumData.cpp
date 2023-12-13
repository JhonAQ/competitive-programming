#include <bits/stdc++.h>

using namespace std;

int main(){
  int tc;
  while (scanf("%d", &tc) != EOF) {
    int suma = 0;
    for (int i = 0; i < tc; i++) {
      int actual;
      scanf("%d", &actual);
      suma += actual;
    }
    printf("%d\n", suma);
  }
}
