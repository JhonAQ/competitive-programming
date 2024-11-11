#include<bits/stdc++.h>

using namespace std;

int main(){
  string str; cin >> str;
  int tc; cin >> tc;
  while(tc--){
    int o; cin >> o;
    if(o == 1){
      reverse(str.begin(), str.end());
    }else{
      int n; cin >> n;
      char c; cin >> c;
      if(n == 1){
        str = c + str;
      }else{
        str = str + c;
      }
    }
  }
  cout << str << endl;
}
