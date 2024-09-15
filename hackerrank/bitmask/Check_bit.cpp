#include<bits/stdc++.h>

using namespace std;

int main(){
  int n, k;
  scanf("%d %d", &n, &k);
  cout << ((n & (1<<k)) ? "true" : "false");
}