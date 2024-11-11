#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cerr << #x << " = " << (x) << endl;
#define RAYA cerr << "=====================" << endl;

int main(){
  int tc; cin >> tc;
  int x; cin >>x;
  vector<int> ps(tc, 0);
  for(int i = 0; i < tc; i++){
    cin >> ps[i];
    if(i != 0){
      ps[i] += ps[i - 1];
    }
    //DBG(ps[i]);
  }
  //RAYA;
  /*
  int l = 0, r = tc - 1;
  int idxRes = -1;
  while(l <= r){
    int mid = (l + r) / 2;
    DBG(l);
    DBG(r);
    DBG(mid);
    DBG(ps[mid]);
    if(ps[mid] == x){
      idxRes =  mid;
      r = mid - 1;
    }else if(ps[mid] > x){
      r = mid - 1;
    }else{
      l = mid + 1;
    }
    RAYA;
  }
  if(idxRes == -1){
    cout<< 0 << endl; 
    return 0;
  }
  cout << tc - idxRes << endl;
  */
  int ans = 1;
  for(int i = 0; i < ps.size(); i++){
    if(ps[i] > x){
      break;
    }else{
      ans++;
    }
  }
  cout << ans << endl;
}
