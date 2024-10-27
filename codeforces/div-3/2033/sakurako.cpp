#include <bits/stdc++.h>
using namespace std;
int main(){
  int t; cin>>t;
  while(t--){
    int n;cin>>n;
    int i = 0;
    while(true){

      if(i * pow(-1, i) > n){
        cout << "Kosuke" << endl;
        break;
      }
      if(i * pow(-1, i) < -n){
        cout << "Sakurako" << endl;
        break;
      }


      i++;
    }

  }

  return 0;
}
