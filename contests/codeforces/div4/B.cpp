#include<bits/stdc++.h>

using namespace std; 

int main(){
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    vector<int> ans;
    for(int i = 0; i < n; i++){
      string str; cin >> str;
      for(int j = 0; j < str.size(); j++){
        if(str[j] == '#'){
          ans.emplace_back(j + 1);
        }
      }
    }
    reverse(ans.begin(), ans.end());
    for(auto it = ans.begin(); it != ans.end(); it++){
      cout << *it  << " ";
    }
    cout << endl;
  }
}
