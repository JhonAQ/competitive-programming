#include<bits/stdc++.h>

using namespace std;

vector<string> keys;

string solve(int extraxd, int idx) {
  char letter = 'a' + idx;
  return string(extraxd + 1, letter);
}

int cuantasTecleadas(string str, int k) {
  for(int i = 0; i < str.size(); i++) {
    if (str[i] - 'a' != k) return i;
  }
  return -1;
}

int main(){
  int n, e; cin >> n >> e;
  vector<int> minimum(e, 0);
  for(int i = 0; i < n; i++){
    string sequence; cin >> sequence;
    keys.push_back(sequence);
  }
  for(int i = 0; i < e; i++){
    //para cada secuencia de keys: adicionar a minimun el minimo de tecleadas por letra del alfabeto
    for(int j = 0; j < n; j++){
      char target = 'a' + i;
      int min = cuantasTecleadas(keys[j], i);
      //perdonen el or xd, mi pipe en el teclado volo
      if(min == -1 or minimum[i] == -1){
        minimum[i] = -1;
        continue;
      } else{
        minimum[i] += min;
      }
    }
  }

  int extraxd = -1;
  int idx = -1;

  for(int i = 0; i < e; i++) {
    if(minimum[i] == -1) continue;
    if(extraxd == -1 || minimum[i] < extraxd) {
      extraxd = minimum[i];
      idx = i;
    }
  }

  if(extraxd == -1){
    cout << "NO";
  } else{
    cout << solve(extraxd, idx);
  }
  cout << '\n';
}
