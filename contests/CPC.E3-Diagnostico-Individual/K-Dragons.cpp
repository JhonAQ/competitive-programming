#include<bits/stdc++.h>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
  return a.first <= b.first;
}

int main(){
  int s, n;
  cin >> s >> n; 
  vector<pair<int, int>> dragon(n, {0, 0});

  for(auto &par : dragon){
    cin >> par.first >> par.second;
  }
  sort(dragon.begin(), dragon.end(), comp);
  for(auto par : dragon){
    if(s <= par.first){
      cout << "NO";
      return 0;
    }
    s += par.second;
  }
  cout << "YES";
  return 0;
}
