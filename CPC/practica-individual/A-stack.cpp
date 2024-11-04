#include<bits/stdc++.h>

using namespace std;

int main(){
  string str;
  getline(cin, str);
  int num = 0;
  stack<int> s;
  for(int i = 0; i < str.size(); i++){
    if(str[i] == ' ' ){
      if(num != 0){
        s.push(num);
        num = 0;
      }
      continue;
    }

    if('0' <= str[i] && str[i] <= '9'){
      num *= 10;
      num += str[i] - '0';
    }else{
      int a = s.top(); s.pop();
      int b = s.top(); s.pop();
      if(str[i] == '+'){
        s.push(a+b);
      }else if(str[i] == '*'){
        s.push(a*b);
      }else{
        s.push(b-a);
      }
    }
  }
  cout << s.top() << '\n';
}
