#include <iostream>
#include <cstring> // Para usar funciones como strlen, strcpy, etc.
using namespace std;

int main() {
  string a, b; cin >> a >> b;
  string win = (a.size() < b.size()) ? a : b;
  int j = 0;
  while(a[j] && b[j]){
    if(b.at(j) < a.at(j)){
      win = b;
      break;
    } else if(a.at(j) < b.at(j)){
      win = a;
      break;
    }
    j++;
  }
  cout << win;
}
