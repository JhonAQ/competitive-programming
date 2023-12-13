#include<bits/stdc++.h>

using namespace std;

int main(){
  int tc;
  int limit;
  scanf("%d %d", &tc, &limit);
  int rpta = 0;
  while(tc--){
    int p;
    scanf("%d", &p);

    p >= limit ? rpta++ : 0;
  }
  cout<<rpta;
}
