#include<bits/stdc++.h>

using namespace std;

int main(){
  int tc; cin >> tc;
  while(tc--){
    unsigned int b; cin >> b;
    unsigned int a = 0;
    for(int i = 0; i < log(b) + 1; i++){
      if(a&b && a^b) break;
      if((1<<i)&b){
        if(!(a&b)){
        a |= 1<<i;
        }else if(!(a^b)){
          a = a & ~(1 << i);
        }
      }else{
        if(!(a^b)){
          a = a | (1 << i);
        }else {
          a = a << 1;
        }
      }
    }
    cout << a <<endl;
  }
}