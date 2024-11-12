#include<bits/stdc++.h>

using namespace std;

int main(){
  string str; cin >> str;
  int tc; cin >> tc;
  int rev = 0;
  while(tc--){
    int o; cin >> o;
    if(o == 1){
      rev++;
    }else{
      int n; cin >> n;
      char c; cin >> c;
      if(n == 1 || (rev & 1)){
        str = c + str;
      }else{
        str = str + c;
      }
    }
  }
  if(rev & 1) reverse(str.begin(), str.end());
  cout << str << endl;
}
