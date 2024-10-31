// Concepto importante: BINARY SEARCH ON THE ANSWER
// Busca la relación entre las soluciones, entre turango de soluciones posibles
// Aprovecha la información que te da una de ellas para buscar la más óptima con bs
#include<bits/stdc++.h>

using namespace std;
string s;
int k;

bool f(int n){
  int cntA = 0, cntB = 0;
  for(int i = 0; i < n; i++){
    if(s[i] == 'a') cntA++;
    else cntB++;
  }
  if(min(cntA, cntB) <=k) return true;
  int size  = s.size();
  for(int i = n; i < size; i++){
    if(s[i -n] == 'a') cntA--;
    if(s[i -n] == 'b') cntB--;
    if(s[i] == 'a') cntA++;
    if(s[i] == 'b') cntB++;

    if(min(cntA, cntB) <=k)
      return true;
  }
  return false;
}

int main(){
  int n; cin >> n >> k;
  cin >> s;

  int l = 1, r = n, res = -1;
  while(l <= r){
    int mid = (l + r) / 2;
    if(f(mid)){
      l = mid + 1;
      res = mid;
    } else {
      r = mid - 1;
    }
  }
//  cout << "l " << (l==r ? "si es igual a" : "no es igual a") << "r\n";
//  cout << f(l -1) << " " << f(l) << " " << f(l+1);
  cout << res << endl;
}
