#include<bits/stdc++.h>

using namespace std;
int findMinimize(int x, int l, int r);

int main(){
  int tc, l, r;
  scanf("%d %d %d", &tc, &l, &r);
  while (tc--) {
    int a; 
    scanf("%d", &a);
    cout <<findMinimize(a, l, r) <<" ";
  }
}

int findMinimize(int x, int l, int r){
  if(x < l)
    return l;
  if(x > r)
    return r;
  return x;
}
