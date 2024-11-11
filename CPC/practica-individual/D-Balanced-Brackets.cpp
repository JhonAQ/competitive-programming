#include<bits/stdc++.h>

using namespace std;

bool isOpen(char a){
  //cout << "Checking if " << a << " is Open\n";
  bool ans =  a == '(' || a == '{' || a == '[';
  //cout << "res: " << ans << endl;
  return ans;
}

int main(){
  int tc; cin >> tc;
  while(tc--){
    string str; cin >> str;
    bool ans = true;
    int len = str.size();
    stack<char> s;

    for(int i = 0; i < len; i++){
      char a = str.at(i);
      if(isOpen(a)){
        s.push(a);
        //cout << "Pusheado isOpen push: " << a << endl;
      }else{
        if((s.empty() || a - s.top() != 2 && a - s.top() != 1)){
          ans = false;
          //cout << "Is not open and does not match, break: " << a << endl;
          //cout << "Aqui estan las que fallan: " << a << " and stack: " << s.top() << endl;
          break;
        }else{
          //cout << "Matches!, pop and next, break: " << a << endl;
          s.pop();
        }
      }
    }
    if(!s.empty()) ans = false;
    cout << (ans ? "YES\n" : "NO\n");
  }

}
