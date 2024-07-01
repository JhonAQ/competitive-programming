#include<iostream>

using namespace std;

int main(){
  int x;
  cin >> x;
  string result = "YES";
  for(int i = 2; i < x; i++){
    if(x % i == 0)
      result = "NO";
  }
  cout << result << endl;
}
