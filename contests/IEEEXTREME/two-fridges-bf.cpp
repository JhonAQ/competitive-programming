#include<bits/stdc++.h>

using namespace std;

bool isIn(pair<int, int> lim, int c){
  return lim.first <= c && c <= lim.second;
}

bool isInAll(vector<pair<int, int>> ob, int a){
  for(auto p : ob){
    if(!isIn(p, a)) return false;
  }
  return true;
}

int main(){
    int n; cin >> n;
    vector<pair<int, int>> ob(n);

    for(int i = 0; i < n; i++){
      int a, b; cin >> a >> b;
      ob[i] = {a, b};
      /*cout << ob[i].first << " " << ob[i].second << endl;*/
    }

    for(int t1 = -100; t1 <= 100; t1++){
      for(int t2 = t1; t2 <= 100; t2++){
        bool possible = true;
        for(auto p : ob){
          if(!isIn(p, t1) && !isIn(p, t2)){
            possible = false;
          }
        }
        if(possible){
          cout  << t1 << " " << t2 << endl;
          return 0;
        }
      }
    }
    cout << -1 << endl;

}
