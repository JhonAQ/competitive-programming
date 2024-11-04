#include<bits/stdc++.h>

using namespace std;

int main(){
  string s; cin >>s;
  string solve;
  for(int i = 0; i < s.size(); i++){
    if(solve.size() == 0 || solve.back() != s[i])
      solve.push_back(s[i]);
    else
      solve.pop_back();
  }
  cout << solve << endl;
}
