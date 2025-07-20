#include<bits/stdc++.h>

using namespace std;

int main(){
  int n; cin >> n;
  while(n--){
    int x; cin >>x;
    int digit = 9;
    while(x >0){
      digit = min(x%10, digit); x/=10;
    }
    cout << digit << endl;
  }
}
