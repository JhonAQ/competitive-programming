#include<bits/stdc++.h>

using namespace std;

int main(){
  int tc, n, st, rpta;
  scanf("%d", &tc);
  for(int i = 1; i <= tc; i++){
    cin >> n;
    n--;
    cin >> rpta;
    while(n--){
      cin >> st;
      rpta = max(st, rpta);
    }
    printf("Case %d: %d\n", i, rpta);
  }
}