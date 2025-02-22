#include<bits/stdc++.h>

using namespace std;

int k;
string str;

bool f(int n){
  //cout << "hola jxd" << endl;
  bool isPossible = false;
  for(int i = 0; i < str.length() - n && !isPossible; i++){
    //cout << "bucle: " << i << endl;
    bool la = true;
    int bn = 1;
    int lk = k;
    int idx = i + 1;
    // agregar verrificador de limite para no salirse
    while(bn!=n && la && idx < str.length()){
      if(str.at(idx) != str.at(i)){
        if(lk != 0) {
          lk--;
        } else{
          //cout << i << " " << idx << " " << lk << " bn: " << bn << endl;
          la = false;
        }
      }
      else{
        bn++;
      }
      idx++;
    }
    if(bn == n){
      la = true;
    } else{
      la = false;
    }
    isPossible = la || isPossible;
    //cout << str.at(i) << endl;
    //cout << la << endl;
  }
  return isPossible;
}

int main(){
  cin >> str;
  cin >> k;

  int l = 1, r = str.length(), ans = 1;
  while(l <= r){
  //while(false){
    int mid = (l + r) / 2;
    //cout << l << " " << mid << " " << r << endl;
    if(f(mid)){
      l = mid + 1;
      ans = mid;
    }else{
      r = mid - 1;
    }
  }
  cout  << ans;
}
