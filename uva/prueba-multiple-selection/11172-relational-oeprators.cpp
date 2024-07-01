#include<bits/stdc++.h>

using namespace std;

int main(){
  int x, y, z;
  cin >> x;
  while(x--){
    cin >> y >> z;
    if(y < z)
      cout << "<";
    else if (y > z)
      cout << ">";
    else
      cout << "=";
    cout << endl;
  }
}