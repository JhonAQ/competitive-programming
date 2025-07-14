#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  string str;
  do{
    cin >> str;
    if(str == "WIN" || str == "LOSE") break;
    int a, b; cin >> a >> b;
    if(b <= (a/6.0)){
      cout << "PLAY" << endl;
    }else{
      cout << "SKIP" << endl;
    }

  }while(str != "WIN" && str != "LOSE");
  return 0;
}
