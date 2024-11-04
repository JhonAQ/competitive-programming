#include<bits/stdc++.h>

using namespace std;

string deletePairs(string s){
  string ans = "";
  for(int i = 0; i < s.length() - 1; i++){
    if(s[i] == s[i + 1]) {
      i +=2;
      continue;
    }
    ans += s.substr(i, 1);
  }
  return ans;
}


int main(){
  string s;
  cin >> s;
  for(int i = 0; i < s.length() / 2; i++){
    s = deletePairs(s);
  }
  cout << s << endl;
}
