#include<bits/stdc++.h>

using namespace std;

int main(){
  vector<int> nums;
  while(true){
    int c; cin >> c;
    nums.push_back(c);
    if(!c) break;
  }
  while(!nums.empty()){
    cout << nums.back();
    nums.pop_back();
    if(!nums.empty()) cout << "\n";
  }
}
